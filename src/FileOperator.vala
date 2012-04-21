/*-
 * Copyright (c) 2011-2012       Scott Ringwelski <sgringwe@mtu.edu>
 *
 * Originally Written by Scott Ringwelski for BeatBox Music Player
 * BeatBox Music Player: http://www.launchpad.net/beat-box
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

using TagLib;
using GLib;
using Gee;

public class BeatBox.FileOperator : Object {
	private BeatBox.LibraryManager lm;
	private BeatBox.Settings settings;
	public GStreamerTagger tagger;
	
	bool inThread;
	LinkedList<Media> toSave;
	
	public int index;
	public int item_count;
	public signal void fo_progress(string? message, double progress);
	public signal void import_cancelled();
	public signal void rescan_cancelled();
	
	public bool cancelled; // set to true if user cancels
	bool cancelSent; // needed to not send cancel signal twice (in recursive function)
	
	ImportType import_type;
	Playlist new_playlist;
	LinkedList<Media> new_imports;
	LinkedList<Media> all_new_imports;
	LinkedList<string> import_errors;
	private string[] other_names_list = {};
	private LinkedList<string>[] other_paths_list;
	private int other_playlists_added = 0;
	
	HashMap<string, string> art_locations = new HashMap<string, string>();
	
	public enum ImportType  {
		SET,
		RESCAN,
		PLAYLIST,
		IMPORT
	}
	
	public FileOperator(BeatBox.LibraryManager lmm, BeatBox.Settings sett) {
		lm = lmm;
		settings = sett;
		inThread = false;
		toSave = new LinkedList<Media>();
		cancelled = false;
		cancelSent = false;
		new_imports = new LinkedList<Media>();
		import_errors = new LinkedList<string>();
		tagger = new GStreamerTagger(lm);
		
		tagger.media_imported.connect(media_imported);
		tagger.import_error.connect(import_error);
		tagger.queue_finished.connect(queue_finished);
		lm.progress_cancel_clicked.connect( () => { 
			cancelled = true;
			tagger.cancel_operations();
		} );

		/* Create album-art cache dir */
		var beatbox_cache_dir = GLib.File.new_for_path(settings.get_cache_dir ());
		var album_art_folder = GLib.File.new_for_path(settings.get_album_art_cache_dir ());
		if(!album_art_folder.query_exists()) {
			try {
				beatbox_cache_dir.make_directory(null);
				album_art_folder.make_directory(null);
			}
			catch(GLib.Error err) {
				warning ("Could not create folder in cache directory: %s\n", err.message);
			}
		}	
	}
	
	public void resetProgress(int items) {
		index = 0;
		item_count = items;
		cancelled = false;
		cancelSent = false;
	}
	
	private static bool is_valid_file_type(string type) {
		var typeDown = type.down();
		
		return (typeDown.has_suffix(".mp3") || typeDown.has_suffix(".m4a") || 
				typeDown.has_suffix(".wma") || typeDown.has_suffix(".ogg") || 
				typeDown.has_suffix(".flac") || typeDown.has_suffix(".mp4") || 
				typeDown.has_suffix(".oga") || typeDown.has_suffix(".m4p") ||
				typeDown.has_suffix(".aac") || typeDown.has_suffix(".alac"));
	}
	
	private static bool is_valid_image_type(string type) {
		var typeDown = type.down();
		
		return (typeDown.has_suffix(".jpg") || typeDown.has_suffix(".jpeg") ||
				typeDown.has_suffix(".png"));
	}
	
	public int count_music_files(GLib.File music_folder, ref LinkedList<string> files) {
		GLib.FileInfo file_info = null;
		
		try {
			var enumerator = music_folder.enumerate_children(FILE_ATTRIBUTE_STANDARD_NAME + "," + FILE_ATTRIBUTE_STANDARD_TYPE, 0);
			while ((file_info = enumerator.next_file ()) != null) {
				var file_path = music_folder.get_path() + "/" + file_info.get_name();
				
				if(file_info.get_file_type() == GLib.FileType.REGULAR && is_valid_file_type(file_info.get_name())) {
					index++;
					files.add(file_path);
				}
				else if(file_info.get_file_type() == GLib.FileType.DIRECTORY) {
					count_music_files(GLib.File.new_for_path(file_path), ref files);
				}
			}
		}
		catch(GLib.Error err) {
			warning("Could not pre-scan music folder. Progress percentage may be off: %s\n", err.message);
		}
        
        return index;
	}
	
	public string get_best_album_art_file(Media m) {
		GLib.File media_file = GLib.File.new_for_uri(m.uri);
		
		if(!media_file.query_exists())
			return "";
		
		string artPath = "";
		GLib.FileInfo file_info = null;
		var album_folder = media_file.get_parent();
		
		if( (artPath = art_locations.get(album_folder.get_path())) != null)
			return artPath;
			
		artPath = "";
		
		/* get a list of all images in folder as potential album art choices */
		var image_list = new LinkedList<string>();

		try {
			var enumerator = album_folder.enumerate_children(FILE_ATTRIBUTE_STANDARD_NAME + "," + FILE_ATTRIBUTE_STANDARD_TYPE, 0);
			while ((file_info = enumerator.next_file ()) != null) {
				if(file_info.get_file_type() == GLib.FileType.REGULAR && is_valid_image_type(file_info.get_name())) {
					image_list.add(file_info.get_name());
				}
			}
        }
        catch (Error e) {
            warning ("Error while looking for covers: %s", e.message);
        }
		
		/* now choose one based on priorities */
		foreach(string sU in image_list) {
			var sD = sU.down();
			if(sD.contains("folder.")) {
				artPath = album_folder.get_path() + "/" + sU;
				break;
			}
			else if(sD.contains("cover."))
				artPath = album_folder.get_path() + "/" + sU;
			else if(!artPath.contains("cover.") && sD.contains("album."))
				artPath = album_folder.get_path() + "/" + sU;
			else if(artPath == "")
				artPath = album_folder.get_path() + "/" + sU;
		}
		
		art_locations.set(album_folder.get_path(), artPath);
		return artPath;
	}
	
	public void save_album(Media s, string uri) {
		if(uri == null || uri == "") {
			return;
		}
		
		GLib.File file = GLib.File.new_for_uri(uri);
		if(file == null) {
			return;
		}
		
		FileInputStream filestream;
		
		try {
			Gdk.Pixbuf rv;
			filestream = file.read(null);
			rv = new Gdk.Pixbuf.from_stream(filestream, null);
			var dest = Path.build_path("/", GLib.File.new_for_uri(s.uri).get_parent().get_path(), "Album.jpg");
			rv.save(dest, "jpeg");
			
			Gee.LinkedList<Media> updated_medias = new Gee.LinkedList<Media>();
			foreach(int i in lm.media_ids()) {
				if(lm.media_from_id(i).artist == s.artist && lm.media_from_id(i).album == s.album) { 
					debug("setting album art for %s by %s\n", lm.media_from_id(i).title, lm.media_from_id(i).artist);
					lm.media_from_id(i).setAlbumArtPath(dest);
					updated_medias.add(lm.media_from_id(i));
				}
			}
			
			lm.update_medias(updated_medias, false, false);
			
			// for sound menu (dbus doesn't like linked lists)
			if(updated_medias.contains(lm.media_info.media))
				lm.update_media(lm.media_info.media, false, false);
		}
		catch(GLib.Error err) {
			debug("Could not save album to file: %s\n", err.message);
		}
	}
	
	public void save_album_art_in_cache (string key, Gdk.Pixbuf? pixbuf) {
		if (key == "" || pixbuf == null)
			return;

		string uri = get_cached_album_art_path (key);

		debug ("Saving cached album-art for %s", key);

		try {
			pixbuf.save (uri, "jpeg");
		} catch (Error err) {
			warning (err.message);
		}
	}

	public Gdk.Pixbuf? get_cached_album_art (string key, out string uri) {
		Gdk.Pixbuf? rv = null;
		uri = get_cached_album_art_path (key);

		try {
			rv = new Gdk.Pixbuf.from_file (uri);
		} catch (Error err) {
			//debug (err.message);
		}

		if (rv == null)
			uri = "";

		debug ("Requested cached album-art for %s: %s", key, rv != null ? " FOUND." : " NOT FOUND.");

		return rv;
	}

	public string get_cached_album_art_path (string key) {
		return GLib.Path.build_filename (settings.get_album_art_cache_dir (), key + ".jpg");
	}

	public Gdk.Pixbuf? save_artist_image(Media s, string uri) {
		Gdk.Pixbuf rv;
		
		if(uri == null || uri == "") {
			return null;
		}
		
		GLib.File file = GLib.File.new_for_uri(uri);
		FileInputStream filestream;
		
		try {
			filestream = file.read(null);
			rv = new Gdk.Pixbuf.from_stream(filestream, null);
			rv.save(Path.build_path("/", GLib.File.new_for_uri(s.uri).get_parent().get_parent().get_path(), "Artist.jpg"), "jpeg");
		}
		catch(GLib.Error err) {
			rv = null;
		}
		
		return rv;
	}
	
	public void save_medias(Collection<Media> to_save) {
		foreach(Media s in to_save) {
			if(!(toSave.contains(s)) && !s.isTemporary && !s.isPreview && GLib.File.new_for_uri(s.uri).get_path().has_prefix(settings.getMusicFolder()))
				toSave.offer(s);
		}
		
		if(!inThread) {
			try {
				inThread = true;
				Thread.create<void*>(save_media_thread, false);
			}
			catch(GLib.Error err) {
				warning ("Could not create thread to rescan music folder: %s\n", err.message);
			}
		}
	}
        
	public void* save_media_thread () {
		while(true) {
			Media s = toSave.poll();
			
			if(s == null) {
				inThread = false;
				return null;
			}
			
			if(settings.getWriteMetadataToFile()) {
				TagLib.File tag_file;
				tag_file = new TagLib.File(GLib.File.new_for_uri(s.uri).get_path());
				
				if(tag_file != null && tag_file.tag != null && tag_file.audioproperties != null) {
					try {
						tag_file.tag.title = s.title;
						tag_file.tag.artist = s.artist;
						tag_file.tag.album = s.album;
						tag_file.tag.genre = s.genre;
						tag_file.tag.comment = s.comment;
						tag_file.tag.year = s.year;
						tag_file.tag.track  = s.track;
						
						tag_file.save();
					}
					finally {
						
					}
				}
				else {
					debug ("Could not save %s.\n", s.uri);
				}
			}
			
			if(settings.getUpdateFolderHierarchy())
				update_file_hierarchy(s, true, false);
		}
	}
	
	public GLib.File? get_new_destination(Media s) {
		GLib.File dest;
		
		try {
			/* initialize file objects */
			GLib.File original = GLib.File.new_for_uri(s.uri);
			
			var ext = "";
			if(s.uri.has_prefix("cdda://"))
				ext = ".mp3";
			else
				ext = get_extension(s.uri);
			
			dest = GLib.File.new_for_path(Path.build_path("/", settings.getMusicFolder(), s.artist.replace("/", "_"), s.album.replace("/", "_"), s.track.to_string() + " " + s.title.replace("/", "_") + ext));
			
			if(original.get_path() == dest.get_path()) {
				debug("File is already in correct location\n");
				return null;
			}
			
			string extra = "";
			while((dest = GLib.File.new_for_path(Path.build_path("/", settings.getMusicFolder(), s.artist.replace("/", "_"), s.album.replace("/", "_"), s.track.to_string() + " " + s.title.replace("/", "_") + extra + ext))).query_exists()) {
				extra += "_";
			}
			
			/* make sure that the parent folders exist */
			if(!dest.get_parent().query_exists())
				dest.get_parent().make_directory_with_parents(null);
		}
		catch(GLib.Error err) {
			debug("Could not find new destination!: %s\n", err.message);
		}
		
		return dest;
	}
	
	public void update_file_hierarchy(Media s, bool delete_old, bool emit_update) {
		try {
			GLib.File dest = get_new_destination(s);
			if(dest == null)
				return;
			
			GLib.File original = GLib.File.new_for_uri(s.uri);
			
			/* copy the file over */
			bool success = false;
			if(!delete_old) {
				debug("Copying %s to %s\n", s.uri, dest.get_uri());
				success = original.copy(dest, FileCopyFlags.NONE, null, null);
			}
			else {
				debug("Moving %s to %s\n", s.uri, dest.get_uri());
				success = original.move(dest, FileCopyFlags.NONE, null, null);
			}
			
			if(success) {
				debug("success copying file\n");
				s.uri = dest.get_uri();
				
				// wait to update media when out of thread
				if(emit_update) {
					Idle.add( () => {
						lm.update_media(s, false, false); return false;
					});
				}
				
				if(original.get_uri().has_prefix("file://") && original.get_parent().get_path() != null &&
				s.getAlbumArtPath().contains(original.get_parent().get_path())) {
					var mediaFile = GLib.File.new_for_path(s.getAlbumArtPath());
					var albumArtDest = Path.build_path("/", dest.get_parent().get_path(), "Album.jpg");
					
					if(!GLib.File.new_for_path(albumArtDest).query_exists() && mediaFile.query_exists() &&
					mediaFile.copy(GLib.File.new_for_path(albumArtDest), FileCopyFlags.NONE, null, null)) {
						debug("Copying album art to %s\n", albumArtDest);
						s.setAlbumArtPath(albumArtDest);
					}
				}
			}
			else // FIXME: use warning() here?
				debug("Failure: Could not copy imported media %s to media folder %s\n", s.uri, dest.get_path());
			
			/* if we are supposed to delete the old, make sure there are no items left in folder if we do */
			if(delete_old) {
				var dummy = new LinkedList<string>();
				var old_folder_items = count_music_files(original.get_parent(), ref dummy);
				// must check for .jpg's as well.
				
				if(old_folder_items == 0) {
					debug("going to delete %s because no files are in it\n", original.get_parent().get_path());
					original.get_parent().delete();
				}
			}
		}
		catch(GLib.Error err) {
			warning("Could not copy imported media %s to media folder: %s\n", s.uri, err.message);
		}
	}
	
	public void remove_medias(Collection<string> toRemove) {
		var dummy_list = new LinkedList<string>();
		foreach(string s in toRemove) {
			try {
				var file = GLib.File.new_for_uri(s);
				file.trash();
				
				var old_folder_items = count_music_files(file.get_parent(), ref dummy_list);
					
				//TODO: COPY ALBUM AND IMAGE ARTWORK
				if(old_folder_items == 0) {
					debug("going to delete %s because no files are in it\n", file.get_parent().get_path());
					//original.get_parent().delete();
					
					var old_folder_parent_items = count_music_files(file.get_parent().get_parent(), ref dummy_list);
					
					if(old_folder_parent_items == 0) {
						debug("going to delete %s because no files are in it\n", file.get_parent().get_parent().get_path());
					}
				}
			}
			catch(GLib.Error err) {
				warning("Could not move file %s to trash: %s (you could be using a file system which is not supported)\n", s, err.message);
				
				//tell the user the file could not be moved and ask if they'd like to delete permanently instead.
				//Gtk.MessageDialog md = new Gtk.MessageDialog(lm.lw, Gtk.DialogFlags.MODAL, Gtk.MessageType.QUESTION, Gtk.ButtonsType.YES_NO, "Could not trash file %s, would you like to permanently delete it? You cannot undo these changes.", s);
			}
		}
	}
	
	/*public static void guess_content_type(GLib.File root, ref int audio, ref int other) {
		GLib.FileInfo file_info = null;
		
		try {
			var enumerator = root.enumerate_children(FILE_ATTRIBUTE_STANDARD_NAME + "," + FILE_ATTRIBUTE_STANDARD_TYPE, 0);
			while ((file_info = enumerator.next_file ()) != null) {
				var file_path = root.get_path() + "/" + file_info.get_name();
				
				if(file_info.get_file_type() == GLib.FileType.REGULAR && is_valid_file_type(file_info.get_name())) {
					++audio;
				}
				else if(file_info.get_file_type() == GLib.FileType.REGULAR) {
					++other;
				}
				else if(file_info.get_file_type() == GLib.FileType.DIRECTORY)
					guess_content_type(GLib.File.new_for_path(file_path), ref audio, ref other);
			}
		}
		catch(GLib.Error err) {
			message("Could not guess content types: %s\n", err.message);
		}
	}*/
	
	public string get_extension(string name) {
		return name.slice(name.last_index_of(".", 0), name.length);
	}
	
	/* should be called from thread */
	public void import_from_playlist_file_info(string[] names, LinkedList<string>[] paths) {
		new_playlist = new Playlist();
		if (names.length > 1) {
    		other_names_list = names[1:paths.length];
	    	other_paths_list = paths[1:paths.length];
		}
		var internals = new LinkedList<int>();
		var externals = new LinkedList<string>();
		
		lm.start_file_operations("Importing <b>" + names[0] + "</b> to Library...");
		
		foreach(string path in paths[0]) {
			Media s;
			if( (s = lm.media_from_file(path)) != null)
				internals.add(s.rowid);
			else
				externals.add(path);
		}
		
		new_playlist.name = names[0];
		new_playlist.addMedia(internals);
		
		resetProgress(externals.size - 1);
		Timeout.add(500, lm.doProgressNotificationWithTimeout);
		import_files(externals, ImportType.PLAYLIST);
	}
	
	public void import_files(LinkedList<string> files, ImportType type) {
		all_new_imports = new LinkedList<Media>();
		new_imports.clear();
		import_errors.clear();
		import_type = type;
		
		if(files.size == 0) {
			queue_finished();
		}
		else {
			tagger.discoverer_import_medias(files);
		}
	}
	
	void media_imported(Media m) {
		new_imports.add(m);
		all_new_imports.add(m);
		++index;
		
		// check if we should guess as a podcast
		if(m.genre.down().contains("podcast") || m.length > 9000) // OVER 9000!!!!! aka 15 minutes
			m.mediatype = 1;
		
		if(new_imports.size >= 200) {
			lm.add_medias(new_imports, true); // give user some feedback
			new_imports.clear();
		}
	}
	
	void import_error(string file) {
		++index;
		import_errors.add(file);
	}
	
	void queue_finished() {
		lm.add_medias(new_imports, true);
		new_imports.clear();
		
		if(import_type == ImportType.PLAYLIST) {
			var to_add = new LinkedList<int>();
			foreach(var s in all_new_imports)
				to_add.add (s.rowid);
			new_playlist.addMedia(to_add);
			
			string extra = "";
			while(lm.playlist_from_name(new_playlist.name + extra) != null)
				extra += "_";
			
			new_playlist.name = new_playlist.name + extra;
			lm.add_playlist(new_playlist);
			lm.lw.addSideListItem(new_playlist);
		}
		
		// if doing import and copy to music folder is enabled, do copy here
		if((import_type == ImportType.IMPORT || import_type == ImportType.PLAYLIST) && settings.getCopyImportedMusic()) {
			fo_progress("<b>Copying</b> files to <b>Music Folder</b>...", 0.0);
			
			try {
				Thread.create<void*>(copy_imports_thread, false);
			}
			catch(GLib.Error err) {
				warning("Could not create thread to rescan music folder: %s\n", err.message);
			}
		}
		else {
			lm.music_added(import_type == ImportType.RESCAN ? new LinkedList<string>() : import_errors);
			lm.finish_file_operations();
		}
		if (other_names_list.length > 0) {
		    import_from_playlist_file_info({other_names_list[other_playlists_added]}, {other_paths_list[other_playlists_added]});
		    other_playlists_added++;
		    if (other_playlists_added == other_names_list.length)
		        other_names_list = {};
		}
	}
	
	public void* copy_imports_thread() {
		resetProgress(all_new_imports.size);
		
		foreach(Media s in all_new_imports) {
			if(!cancelled) {
				//current_operation = "<b>Copying " + s.title + "</b> to <b>Music Folder</b>";
				update_file_hierarchy(s, false, false);
			}
			
			++index;
		}
		
		Idle.add( () => {
			lm.music_added(import_errors);
			lm.finish_file_operations();
			
			return false;
		});
		
		return null;
	}
}
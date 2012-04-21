/*-
 * Copyright (c) 2012 Lucas Baudin <xapantu@gmail.com>
 *
 * Originally Written by Lucas Baudin for BeatBox Music Player
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

using Gtk;
using Gee;

/* This file contains the default list model */

public abstract class BeatBox.BaseTreeModel : GLib.Object, TreeModel, TreeSortable {
	public bool is_current { get { return list_view.is_current_view; } }

	public BaseListView list_view;

	protected LinkedList<string> _columns;
	/* data storage variables */
	protected Sequence<int> rows;
	protected int stamp; // all iters must match this

	/* treesortable stuff */
	protected int sort_column_id;
	protected SortType sort_direction;
	protected unowned TreeIterCompareFunc default_sort_func;
	protected HashMap<int, CompareFuncHolder> column_sorts;
	protected bool removing_medias = false;
	
	/** Returns Type of column at index_ **/
	public Type get_column_type (int col) {
		string [] string_cols = { "Length", "Rating", "Episode", "Date", "Station", "Genre", "Title", "Artist", "Album"};
		if(_columns[col] == " ") {
			return typeof(GLib.Icon);
		}
		else if(col == 0 || _columns[col] in string_cols || col == 10) {
			return typeof(int);
		}
		else {
			return typeof(string);
		}
	}
	
	
	/** Sets iter to point to the first child of parent. **/
	public bool iter_children (out TreeIter iter, TreeIter? parent) {
	    iter = TreeIter ();
	    critical ("Function not implemented.");
		
		return false;
	}

	/** Returns true if iter has children, false otherwise. **/
	public bool iter_has_child (TreeIter iter) {
		
		return false;
	}

	/** Returns the number of children that iter has. **/
	public int iter_n_children (TreeIter? iter) {
		if(iter == null)
			return rows.get_length();
		
		return 0;
	}

	/** Sets iter to point to the node following it at the current level. **/
	public bool iter_next (ref TreeIter iter) {
		if(iter.stamp != this.stamp)
			return false;

		iter.user_data = ((SequenceIter)iter.user_data).next();

		if(((SequenceIter)iter.user_data).is_end())
			return false;

		return true;
	}

	/** Sets iter to be the child of parent, using the given index. **/
	public bool iter_nth_child (out TreeIter iter, TreeIter? parent, int n) {
	    iter = TreeIter ();
		if(n < 0 || n >= rows.get_length() || parent != null) {
		    critical ("Invalid child number %d", n);
			return false;
	    }
		
		iter.stamp = this.stamp;
		iter.user_data = rows.get_iter_at_pos(n);
		
		return true;
	}

	/** Fills in sort_column_id and order with the current sort column and the order. **/
	public bool get_sort_column_id(out int sort_column_id, out SortType order) {
		sort_column_id = this.sort_column_id;
		order = sort_direction;

		return true;
	}

	/** Returns true if the model has a default sort function. **/
	public bool has_default_sort_func() {
		return (default_sort_func != null);
	}

	/** Sets the default comparison function used when sorting to be sort_func. **/
	public void set_default_sort_func(owned TreeIterCompareFunc sort_func) {
		default_sort_func = sort_func;
	}
	
	public abstract int sequence_iter_compare_func (SequenceIter<int> a, SequenceIter<int> b);

	/** Sets the current sort column to be sort_column_id. **/
	public void set_sort_column_id(int sort_column_id, SortType order) {
		bool changed = (this.sort_column_id != sort_column_id || order != sort_direction);

		this.sort_column_id = sort_column_id;
		sort_direction = order;

		if(changed && sort_column_id >= 0) {
			/* do the sort for reals */
			rows.sort_iter(sequence_iter_compare_func);

			sort_column_changed();
		}
	}

	public void resort() {
		rows.sort_iter(sequence_iter_compare_func);
		sort_column_changed();
	}

	/** Sets the comparison function used when sorting to be sort_func. **/
	public void set_sort_func(int sort_column_id, owned TreeIterCompareFunc sort_func) {
		column_sorts.set(sort_column_id, new CompareFuncHolder(sort_func));
	}
	
	/** Lets the tree ref the node. **/
	public void ref_node (TreeIter iter) {}

	/** Lets the tree unref the node. **/
	public void unref_node (TreeIter iter) {}

	/** Sets iter to be the parent of child. **/
	public bool iter_parent (out TreeIter iter, TreeIter child) {
	    iter = TreeIter ();
	    critical ("Function not allowed on list-only view");
		
		return false;
	}
	
	public abstract void get_value_impl (TreeIter iter, int column, out Value val);
	
	public void get_value (TreeIter iter, int column, out Value val) {
	    get_value_impl (iter, column, out val);
	}

	/** Returns a set of flags supported by this interface **/
	public TreeModelFlags get_flags () {
		return TreeModelFlags.LIST_ONLY;
	}

	/** Returns a newly-created Gtk.TreePath referenced by iter. **/
	public TreePath? get_path (TreeIter iter) {
		return new TreePath.from_string(((SequenceIter)iter.user_data).get_position().to_string());
	}

	/** Returns the number of columns supported by tree_model. **/
	public int get_n_columns () {
		return _columns.size;
	}

	/** Sets iter to a valid iterator pointing to path **/
	public bool get_iter (out TreeIter iter, TreePath path) {
		iter = TreeIter();
		int path_index = path.get_indices()[0];
		
		if(rows.get_length() == 0 || path_index < 0 || path_index >= rows.get_length())
			return false;
		
	    var seq_iter = rows.get_iter_at_pos(path_index);
	    if(seq_iter == null)
			    return false;
	
		iter.stamp = this.stamp;
		iter.user_data = seq_iter;
	
		return true;
	}
	
	
	/** convenience method to insert media into the model. No iters returned. **/
	public void append_medias(Collection<int> medias, bool emit) {
		foreach(int id in medias) {
			SequenceIter<int> added = rows.append(id);
			
			if(emit) {
				TreePath path = new TreePath.from_string(added.get_position().to_string());
			
				TreeIter iter = TreeIter();
				iter.stamp = this.stamp;
				iter.user_data = added;
				
				row_inserted(path, iter);
			}
		}
	}
	
	public void turnOffPixbuf(int id) {
		SequenceIter s_iter = rows.get_begin_iter();
		
		for(int index = 0; index < rows.get_length(); ++index) {
			s_iter = rows.get_iter_at_pos(index);
			
			if(id == rows.get(s_iter)) {
				TreePath path = new TreePath.from_string(s_iter.get_position().to_string());
				
				TreeIter iter = TreeIter();
				iter.stamp = this.stamp;
				iter.user_data = s_iter;
				
				row_changed(path, iter);
				return;
			}
		}
	}
	
	// just a convenience function
	public void updateMedia(int id, bool is_current) {
		ArrayList<int> temp = new ArrayList<int>();
		temp.add(id);
		updateMedias(temp, is_current);
	}
	
	/** Some actual functions to use this model **/
	public TreeIter? getIterFromRowid(int id) {
		SequenceIter s_iter = rows.get_begin_iter();
		
		for(int index = 0; index < rows.get_length(); ++index) {
			s_iter = rows.get_iter_at_pos(index);
			
			if(id == rows.get(s_iter)) {
				TreeIter iter = TreeIter();
				iter.stamp = this.stamp;
				iter.user_data = s_iter;
				
				return iter;
			}
		}
		
		return null;
	}
	
	public int getRowidFromIter(TreeIter iter) {
		if(iter.stamp != this.stamp || ((SequenceIter)iter.user_data).is_end())
			return 0;
		
		return rows.get(((SequenceIter<int>)iter.user_data));
	}
	
	public int getRowidFromPath(string path) {
		if(int.parse(path) < 0 || int.parse(path) >= rows.get_length())
			return 0;
		
		SequenceIter s_iter = rows.get_iter_at_pos(int.parse(path));
		
		if(s_iter.is_end())
			return 0;
		
		return rows.get(s_iter);
	}
	
	/** simply adds iter to the model **/
	public void append(out TreeIter iter) {
	    iter = TreeIter ();
		SequenceIter<int> added = rows.append(0);
		iter.stamp = this.stamp;
		iter.user_data = added;
	}
	
	
	public void updateMedias(owned Collection<int> rowids, bool is_current) {
		SequenceIter s_iter = rows.get_begin_iter();
		
		for(int index = 0; index < rows.get_length(); ++index) {
			s_iter = rows.get_iter_at_pos(index);
			
			if(rowids.contains(rows.get(s_iter))) {
				TreePath path = new TreePath.from_string(s_iter.get_position().to_string());
			
				TreeIter iter = TreeIter();
				iter.stamp = this.stamp;
				iter.user_data = s_iter;
				
				row_changed(path, iter);
				
				// can't do this. rowids must be read only
				//rowids.remove(rows.get(s_iter));
			}
			
			if(rowids.size <= 0)
				return;
		}
	}
	
	public new void set(TreeIter iter, ...) {
		if(iter.stamp != this.stamp)
			return;
		
		var args = va_list(); // now call args.arg() to poll
		
		while(true) {
			int col = args.arg();
			if(col < 0 || col >= _columns.size)
				return;
			
			/*else if(_columns[col] == " ") {
				debug("set oh hi3\n");
				Gdk.Pixbuf val = args.arg();
				((SequenceIter<ValueArray>)iter.user_data).get().get_nth(col).set_object(val);
			}
			else if(_columns[col] == "Title" || _columns[col] == "Artist" || _columns[col] == "Album" || _columns[col] == "Genre") {
				debug("set oh hi2\n");
				string val = args.arg();
				((SequenceIter<ValueArray>)iter.user_data).get().get_nth(col).set_string(val);
			}
			else {
				debug("set oh hi\n");
				int val = args.arg();
				((SequenceIter<Media>)iter.user_data).get().get_nth(col).set_int(val);
			}*/
		}
	}
	
	public void remove(TreeIter iter) {
		if(iter.stamp != this.stamp)
			return;
			
		var path = new TreePath.from_string(((SequenceIter)iter.user_data).get_position().to_string());
		rows.remove((SequenceIter<int>)iter.user_data);
		row_deleted(path);
	}
	
	public void removeMedias(Collection<int> rowids) {
		removing_medias = true;
		
		SequenceIter s_iter = rows.get_begin_iter();
		
		for(int index = 0; index < rows.get_length(); ++index) {
			s_iter = rows.get_iter_at_pos(index);
			
			if(rowids.contains(rows.get(s_iter))) {
				int rowid = rows.get(s_iter);
				TreePath path = new TreePath.from_string(s_iter.get_position().to_string());
					
				rows.remove(s_iter);
					
				row_deleted(path);
				rowids.remove(rowid);
				--index;
			}
			
			if(rowids.size <= 0) {
				removing_medias = false;
				return;
			}
		}
		
		removing_medias = false;
	}
	
	public LinkedList<int> getOrderedMedias() {
		var rv = new LinkedList<int>();
		SequenceIter s_iter = rows.get_begin_iter();
		
		for(int index = 0; index < rows.get_length(); ++index) {
			s_iter = rows.get_iter_at_pos(index);
			
			int rowid = rows.get(s_iter);
			
			rv.add(rowid);
		}
		
		return rv;
	}

}
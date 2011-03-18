/* SongInfo.c generated by valac 0.11.6, the Vala compiler
 * generated from SongInfo.vala, do not modify */

/* Merely a place holder for multiple pieces of information regarding
 * the current song playing. Mostly here because of dependence. */

#include <glib.h>
#include <glib-object.h>


#define BEAT_BOX_TYPE_SONG_INFO (beat_box_song_info_get_type ())
#define BEAT_BOX_SONG_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BEAT_BOX_TYPE_SONG_INFO, BeatBoxSongInfo))
#define BEAT_BOX_SONG_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BEAT_BOX_TYPE_SONG_INFO, BeatBoxSongInfoClass))
#define BEAT_BOX_IS_SONG_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BEAT_BOX_TYPE_SONG_INFO))
#define BEAT_BOX_IS_SONG_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BEAT_BOX_TYPE_SONG_INFO))
#define BEAT_BOX_SONG_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BEAT_BOX_TYPE_SONG_INFO, BeatBoxSongInfoClass))

typedef struct _BeatBoxSongInfo BeatBoxSongInfo;
typedef struct _BeatBoxSongInfoClass BeatBoxSongInfoClass;
typedef struct _BeatBoxSongInfoPrivate BeatBoxSongInfoPrivate;

#define BEAT_BOX_TYPE_SONG (beat_box_song_get_type ())
#define BEAT_BOX_SONG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BEAT_BOX_TYPE_SONG, BeatBoxSong))
#define BEAT_BOX_SONG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BEAT_BOX_TYPE_SONG, BeatBoxSongClass))
#define BEAT_BOX_IS_SONG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BEAT_BOX_TYPE_SONG))
#define BEAT_BOX_IS_SONG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BEAT_BOX_TYPE_SONG))
#define BEAT_BOX_SONG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BEAT_BOX_TYPE_SONG, BeatBoxSongClass))

typedef struct _BeatBoxSong BeatBoxSong;
typedef struct _BeatBoxSongClass BeatBoxSongClass;

#define LAST_FM_TYPE_ARTIST_INFO (last_fm_artist_info_get_type ())
#define LAST_FM_ARTIST_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LAST_FM_TYPE_ARTIST_INFO, LastFMArtistInfo))
#define LAST_FM_ARTIST_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LAST_FM_TYPE_ARTIST_INFO, LastFMArtistInfoClass))
#define LAST_FM_IS_ARTIST_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LAST_FM_TYPE_ARTIST_INFO))
#define LAST_FM_IS_ARTIST_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LAST_FM_TYPE_ARTIST_INFO))
#define LAST_FM_ARTIST_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LAST_FM_TYPE_ARTIST_INFO, LastFMArtistInfoClass))

typedef struct _LastFMArtistInfo LastFMArtistInfo;
typedef struct _LastFMArtistInfoClass LastFMArtistInfoClass;

#define LAST_FM_TYPE_TRACK_INFO (last_fm_track_info_get_type ())
#define LAST_FM_TRACK_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LAST_FM_TYPE_TRACK_INFO, LastFMTrackInfo))
#define LAST_FM_TRACK_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LAST_FM_TYPE_TRACK_INFO, LastFMTrackInfoClass))
#define LAST_FM_IS_TRACK_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LAST_FM_TYPE_TRACK_INFO))
#define LAST_FM_IS_TRACK_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LAST_FM_TYPE_TRACK_INFO))
#define LAST_FM_TRACK_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LAST_FM_TYPE_TRACK_INFO, LastFMTrackInfoClass))

typedef struct _LastFMTrackInfo LastFMTrackInfo;
typedef struct _LastFMTrackInfoClass LastFMTrackInfoClass;

#define LAST_FM_TYPE_ALBUM_INFO (last_fm_album_info_get_type ())
#define LAST_FM_ALBUM_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LAST_FM_TYPE_ALBUM_INFO, LastFMAlbumInfo))
#define LAST_FM_ALBUM_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LAST_FM_TYPE_ALBUM_INFO, LastFMAlbumInfoClass))
#define LAST_FM_IS_ALBUM_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LAST_FM_TYPE_ALBUM_INFO))
#define LAST_FM_IS_ALBUM_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LAST_FM_TYPE_ALBUM_INFO))
#define LAST_FM_ALBUM_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LAST_FM_TYPE_ALBUM_INFO, LastFMAlbumInfoClass))

typedef struct _LastFMAlbumInfo LastFMAlbumInfo;
typedef struct _LastFMAlbumInfoClass LastFMAlbumInfoClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _BeatBoxSongInfo {
	GObject parent_instance;
	BeatBoxSongInfoPrivate * priv;
	BeatBoxSong* song;
	LastFMArtistInfo* artist;
	LastFMTrackInfo* track;
	LastFMAlbumInfo* album;
};

struct _BeatBoxSongInfoClass {
	GObjectClass parent_class;
};


static gpointer beat_box_song_info_parent_class = NULL;

GType beat_box_song_info_get_type (void) G_GNUC_CONST;
GType beat_box_song_get_type (void) G_GNUC_CONST;
GType last_fm_artist_info_get_type (void) G_GNUC_CONST;
GType last_fm_track_info_get_type (void) G_GNUC_CONST;
GType last_fm_album_info_get_type (void) G_GNUC_CONST;
enum  {
	BEAT_BOX_SONG_INFO_DUMMY_PROPERTY
};
BeatBoxSongInfo* beat_box_song_info_new (void);
BeatBoxSongInfo* beat_box_song_info_construct (GType object_type);
LastFMArtistInfo* last_fm_artist_info_new_basic (void);
LastFMArtistInfo* last_fm_artist_info_construct_basic (GType object_type);
LastFMTrackInfo* last_fm_track_info_new (void);
LastFMTrackInfo* last_fm_track_info_construct (GType object_type);
LastFMAlbumInfo* last_fm_album_info_new_basic (void);
LastFMAlbumInfo* last_fm_album_info_construct_basic (GType object_type);
void beat_box_song_info_update (BeatBoxSongInfo* self, LastFMArtistInfo* art, LastFMTrackInfo* tra, LastFMAlbumInfo* alb, BeatBoxSong* s);
static void beat_box_song_info_finalize (GObject* obj);


BeatBoxSongInfo* beat_box_song_info_construct (GType object_type) {
	BeatBoxSongInfo * self = NULL;
	LastFMArtistInfo* _tmp0_ = NULL;
	LastFMArtistInfo* _tmp1_;
	LastFMTrackInfo* _tmp2_ = NULL;
	LastFMTrackInfo* _tmp3_;
	LastFMAlbumInfo* _tmp4_ = NULL;
	LastFMAlbumInfo* _tmp5_;
	self = (BeatBoxSongInfo*) g_object_new (object_type, NULL);
	_tmp0_ = last_fm_artist_info_new_basic ();
	_tmp1_ = _tmp0_;
	_g_object_unref0 (self->artist);
	self->artist = _tmp1_;
	_tmp2_ = last_fm_track_info_new ();
	_tmp3_ = _tmp2_;
	_g_object_unref0 (self->track);
	self->track = _tmp3_;
	_tmp4_ = last_fm_album_info_new_basic ();
	_tmp5_ = _tmp4_;
	_g_object_unref0 (self->album);
	self->album = _tmp5_;
	return self;
}


BeatBoxSongInfo* beat_box_song_info_new (void) {
	return beat_box_song_info_construct (BEAT_BOX_TYPE_SONG_INFO);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void beat_box_song_info_update (BeatBoxSongInfo* self, LastFMArtistInfo* art, LastFMTrackInfo* tra, LastFMAlbumInfo* alb, BeatBoxSong* s) {
	BeatBoxSong* _tmp0_;
	BeatBoxSong* _tmp1_;
	LastFMArtistInfo* _tmp2_;
	LastFMArtistInfo* _tmp3_;
	LastFMTrackInfo* _tmp4_;
	LastFMTrackInfo* _tmp5_;
	LastFMAlbumInfo* _tmp6_;
	LastFMAlbumInfo* _tmp7_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (art != NULL);
	g_return_if_fail (tra != NULL);
	g_return_if_fail (alb != NULL);
	g_return_if_fail (s != NULL);
	_tmp0_ = _g_object_ref0 (s);
	_tmp1_ = _tmp0_;
	_g_object_unref0 (self->song);
	self->song = _tmp1_;
	_tmp2_ = _g_object_ref0 (art);
	_tmp3_ = _tmp2_;
	_g_object_unref0 (self->artist);
	self->artist = _tmp3_;
	_tmp4_ = _g_object_ref0 (tra);
	_tmp5_ = _tmp4_;
	_g_object_unref0 (self->track);
	self->track = _tmp5_;
	_tmp6_ = _g_object_ref0 (alb);
	_tmp7_ = _tmp6_;
	_g_object_unref0 (self->album);
	self->album = _tmp7_;
}


static void beat_box_song_info_class_init (BeatBoxSongInfoClass * klass) {
	beat_box_song_info_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = beat_box_song_info_finalize;
}


static void beat_box_song_info_instance_init (BeatBoxSongInfo * self) {
}


static void beat_box_song_info_finalize (GObject* obj) {
	BeatBoxSongInfo * self;
	self = BEAT_BOX_SONG_INFO (obj);
	_g_object_unref0 (self->song);
	_g_object_unref0 (self->artist);
	_g_object_unref0 (self->track);
	_g_object_unref0 (self->album);
	G_OBJECT_CLASS (beat_box_song_info_parent_class)->finalize (obj);
}


GType beat_box_song_info_get_type (void) {
	static volatile gsize beat_box_song_info_type_id__volatile = 0;
	if (g_once_init_enter (&beat_box_song_info_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (BeatBoxSongInfoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) beat_box_song_info_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BeatBoxSongInfo), 0, (GInstanceInitFunc) beat_box_song_info_instance_init, NULL };
		GType beat_box_song_info_type_id;
		beat_box_song_info_type_id = g_type_register_static (G_TYPE_OBJECT, "BeatBoxSongInfo", &g_define_type_info, 0);
		g_once_init_leave (&beat_box_song_info_type_id__volatile, beat_box_song_info_type_id);
	}
	return beat_box_song_info_type_id__volatile;
}




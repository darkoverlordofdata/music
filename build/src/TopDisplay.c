/* TopDisplay.c generated by valac 0.11.6, the Vala compiler
 * generated from TopDisplay.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <float.h>
#include <math.h>
#include <pango/pango.h>
#include <stdlib.h>
#include <string.h>


#define ELEMENTARY_WIDGETS_TYPE_TOP_DISPLAY (elementary_widgets_top_display_get_type ())
#define ELEMENTARY_WIDGETS_TOP_DISPLAY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ELEMENTARY_WIDGETS_TYPE_TOP_DISPLAY, ElementaryWidgetsTopDisplay))
#define ELEMENTARY_WIDGETS_TOP_DISPLAY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ELEMENTARY_WIDGETS_TYPE_TOP_DISPLAY, ElementaryWidgetsTopDisplayClass))
#define ELEMENTARY_WIDGETS_IS_TOP_DISPLAY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ELEMENTARY_WIDGETS_TYPE_TOP_DISPLAY))
#define ELEMENTARY_WIDGETS_IS_TOP_DISPLAY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ELEMENTARY_WIDGETS_TYPE_TOP_DISPLAY))
#define ELEMENTARY_WIDGETS_TOP_DISPLAY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ELEMENTARY_WIDGETS_TYPE_TOP_DISPLAY, ElementaryWidgetsTopDisplayClass))

typedef struct _ElementaryWidgetsTopDisplay ElementaryWidgetsTopDisplay;
typedef struct _ElementaryWidgetsTopDisplayClass ElementaryWidgetsTopDisplayClass;
typedef struct _ElementaryWidgetsTopDisplayPrivate ElementaryWidgetsTopDisplayPrivate;

#define BEAT_BOX_TYPE_LIBRARY_MANAGER (beat_box_library_manager_get_type ())
#define BEAT_BOX_LIBRARY_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BEAT_BOX_TYPE_LIBRARY_MANAGER, BeatBoxLibraryManager))
#define BEAT_BOX_LIBRARY_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BEAT_BOX_TYPE_LIBRARY_MANAGER, BeatBoxLibraryManagerClass))
#define BEAT_BOX_IS_LIBRARY_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BEAT_BOX_TYPE_LIBRARY_MANAGER))
#define BEAT_BOX_IS_LIBRARY_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BEAT_BOX_TYPE_LIBRARY_MANAGER))
#define BEAT_BOX_LIBRARY_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BEAT_BOX_TYPE_LIBRARY_MANAGER, BeatBoxLibraryManagerClass))

typedef struct _BeatBoxLibraryManager BeatBoxLibraryManager;
typedef struct _BeatBoxLibraryManagerClass BeatBoxLibraryManagerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _BeatBoxLibraryManagerPrivate BeatBoxLibraryManagerPrivate;

#define BEAT_BOX_TYPE_SETTINGS (beat_box_settings_get_type ())
#define BEAT_BOX_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BEAT_BOX_TYPE_SETTINGS, BeatBoxSettings))
#define BEAT_BOX_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BEAT_BOX_TYPE_SETTINGS, BeatBoxSettingsClass))
#define BEAT_BOX_IS_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BEAT_BOX_TYPE_SETTINGS))
#define BEAT_BOX_IS_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BEAT_BOX_TYPE_SETTINGS))
#define BEAT_BOX_SETTINGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BEAT_BOX_TYPE_SETTINGS, BeatBoxSettingsClass))

typedef struct _BeatBoxSettings BeatBoxSettings;
typedef struct _BeatBoxSettingsClass BeatBoxSettingsClass;

#define BEAT_BOX_TYPE_DATA_BASE_MANAGER (beat_box_data_base_manager_get_type ())
#define BEAT_BOX_DATA_BASE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BEAT_BOX_TYPE_DATA_BASE_MANAGER, BeatBoxDataBaseManager))
#define BEAT_BOX_DATA_BASE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BEAT_BOX_TYPE_DATA_BASE_MANAGER, BeatBoxDataBaseManagerClass))
#define BEAT_BOX_IS_DATA_BASE_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BEAT_BOX_TYPE_DATA_BASE_MANAGER))
#define BEAT_BOX_IS_DATA_BASE_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BEAT_BOX_TYPE_DATA_BASE_MANAGER))
#define BEAT_BOX_DATA_BASE_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BEAT_BOX_TYPE_DATA_BASE_MANAGER, BeatBoxDataBaseManagerClass))

typedef struct _BeatBoxDataBaseManager BeatBoxDataBaseManager;
typedef struct _BeatBoxDataBaseManagerClass BeatBoxDataBaseManagerClass;

#define BEAT_BOX_TYPE_DATA_BASE_UPDATER (beat_box_data_base_updater_get_type ())
#define BEAT_BOX_DATA_BASE_UPDATER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BEAT_BOX_TYPE_DATA_BASE_UPDATER, BeatBoxDataBaseUpdater))
#define BEAT_BOX_DATA_BASE_UPDATER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BEAT_BOX_TYPE_DATA_BASE_UPDATER, BeatBoxDataBaseUpdaterClass))
#define BEAT_BOX_IS_DATA_BASE_UPDATER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BEAT_BOX_TYPE_DATA_BASE_UPDATER))
#define BEAT_BOX_IS_DATA_BASE_UPDATER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BEAT_BOX_TYPE_DATA_BASE_UPDATER))
#define BEAT_BOX_DATA_BASE_UPDATER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BEAT_BOX_TYPE_DATA_BASE_UPDATER, BeatBoxDataBaseUpdaterClass))

typedef struct _BeatBoxDataBaseUpdater BeatBoxDataBaseUpdater;
typedef struct _BeatBoxDataBaseUpdaterClass BeatBoxDataBaseUpdaterClass;

#define BEAT_BOX_TYPE_FILE_OPERATOR (beat_box_file_operator_get_type ())
#define BEAT_BOX_FILE_OPERATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BEAT_BOX_TYPE_FILE_OPERATOR, BeatBoxFileOperator))
#define BEAT_BOX_FILE_OPERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BEAT_BOX_TYPE_FILE_OPERATOR, BeatBoxFileOperatorClass))
#define BEAT_BOX_IS_FILE_OPERATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BEAT_BOX_TYPE_FILE_OPERATOR))
#define BEAT_BOX_IS_FILE_OPERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BEAT_BOX_TYPE_FILE_OPERATOR))
#define BEAT_BOX_FILE_OPERATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BEAT_BOX_TYPE_FILE_OPERATOR, BeatBoxFileOperatorClass))

typedef struct _BeatBoxFileOperator BeatBoxFileOperator;
typedef struct _BeatBoxFileOperatorClass BeatBoxFileOperatorClass;

#define BEAT_BOX_TYPE_STREAM_PLAYER (beat_box_stream_player_get_type ())
#define BEAT_BOX_STREAM_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BEAT_BOX_TYPE_STREAM_PLAYER, BeatBoxStreamPlayer))
#define BEAT_BOX_STREAM_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BEAT_BOX_TYPE_STREAM_PLAYER, BeatBoxStreamPlayerClass))
#define BEAT_BOX_IS_STREAM_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BEAT_BOX_TYPE_STREAM_PLAYER))
#define BEAT_BOX_IS_STREAM_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BEAT_BOX_TYPE_STREAM_PLAYER))
#define BEAT_BOX_STREAM_PLAYER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BEAT_BOX_TYPE_STREAM_PLAYER, BeatBoxStreamPlayerClass))

typedef struct _BeatBoxStreamPlayer BeatBoxStreamPlayer;
typedef struct _BeatBoxStreamPlayerClass BeatBoxStreamPlayerClass;

#define LAST_FM_TYPE_CORE (last_fm_core_get_type ())
#define LAST_FM_CORE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LAST_FM_TYPE_CORE, LastFMCore))
#define LAST_FM_CORE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LAST_FM_TYPE_CORE, LastFMCoreClass))
#define LAST_FM_IS_CORE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LAST_FM_TYPE_CORE))
#define LAST_FM_IS_CORE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LAST_FM_TYPE_CORE))
#define LAST_FM_CORE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LAST_FM_TYPE_CORE, LastFMCoreClass))

typedef struct _LastFMCore LastFMCore;
typedef struct _LastFMCoreClass LastFMCoreClass;

#define BEAT_BOX_TYPE_TREE_VIEW_SETUP (beat_box_tree_view_setup_get_type ())
#define BEAT_BOX_TREE_VIEW_SETUP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BEAT_BOX_TYPE_TREE_VIEW_SETUP, BeatBoxTreeViewSetup))
#define BEAT_BOX_TREE_VIEW_SETUP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BEAT_BOX_TYPE_TREE_VIEW_SETUP, BeatBoxTreeViewSetupClass))
#define BEAT_BOX_IS_TREE_VIEW_SETUP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BEAT_BOX_TYPE_TREE_VIEW_SETUP))
#define BEAT_BOX_IS_TREE_VIEW_SETUP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BEAT_BOX_TYPE_TREE_VIEW_SETUP))
#define BEAT_BOX_TREE_VIEW_SETUP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BEAT_BOX_TYPE_TREE_VIEW_SETUP, BeatBoxTreeViewSetupClass))

typedef struct _BeatBoxTreeViewSetup BeatBoxTreeViewSetup;
typedef struct _BeatBoxTreeViewSetupClass BeatBoxTreeViewSetupClass;

#define BEAT_BOX_TYPE_SONG_INFO (beat_box_song_info_get_type ())
#define BEAT_BOX_SONG_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BEAT_BOX_TYPE_SONG_INFO, BeatBoxSongInfo))
#define BEAT_BOX_SONG_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BEAT_BOX_TYPE_SONG_INFO, BeatBoxSongInfoClass))
#define BEAT_BOX_IS_SONG_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BEAT_BOX_TYPE_SONG_INFO))
#define BEAT_BOX_IS_SONG_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BEAT_BOX_TYPE_SONG_INFO))
#define BEAT_BOX_SONG_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BEAT_BOX_TYPE_SONG_INFO, BeatBoxSongInfoClass))

typedef struct _BeatBoxSongInfo BeatBoxSongInfo;
typedef struct _BeatBoxSongInfoClass BeatBoxSongInfoClass;
#define _g_free0(var) (var = (g_free (var), NULL))
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

struct _ElementaryWidgetsTopDisplay {
	GtkVBox parent_instance;
	ElementaryWidgetsTopDisplayPrivate * priv;
};

struct _ElementaryWidgetsTopDisplayClass {
	GtkVBoxClass parent_class;
	gboolean (*scale_button_press) (ElementaryWidgetsTopDisplay* self, GdkEventButton* event);
	gboolean (*scale_button_release) (ElementaryWidgetsTopDisplay* self, GdkEventButton* event);
	void (*value_changed) (ElementaryWidgetsTopDisplay* self);
	gboolean (*change_value) (ElementaryWidgetsTopDisplay* self, GtkScrollType scroll, gdouble val);
	void (*player_position_update) (ElementaryWidgetsTopDisplay* self, gint64 position);
};

struct _ElementaryWidgetsTopDisplayPrivate {
	BeatBoxLibraryManager* lm;
	GtkLabel* label;
	GtkHBox* scaleBox;
	GtkLabel* leftTime;
	GtkLabel* rightTime;
	GtkHScale* scale;
	GtkProgressBar* progressbar;
};

struct _BeatBoxLibraryManager {
	GObject parent_instance;
	BeatBoxLibraryManagerPrivate * priv;
	BeatBoxSettings* settings;
	BeatBoxDataBaseManager* dbm;
	BeatBoxDataBaseUpdater* dbu;
	BeatBoxFileOperator* fo;
	BeatBoxStreamPlayer* player;
	LastFMCore* lfm;
	BeatBoxTreeViewSetup* music_setup;
	BeatBoxTreeViewSetup* similar_setup;
	BeatBoxTreeViewSetup* queue_setup;
	BeatBoxTreeViewSetup* history_setup;
	gint _played_index;
	gint _current_index;
	gint _current_shuffled_index;
	BeatBoxSongInfo* song_info;
	gboolean playing;
	gboolean repeat;
	gboolean shuffle;
	gboolean doing_file_operations;
};

struct _BeatBoxLibraryManagerClass {
	GObjectClass parent_class;
	void (*dbProgress) (BeatBoxLibraryManager* self, const gchar* message, gdouble progress);
};

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


static gpointer elementary_widgets_top_display_parent_class = NULL;

GType elementary_widgets_top_display_get_type (void) G_GNUC_CONST;
GType beat_box_library_manager_get_type (void) G_GNUC_CONST;
#define ELEMENTARY_WIDGETS_TOP_DISPLAY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), ELEMENTARY_WIDGETS_TYPE_TOP_DISPLAY, ElementaryWidgetsTopDisplayPrivate))
enum  {
	ELEMENTARY_WIDGETS_TOP_DISPLAY_DUMMY_PROPERTY
};
ElementaryWidgetsTopDisplay* elementary_widgets_top_display_new (BeatBoxLibraryManager* lmm);
ElementaryWidgetsTopDisplay* elementary_widgets_top_display_construct (GType object_type, BeatBoxLibraryManager* lmm);
gboolean elementary_widgets_top_display_scale_button_press (ElementaryWidgetsTopDisplay* self, GdkEventButton* event);
static gboolean _elementary_widgets_top_display_scale_button_press_gtk_widget_button_press_event (GtkWidget* _sender, GdkEventButton* event, gpointer self);
void elementary_widgets_top_display_value_changed (ElementaryWidgetsTopDisplay* self);
static void _elementary_widgets_top_display_value_changed_gtk_range_value_changed (GtkRange* _sender, gpointer self);
gboolean elementary_widgets_top_display_change_value (ElementaryWidgetsTopDisplay* self, GtkScrollType scroll, gdouble val);
static gboolean _elementary_widgets_top_display_change_value_gtk_range_change_value (GtkRange* _sender, GtkScrollType scroll, gdouble new_value, gpointer self);
GType beat_box_settings_get_type (void) G_GNUC_CONST;
GType beat_box_data_base_manager_get_type (void) G_GNUC_CONST;
GType beat_box_data_base_updater_get_type (void) G_GNUC_CONST;
GType beat_box_file_operator_get_type (void) G_GNUC_CONST;
GType beat_box_stream_player_get_type (void) G_GNUC_CONST;
GType last_fm_core_get_type (void) G_GNUC_CONST;
GType beat_box_tree_view_setup_get_type (void) G_GNUC_CONST;
GType beat_box_song_info_get_type (void) G_GNUC_CONST;
void elementary_widgets_top_display_player_position_update (ElementaryWidgetsTopDisplay* self, gint64 position);
static void _elementary_widgets_top_display_player_position_update_beat_box_stream_player_current_position_update (BeatBoxStreamPlayer* _sender, gint64 position, gpointer self);
void elementary_widgets_top_display_set_label_text (ElementaryWidgetsTopDisplay* self, const gchar* text);
void elementary_widgets_top_display_set_label_markup (ElementaryWidgetsTopDisplay* self, const gchar* markup);
gchar* elementary_widgets_top_display_get_label_text (ElementaryWidgetsTopDisplay* self);
void elementary_widgets_top_display_set_label_showing (ElementaryWidgetsTopDisplay* self, gboolean val);
void elementary_widgets_top_display_set_scale_sensitivity (ElementaryWidgetsTopDisplay* self, gboolean val);
void elementary_widgets_top_display_set_progress_value (ElementaryWidgetsTopDisplay* self, gdouble progress);
void elementary_widgets_top_display_set_scale_range (ElementaryWidgetsTopDisplay* self, gdouble min, gdouble max);
void elementary_widgets_top_display_set_scale_value (ElementaryWidgetsTopDisplay* self, gdouble val);
gdouble elementary_widgets_top_display_get_scale_value (ElementaryWidgetsTopDisplay* self);
static gboolean elementary_widgets_top_display_real_scale_button_press (ElementaryWidgetsTopDisplay* self, GdkEventButton* event);
gboolean elementary_widgets_top_display_scale_button_release (ElementaryWidgetsTopDisplay* self, GdkEventButton* event);
static gboolean elementary_widgets_top_display_real_scale_button_release (ElementaryWidgetsTopDisplay* self, GdkEventButton* event);
static void elementary_widgets_top_display_real_value_changed (ElementaryWidgetsTopDisplay* self);
static gboolean elementary_widgets_top_display_real_change_value (ElementaryWidgetsTopDisplay* self, GtkScrollType scroll, gdouble val);
void beat_box_stream_player_seek_position (BeatBoxStreamPlayer* self, gint64 position);
void elementary_widgets_top_display_show_scale (ElementaryWidgetsTopDisplay* self);
void elementary_widgets_top_display_show_progressbar (ElementaryWidgetsTopDisplay* self);
static void elementary_widgets_top_display_real_player_position_update (ElementaryWidgetsTopDisplay* self, gint64 position);
GType beat_box_song_get_type (void) G_GNUC_CONST;
GType last_fm_artist_info_get_type (void) G_GNUC_CONST;
GType last_fm_track_info_get_type (void) G_GNUC_CONST;
GType last_fm_album_info_get_type (void) G_GNUC_CONST;
static void g_cclosure_user_marshal_VOID__ENUM_DOUBLE (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
static void elementary_widgets_top_display_finalize (GObject* obj);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean _elementary_widgets_top_display_scale_button_press_gtk_widget_button_press_event (GtkWidget* _sender, GdkEventButton* event, gpointer self) {
	gboolean result;
	result = elementary_widgets_top_display_scale_button_press (self, event);
	return result;
}


static void _elementary_widgets_top_display_value_changed_gtk_range_value_changed (GtkRange* _sender, gpointer self) {
	elementary_widgets_top_display_value_changed (self);
}


static gboolean _elementary_widgets_top_display_change_value_gtk_range_change_value (GtkRange* _sender, GtkScrollType scroll, gdouble new_value, gpointer self) {
	gboolean result;
	result = elementary_widgets_top_display_change_value (self, scroll, new_value);
	return result;
}


static void _elementary_widgets_top_display_player_position_update_beat_box_stream_player_current_position_update (BeatBoxStreamPlayer* _sender, gint64 position, gpointer self) {
	elementary_widgets_top_display_player_position_update (self, position);
}


ElementaryWidgetsTopDisplay* elementary_widgets_top_display_construct (GType object_type, BeatBoxLibraryManager* lmm) {
	ElementaryWidgetsTopDisplay * self = NULL;
	BeatBoxLibraryManager* _tmp0_;
	BeatBoxLibraryManager* _tmp1_;
	GtkLabel* _tmp2_ = NULL;
	GtkLabel* _tmp3_;
	GtkHScale* _tmp4_ = NULL;
	GtkHScale* _tmp5_;
	GtkLabel* _tmp6_ = NULL;
	GtkLabel* _tmp7_;
	GtkLabel* _tmp8_ = NULL;
	GtkLabel* _tmp9_;
	GtkProgressBar* _tmp10_ = NULL;
	GtkProgressBar* _tmp11_;
	GtkHBox* _tmp12_ = NULL;
	GtkHBox* _tmp13_;
	g_return_val_if_fail (lmm != NULL, NULL);
	self = (ElementaryWidgetsTopDisplay*) g_object_new (object_type, NULL);
	_tmp0_ = _g_object_ref0 (lmm);
	_tmp1_ = _tmp0_;
	_g_object_unref0 (self->priv->lm);
	self->priv->lm = _tmp1_;
	_tmp2_ = (GtkLabel*) gtk_label_new ("");
	_tmp3_ = g_object_ref_sink (_tmp2_);
	_g_object_unref0 (self->priv->label);
	self->priv->label = _tmp3_;
	_tmp4_ = (GtkHScale*) gtk_hscale_new_with_range ((gdouble) 0, (gdouble) 1, (gdouble) 1);
	_tmp5_ = g_object_ref_sink (_tmp4_);
	_g_object_unref0 (self->priv->scale);
	self->priv->scale = _tmp5_;
	_tmp6_ = (GtkLabel*) gtk_label_new ("0:00");
	_tmp7_ = g_object_ref_sink (_tmp6_);
	_g_object_unref0 (self->priv->leftTime);
	self->priv->leftTime = _tmp7_;
	_tmp8_ = (GtkLabel*) gtk_label_new ("0:00");
	_tmp9_ = g_object_ref_sink (_tmp8_);
	_g_object_unref0 (self->priv->rightTime);
	self->priv->rightTime = _tmp9_;
	_tmp10_ = (GtkProgressBar*) gtk_progress_bar_new ();
	_tmp11_ = g_object_ref_sink (_tmp10_);
	_g_object_unref0 (self->priv->progressbar);
	self->priv->progressbar = _tmp11_;
	_tmp12_ = (GtkHBox*) gtk_hbox_new (FALSE, 1);
	_tmp13_ = g_object_ref_sink (_tmp12_);
	_g_object_unref0 (self->priv->scaleBox);
	self->priv->scaleBox = _tmp13_;
	gtk_box_pack_start ((GtkBox*) self->priv->scaleBox, (GtkWidget*) self->priv->leftTime, FALSE, FALSE, (guint) 0);
	gtk_box_pack_start ((GtkBox*) self->priv->scaleBox, (GtkWidget*) self->priv->scale, TRUE, TRUE, (guint) 0);
	gtk_box_pack_start ((GtkBox*) self->priv->scaleBox, (GtkWidget*) self->priv->rightTime, FALSE, FALSE, (guint) 0);
	gtk_scale_set_draw_value ((GtkScale*) self->priv->scale, FALSE);
	gtk_label_set_justify (self->priv->label, GTK_JUSTIFY_CENTER);
	gtk_label_set_single_line_mode (self->priv->label, TRUE);
	gtk_label_set_ellipsize (self->priv->label, PANGO_ELLIPSIZE_END);
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) self->priv->label, FALSE, TRUE, (guint) 0);
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) self->priv->progressbar, FALSE, TRUE, (guint) 2);
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) self->priv->scaleBox, FALSE, TRUE, (guint) 0);
	g_signal_connect_object ((GtkWidget*) self->priv->scale, "button-press-event", (GCallback) _elementary_widgets_top_display_scale_button_press_gtk_widget_button_press_event, self, 0);
	g_signal_connect_object ((GtkRange*) self->priv->scale, "value-changed", (GCallback) _elementary_widgets_top_display_value_changed_gtk_range_value_changed, self, 0);
	g_signal_connect_object ((GtkRange*) self->priv->scale, "change-value", (GCallback) _elementary_widgets_top_display_change_value_gtk_range_change_value, self, 0);
	g_signal_connect_object (self->priv->lm->player, "current-position-update", (GCallback) _elementary_widgets_top_display_player_position_update_beat_box_stream_player_current_position_update, self, 0);
	gtk_widget_show_all ((GtkWidget*) self);
	return self;
}


ElementaryWidgetsTopDisplay* elementary_widgets_top_display_new (BeatBoxLibraryManager* lmm) {
	return elementary_widgets_top_display_construct (ELEMENTARY_WIDGETS_TYPE_TOP_DISPLAY, lmm);
}


/** label functions **/
void elementary_widgets_top_display_set_label_text (ElementaryWidgetsTopDisplay* self, const gchar* text) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	gtk_label_set_text (self->priv->label, text);
}


void elementary_widgets_top_display_set_label_markup (ElementaryWidgetsTopDisplay* self, const gchar* markup) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (markup != NULL);
	gtk_label_set_markup (self->priv->label, markup);
}


gchar* elementary_widgets_top_display_get_label_text (ElementaryWidgetsTopDisplay* self) {
	gchar* result = NULL;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = gtk_label_get_text (self->priv->label);
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}


void elementary_widgets_top_display_set_label_showing (ElementaryWidgetsTopDisplay* self, gboolean val) {
	g_return_if_fail (self != NULL);
	if (val) {
		gtk_widget_show ((GtkWidget*) self->priv->label);
	} else {
		gtk_widget_hide ((GtkWidget*) self->priv->label);
	}
}


/** progressbar functions **/
void elementary_widgets_top_display_set_scale_sensitivity (ElementaryWidgetsTopDisplay* self, gboolean val) {
	g_return_if_fail (self != NULL);
	gtk_widget_set_sensitive ((GtkWidget*) self->priv->scale, val);
	gtk_widget_set_visible ((GtkWidget*) self->priv->scale, val);
	gtk_widget_set_visible ((GtkWidget*) self->priv->leftTime, val);
	gtk_widget_set_visible ((GtkWidget*) self->priv->rightTime, val);
}


void elementary_widgets_top_display_set_progress_value (ElementaryWidgetsTopDisplay* self, gdouble progress) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	if (progress > 0.0) {
		_tmp0_ = progress < 1.0;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		gtk_progress_bar_set_fraction (self->priv->progressbar, progress);
	}
}


/** scale functions **/
void elementary_widgets_top_display_set_scale_range (ElementaryWidgetsTopDisplay* self, gdouble min, gdouble max) {
	g_return_if_fail (self != NULL);
	gtk_range_set_range ((GtkRange*) self->priv->scale, min, max);
}


void elementary_widgets_top_display_set_scale_value (ElementaryWidgetsTopDisplay* self, gdouble val) {
	g_return_if_fail (self != NULL);
	gtk_range_set_value ((GtkRange*) self->priv->scale, val);
}


gdouble elementary_widgets_top_display_get_scale_value (ElementaryWidgetsTopDisplay* self) {
	gdouble result = 0.0;
	gdouble _tmp0_;
	g_return_val_if_fail (self != NULL, 0.0);
	_tmp0_ = gtk_range_get_value ((GtkRange*) self->priv->scale);
	result = _tmp0_;
	return result;
}


static gboolean elementary_widgets_top_display_real_scale_button_press (ElementaryWidgetsTopDisplay* self, GdkEventButton* event) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	if ((*event).type == GDK_BUTTON_PRESS) {
		_tmp0_ = (*event).button == 1;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		GtkAllocation extents = {0};
		gint point_x;
		gint point_y;
		gint _tmp1_;
		gint _tmp2_;
		GtkAllocation _tmp3_ = {0};
		GtkAdjustment* _tmp4_ = NULL;
		gdouble _tmp5_;
		gdouble songtime;
		point_x = 0;
		point_y = 0;
		gtk_widget_get_pointer ((GtkWidget*) self->priv->scale, &_tmp1_, &_tmp2_);
		point_x = _tmp1_;
		point_y = _tmp2_;
		gtk_widget_get_allocation ((GtkWidget*) self->priv->scale, &_tmp3_);
		extents = _tmp3_;
		_tmp4_ = gtk_range_get_adjustment ((GtkRange*) self->priv->scale);
		_tmp5_ = gtk_adjustment_get_upper (_tmp4_);
		songtime = ((gdouble) (((gdouble) point_x) / ((gdouble) extents.width))) * _tmp5_;
		elementary_widgets_top_display_change_value (self, GTK_SCROLL_NONE, songtime);
	}
	result = FALSE;
	return result;
}


gboolean elementary_widgets_top_display_scale_button_press (ElementaryWidgetsTopDisplay* self, GdkEventButton* event) {
	return ELEMENTARY_WIDGETS_TOP_DISPLAY_GET_CLASS (self)->scale_button_press (self, event);
}


static gboolean elementary_widgets_top_display_real_scale_button_release (ElementaryWidgetsTopDisplay* self, GdkEventButton* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	result = FALSE;
	return result;
}


gboolean elementary_widgets_top_display_scale_button_release (ElementaryWidgetsTopDisplay* self, GdkEventButton* event) {
	return ELEMENTARY_WIDGETS_TOP_DISPLAY_GET_CLASS (self)->scale_button_release (self, event);
}


static void elementary_widgets_top_display_real_value_changed (ElementaryWidgetsTopDisplay* self) {
	gboolean _tmp0_;
	gint minute;
	gdouble _tmp1_;
	gint seconds;
	gchar* _tmp2_ = NULL;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	GtkAdjustment* _tmp12_ = NULL;
	gdouble _tmp13_;
	gdouble _tmp14_;
	gchar* _tmp15_ = NULL;
	gchar* _tmp21_ = NULL;
	gchar* _tmp22_;
	gchar* _tmp23_;
	gchar* _tmp24_;
	g_return_if_fail (self != NULL);
	_tmp0_ = gtk_widget_get_visible ((GtkWidget*) self->priv->scale);
	if (!_tmp0_) {
		return;
	}
	minute = 0;
	_tmp1_ = gtk_range_get_value ((GtkRange*) self->priv->scale);
	seconds = (gint) _tmp1_;
	while (TRUE) {
		if (!(seconds >= 60)) {
			break;
		}
		minute = minute + 1;
		seconds = seconds - 60;
	}
	if (seconds < 10) {
		gchar* _tmp3_ = NULL;
		gchar* _tmp4_;
		gchar* _tmp5_;
		_tmp3_ = g_strdup_printf ("%i", seconds);
		_tmp4_ = _tmp3_;
		_tmp5_ = g_strconcat ("0", _tmp4_, NULL);
		_g_free0 (_tmp2_);
		_tmp2_ = _tmp5_;
		_g_free0 (_tmp4_);
	} else {
		gchar* _tmp6_ = NULL;
		gchar* _tmp7_;
		_tmp6_ = g_strdup_printf ("%i", seconds);
		_tmp7_ = _tmp6_;
		_g_free0 (_tmp2_);
		_tmp2_ = _tmp7_;
	}
	_tmp8_ = g_strdup_printf ("%i", minute);
	_tmp9_ = _tmp8_;
	_tmp10_ = g_strconcat (_tmp9_, ":", NULL);
	_tmp11_ = g_strconcat (_tmp10_, _tmp2_, NULL);
	gtk_label_set_text (self->priv->leftTime, _tmp11_);
	_g_free0 (_tmp11_);
	_g_free0 (_tmp10_);
	_g_free0 (_tmp9_);
	minute = 0;
	_tmp12_ = gtk_range_get_adjustment ((GtkRange*) self->priv->scale);
	_tmp13_ = gtk_adjustment_get_upper (_tmp12_);
	_tmp14_ = gtk_range_get_value ((GtkRange*) self->priv->scale);
	seconds = ((gint) _tmp13_) - ((gint) _tmp14_);
	while (TRUE) {
		if (!(seconds >= 60)) {
			break;
		}
		minute = minute + 1;
		seconds = seconds - 60;
	}
	if (seconds < 10) {
		gchar* _tmp16_ = NULL;
		gchar* _tmp17_;
		gchar* _tmp18_;
		_tmp16_ = g_strdup_printf ("%i", seconds);
		_tmp17_ = _tmp16_;
		_tmp18_ = g_strconcat ("0", _tmp17_, NULL);
		_g_free0 (_tmp15_);
		_tmp15_ = _tmp18_;
		_g_free0 (_tmp17_);
	} else {
		gchar* _tmp19_ = NULL;
		gchar* _tmp20_;
		_tmp19_ = g_strdup_printf ("%i", seconds);
		_tmp20_ = _tmp19_;
		_g_free0 (_tmp15_);
		_tmp15_ = _tmp20_;
	}
	_tmp21_ = g_strdup_printf ("%i", minute);
	_tmp22_ = _tmp21_;
	_tmp23_ = g_strconcat (_tmp22_, ":", NULL);
	_tmp24_ = g_strconcat (_tmp23_, _tmp15_, NULL);
	gtk_label_set_text (self->priv->rightTime, _tmp24_);
	_g_free0 (_tmp24_);
	_g_free0 (_tmp23_);
	_g_free0 (_tmp22_);
	_g_free0 (_tmp15_);
	_g_free0 (_tmp2_);
}


void elementary_widgets_top_display_value_changed (ElementaryWidgetsTopDisplay* self) {
	ELEMENTARY_WIDGETS_TOP_DISPLAY_GET_CLASS (self)->value_changed (self);
}


static gboolean elementary_widgets_top_display_real_change_value (ElementaryWidgetsTopDisplay* self, GtkScrollType scroll, gdouble val) {
	gboolean result = FALSE;
	guint _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_signal_parse_name ("current-position-update", BEAT_BOX_TYPE_STREAM_PLAYER, &_tmp0_, NULL, FALSE);
	g_signal_handlers_disconnect_matched (self->priv->lm->player, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp0_, 0, NULL, (GCallback) _elementary_widgets_top_display_player_position_update_beat_box_stream_player_current_position_update, self);
	gtk_range_set_value ((GtkRange*) self->priv->scale, val);
	g_signal_emit_by_name (self, "scale-value-changed", scroll, val);
	g_signal_connect_object (self->priv->lm->player, "current-position-update", (GCallback) _elementary_widgets_top_display_player_position_update_beat_box_stream_player_current_position_update, self, 0);
	beat_box_stream_player_seek_position (self->priv->lm->player, (gint64) (val * 1000000000));
	result = FALSE;
	return result;
}


gboolean elementary_widgets_top_display_change_value (ElementaryWidgetsTopDisplay* self, GtkScrollType scroll, gdouble val) {
	return ELEMENTARY_WIDGETS_TOP_DISPLAY_GET_CLASS (self)->change_value (self, scroll, val);
}


/** other functions **/
void elementary_widgets_top_display_show_scale (ElementaryWidgetsTopDisplay* self) {
	g_return_if_fail (self != NULL);
	gtk_widget_show ((GtkWidget*) self->priv->scaleBox);
	gtk_widget_hide ((GtkWidget*) self->priv->progressbar);
}


void elementary_widgets_top_display_show_progressbar (ElementaryWidgetsTopDisplay* self) {
	g_return_if_fail (self != NULL);
	gtk_widget_show ((GtkWidget*) self->priv->progressbar);
	gtk_widget_hide ((GtkWidget*) self->priv->scaleBox);
}


static void elementary_widgets_top_display_real_player_position_update (ElementaryWidgetsTopDisplay* self, gint64 position) {
	gdouble sec;
	g_return_if_fail (self != NULL);
	sec = 0.0;
	if (self->priv->lm->song_info->song != NULL) {
		sec = ((gdouble) position) / 1000000000;
		elementary_widgets_top_display_set_scale_value (self, sec);
	}
}


void elementary_widgets_top_display_player_position_update (ElementaryWidgetsTopDisplay* self, gint64 position) {
	ELEMENTARY_WIDGETS_TOP_DISPLAY_GET_CLASS (self)->player_position_update (self, position);
}


static void g_cclosure_user_marshal_VOID__ENUM_DOUBLE (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__ENUM_DOUBLE) (gpointer data1, gint arg_1, gdouble arg_2, gpointer data2);
	register GMarshalFunc_VOID__ENUM_DOUBLE callback;
	register GCClosure * cc;
	register gpointer data1, data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__ENUM_DOUBLE) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_enum (param_values + 1), g_value_get_double (param_values + 2), data2);
}


static void elementary_widgets_top_display_class_init (ElementaryWidgetsTopDisplayClass * klass) {
	elementary_widgets_top_display_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (ElementaryWidgetsTopDisplayPrivate));
	ELEMENTARY_WIDGETS_TOP_DISPLAY_CLASS (klass)->scale_button_press = elementary_widgets_top_display_real_scale_button_press;
	ELEMENTARY_WIDGETS_TOP_DISPLAY_CLASS (klass)->scale_button_release = elementary_widgets_top_display_real_scale_button_release;
	ELEMENTARY_WIDGETS_TOP_DISPLAY_CLASS (klass)->value_changed = elementary_widgets_top_display_real_value_changed;
	ELEMENTARY_WIDGETS_TOP_DISPLAY_CLASS (klass)->change_value = elementary_widgets_top_display_real_change_value;
	ELEMENTARY_WIDGETS_TOP_DISPLAY_CLASS (klass)->player_position_update = elementary_widgets_top_display_real_player_position_update;
	G_OBJECT_CLASS (klass)->finalize = elementary_widgets_top_display_finalize;
	g_signal_new ("scale_value_changed", ELEMENTARY_WIDGETS_TYPE_TOP_DISPLAY, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__ENUM_DOUBLE, G_TYPE_NONE, 2, GTK_TYPE_SCROLL_TYPE, G_TYPE_DOUBLE);
}


static void elementary_widgets_top_display_instance_init (ElementaryWidgetsTopDisplay * self) {
	self->priv = ELEMENTARY_WIDGETS_TOP_DISPLAY_GET_PRIVATE (self);
}


static void elementary_widgets_top_display_finalize (GObject* obj) {
	ElementaryWidgetsTopDisplay * self;
	self = ELEMENTARY_WIDGETS_TOP_DISPLAY (obj);
	_g_object_unref0 (self->priv->lm);
	_g_object_unref0 (self->priv->label);
	_g_object_unref0 (self->priv->scaleBox);
	_g_object_unref0 (self->priv->leftTime);
	_g_object_unref0 (self->priv->rightTime);
	_g_object_unref0 (self->priv->scale);
	_g_object_unref0 (self->priv->progressbar);
	G_OBJECT_CLASS (elementary_widgets_top_display_parent_class)->finalize (obj);
}


GType elementary_widgets_top_display_get_type (void) {
	static volatile gsize elementary_widgets_top_display_type_id__volatile = 0;
	if (g_once_init_enter (&elementary_widgets_top_display_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ElementaryWidgetsTopDisplayClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) elementary_widgets_top_display_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ElementaryWidgetsTopDisplay), 0, (GInstanceInitFunc) elementary_widgets_top_display_instance_init, NULL };
		GType elementary_widgets_top_display_type_id;
		elementary_widgets_top_display_type_id = g_type_register_static (GTK_TYPE_VBOX, "ElementaryWidgetsTopDisplay", &g_define_type_info, 0);
		g_once_init_leave (&elementary_widgets_top_display_type_id__volatile, elementary_widgets_top_display_type_id);
	}
	return elementary_widgets_top_display_type_id__volatile;
}




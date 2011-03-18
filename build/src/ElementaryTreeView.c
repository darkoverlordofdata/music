/* ElementaryTreeView.c generated by valac 0.11.6, the Vala compiler
 * generated from ElementaryTreeView.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>


#define TYPE_ELEMENTARY_TREE_VIEW (elementary_tree_view_get_type ())
#define ELEMENTARY_TREE_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ELEMENTARY_TREE_VIEW, ElementaryTreeView))
#define ELEMENTARY_TREE_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ELEMENTARY_TREE_VIEW, ElementaryTreeViewClass))
#define IS_ELEMENTARY_TREE_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ELEMENTARY_TREE_VIEW))
#define IS_ELEMENTARY_TREE_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ELEMENTARY_TREE_VIEW))
#define ELEMENTARY_TREE_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ELEMENTARY_TREE_VIEW, ElementaryTreeViewClass))

typedef struct _ElementaryTreeView ElementaryTreeView;
typedef struct _ElementaryTreeViewClass ElementaryTreeViewClass;
typedef struct _ElementaryTreeViewPrivate ElementaryTreeViewPrivate;

struct _ElementaryTreeView {
	GtkTreeView parent_instance;
	ElementaryTreeViewPrivate * priv;
};

struct _ElementaryTreeViewClass {
	GtkTreeViewClass parent_class;
};


static gpointer elementary_tree_view_parent_class = NULL;

GType elementary_tree_view_get_type (void) G_GNUC_CONST;
enum  {
	ELEMENTARY_TREE_VIEW_DUMMY_PROPERTY
};
ElementaryTreeView* elementary_tree_view_new (void);
ElementaryTreeView* elementary_tree_view_construct (GType object_type);


ElementaryTreeView* elementary_tree_view_construct (GType object_type) {
	ElementaryTreeView * self = NULL;
	self = (ElementaryTreeView*) g_object_new (object_type, NULL);
	return self;
}


ElementaryTreeView* elementary_tree_view_new (void) {
	return elementary_tree_view_construct (TYPE_ELEMENTARY_TREE_VIEW);
}


static void elementary_tree_view_class_init (ElementaryTreeViewClass * klass) {
	elementary_tree_view_parent_class = g_type_class_peek_parent (klass);
}


static void elementary_tree_view_instance_init (ElementaryTreeView * self) {
}


GType elementary_tree_view_get_type (void) {
	static volatile gsize elementary_tree_view_type_id__volatile = 0;
	if (g_once_init_enter (&elementary_tree_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ElementaryTreeViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) elementary_tree_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ElementaryTreeView), 0, (GInstanceInitFunc) elementary_tree_view_instance_init, NULL };
		GType elementary_tree_view_type_id;
		elementary_tree_view_type_id = g_type_register_static (GTK_TYPE_TREE_VIEW, "ElementaryTreeView", &g_define_type_info, 0);
		g_once_init_leave (&elementary_tree_view_type_id__volatile, elementary_tree_view_type_id);
	}
	return elementary_tree_view_type_id__volatile;
}




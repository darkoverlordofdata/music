// -*- Mode: vala; indent-tabs-mode: nil; tab-width: 4 -*-
/*-
 * Copyright (c) 2012-2017 elementary LLC. (https://elementary.io)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * The Noise authors hereby grant permission for non-GPL compatible
 * GStreamer plugins to be used and distributed together with GStreamer
 * and Noise. This permission is above and beyond the permissions granted
 * by the GPL license by which Noise is covered. If you modify this code
 * you may extend this exception to your version of the code, but you are not
 * obligated to do so. If you do not wish to do so, delete this exception
 * statement from your version.
 *
 * Authored by: Corentin Noël <corentin@elementary.io>
 */

/**
 * SourceList item.
 */
public class Noise.SourceListItem : Granite.Widgets.SourceList.Item, Granite.Widgets.SourceListDragDest {
    public View view { get; construct; }
    public Granite.Widgets.SourceList source_list { get; construct; }

    public SourceListItem (View view, Granite.Widgets.SourceList source_list) {
        Object (
            view: view,
            name: view.title,
            icon: view.icon,
            badge: view.badge,
            source_list: source_list
        );
    }

    construct {
        view.notify["badge"].connect (() => {
            badge = view.badge;
        });
    }

    public override Gtk.Menu? get_context_menu () {
        return view.get_sidebar_context_menu (source_list, this);
    }

    public bool data_drop_possible (Gdk.DragContext context, Gtk.SelectionData data) {
        return view.accept_data_drop && data.get_target () == Gdk.Atom.intern_static_string ("text/uri-list");
    }

    public Gdk.DragAction data_received (Gdk.DragContext context, Gtk.SelectionData data) {
        view.data_drop (data);
        return Gdk.DragAction.COPY;
    }
}

public class Noise.SourceListExpandableItem : Granite.Widgets.SourceList.ExpandableItem, Granite.Widgets.SourceListSortable {
    public Category category { get; set; }
    public Gtk.Menu? menu { get; set; default = null; }
    public bool allow_user_sorting { get; set; default = false; }

    public SourceListExpandableItem (Category cat) {
        Object (category: cat, name: cat.name);
    }

    public override Gtk.Menu? get_context_menu () {
        return menu;
    }

    public bool allow_dnd_sorting () {
        return allow_user_sorting;
    }

    public int compare (Granite.Widgets.SourceList.Item a, Granite.Widgets.SourceList.Item b) {
        var item_a = a as SourceListItem;
        var item_b = b as SourceListItem;

        if (item_a == null || item_b == null) {
            return 0;
        }

        var res = item_b.view.priority - item_a.view.priority;

        return res == 0
            ? strcmp (item_a.name.collate_key (), item_b.name.collate_key ()) // order them alphabetically
            : res;
    }
}

public class Noise.SourceListRoot : Granite.Widgets.SourceList.ExpandableItem, Granite.Widgets.SourceListSortable {
    public SourceListRoot () {
        base ("SourceListRoot");
    }

    public bool allow_dnd_sorting () {
        return true;
    }

    public int compare (Granite.Widgets.SourceList.Item a, Granite.Widgets.SourceList.Item b) {
        return 0;
    }
}

public class Noise.SourceListView : Granite.Widgets.SourceList {
    Gee.HashMap<string, Granite.Widgets.SourceList.ExpandableItem> categories = new Gee.HashMap<string, Granite.Widgets.SourceList.ExpandableItem> ();

    public SourceListView () {
        base (new SourceListRoot ());

        App.main_window.view_manager.category_added.connect (add_category);
        foreach (var cat in App.main_window.view_manager.categories) {
            add_category (cat);
        }

        App.main_window.view_manager.view_added.connect (add_view);
        foreach (var view in App.main_window.view_manager.views) {
            add_view (view);
        }

        // update the selected item when the selected view changes
        App.main_window.view_manager.notify["selected-view"].connect (() => {
            foreach (var cat in root.children) {
                if (cat is Granite.Widgets.SourceList.ExpandableItem) {
                    foreach (var item in ((Granite.Widgets.SourceList.ExpandableItem)cat).children) {
                        if (item is SourceListItem) {
                            if (((SourceListItem)item).view == App.main_window.view_manager.selected_view) {
                                selected = item;
                            }
                        }
                    }
                }
            }
        });

        Gtk.TargetEntry uri_list_entry = { "text/uri-list", Gtk.TargetFlags.SAME_APP, 0 };
        enable_drag_dest ({ uri_list_entry }, Gdk.DragAction.COPY);
    }

    private void add_category (Category cat) {
        var item = new SourceListExpandableItem (cat);
        root.add (item);

        cat.hide.connect (() => {
            item.visible = false;
        });
        cat.show.connect (() => {
            item.visible = true;
        });

        categories[cat.id] = item;
    }

    private void add_view (View view) {
        var item = new SourceListItem (view, this);
        categories[view.category].add (item);
        categories[view.category].expand_all ();

        if (view == App.main_window.view_manager.selected_view) {
            selected = item;
        }

        view.destroy.connect (() => {
            categories[view.category].remove (item);
        });
    }

    public override void item_selected (Granite.Widgets.SourceList.Item? item) {
        if (item is SourceListItem) {
            App.main_window.view_manager.select (((SourceListItem)item).view);
        }
    }

    // removes the device from menu
    public Gee.Collection<int> remove_device (int page_number) {
        var pages = new Gee.TreeSet<int>();
        // foreach (var device in devices_category.children) {
        //     if (device is SourceListExpandableItem) {
        //         if (page_number == ((SourceListExpandableItem)device).page_number) {
        //             enumerate_children_pages((SourceListExpandableItem)device, ref pages);
        //             devices_category.remove (device);
        //             return pages;
        //         }
        //     }
        // }
        return pages;
    }

    // get the device page_number associated to the view
    public int get_device_from_item (Noise.SourceListExpandableItem item) {
        // foreach (var device in devices_category.children) {
        //     if (item.parent == (Granite.Widgets.SourceList.ExpandableItem)device) {
        //         if (device is SourceListExpandableItem) {
        //             return ((SourceListExpandableItem)device).page_number;
        //         }
        //     }
        // }
        return -1;
    }

    public void enumerate_children_pages (SourceListExpandableItem exp_item, ref Gee.TreeSet<int> pages) {
        // foreach (var views in ((SourceListExpandableItem)exp_item).children) {
        //     if (views is SourceListExpandableItem) {
        //         pages.add (((SourceListExpandableItem)views).page_number);
        //         enumerate_children_pages ((SourceListExpandableItem)views, ref pages);
        //     } else if (views is SourceListItem) {
        //         pages.add (((SourceListItem)views).page_number);
        //     }
        // }
    }

    public void enumerate_children_items (SourceListExpandableItem exp_item, ref Gee.TreeSet<SourceListItem> pages) {
        // foreach (var views in ((SourceListExpandableItem)exp_item).children) {
        //     if (views is SourceListExpandableItem) {
        //         enumerate_children_items ((SourceListExpandableItem)views, ref pages);
        //     } else if (views is SourceListItem) {
        //         pages.add (((SourceListItem)views));
        //     }
        // }
    }

    // change the name shown
    public void change_playlist_name (int page_number, string new_name) {
        // foreach (var playlist in playlists_category.children) {
        //     if (playlist is SourceListItem) {
        //         if (page_number == ((SourceListItem)playlist).page_number) {
        //             ((SourceListItem)playlist).name = new_name;
        //             return;
        //         }
        //     }
        // }
        // var items = new Gee.TreeSet<SourceListItem> ();
        // foreach (var device in devices_category.children) {
        //     if (device is SourceListExpandableItem) {
        //         enumerate_children_items ((SourceListExpandableItem)device, ref items);
        //         foreach (var item in items) {
        //             if (item.page_number == page_number) {
        //                 ((SourceListItem)item).name = new_name;
        //                 return;
        //             }
        //         }
        //     }
        // }
    }

    // change the name shown
    public void change_device_name (int page_number, string new_name) {
        // foreach (var device in devices_category.children) {
        //     if (device is SourceListItem) {
        //         if (page_number == ((SourceListItem)device).page_number) {
        //             ((SourceListItem)device).name = new_name;
        //             return;
        //         }
        //     }
        // }
    }
}

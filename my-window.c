#include "my-window.h"

static void my_window_finalize(GObject *object);

static void my_window_show_dialog(GSimpleAction *action, GVariant *value,
                                  gpointer data);

struct _MyWindow {
  GtkApplicationWindow __parent__;

  GtkWidget *menubar;
};

static const GActionEntry action_entries[] = {
    {"file.show-dialog", my_window_show_dialog, NULL, NULL, NULL}};

G_DEFINE_TYPE(MyWindow, my_window, GTK_TYPE_APPLICATION_WINDOW)

GtkWidget *my_window_new(MyApplication *application) {
  return g_object_new(MY_TYPE_WINDOW, "application",
                      GTK_APPLICATION(application), NULL);
}

static void my_window_class_init(MyWindowClass *klass) {
  GObjectClass *gobject_class;
  //  GtkWidgetClass *gtkwidget_class;
  //
  gobject_class = G_OBJECT_CLASS(klass);
  gobject_class->finalize = my_window_finalize;
  //
  //  gtkwidget_class = GTK_WIDGET_CLASS(klass);
}

static void my_window_finalize(GObject *object) {
  (*G_OBJECT_CLASS(my_window_parent_class)->finalize)(object);
}

static void my_window_init(MyWindow *window) {
  g_action_map_add_action_entries(G_ACTION_MAP(window), action_entries,
                                  G_N_ELEMENTS(action_entries), window);
}

static void my_window_show_dialog(GSimpleAction *action, GVariant *value,
                                  gpointer data) {
  g_print("my_window_show_dialog\n");
}

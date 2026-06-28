#include "my-window.h"
#include "my-preference-dialog.h"

static void my_window_finalize(GObject *object);

static void my_window_show_dialog(GSimpleAction *action, GVariant *value,
                                  gpointer data);
static void my_window_show_preferences(GSimpleAction *action, GVariant *value,
                                  gpointer data);

struct _MyWindow {
  GtkApplicationWindow __parent__;

  GtkWidget *menubar;
  GtkWidget* preference_dialog;
};

static const GActionEntry action_entries[] = {
    {"file.show-dialog", my_window_show_dialog, NULL, NULL, NULL},
    {"file.show-preferences", my_window_show_preferences, NULL, NULL, NULL}};

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
  window->preference_dialog = NULL;
  g_action_map_add_action_entries(G_ACTION_MAP(window), action_entries,
                                  G_N_ELEMENTS(action_entries), window);
}

static void my_window_show_dialog(GSimpleAction *action, GVariant *value,
                                  gpointer data) {
  g_print("my_window_show_dialog\n");
  gtk_show_about_dialog (GTK_WINDOW (data),
                         "authors", (const char*[]){"Me","Myself","I",NULL},
                         //"comments", "Mousepad is a simple text editor for the Xfce desktop environment",
//                         "copyright", "Copyright \xc2\xa9 2005- the Mousepad developers",
//                         "destroy-with-parent", TRUE,
//                         "license-type", "GTK_LICENSE_GPL_2_0",
//                         "logo-icon-name", "MOUSEPAD_ID",
//                         "program-name", "PACKAGE_NAME",
//                         "version", "VERSION_FULL",
//                         "translator-credits", "translator-credits",
//                         "website", "https://docs.xfce.org/apps/mousepad/start",
                         NULL);
}

static void my_window_show_preferences(GSimpleAction *action, GVariant *value,
    gpointer data) {
  g_print("show preferences\n");

  MyWindow *window = data;
  if (window->preference_dialog == NULL) {
    window->preference_dialog = my_preference_dialog_new(window);
  }

  gtk_window_set_transient_for(GTK_WINDOW(window->preference_dialog),GTK_WINDOW(window));

  gtk_window_present(GTK_WINDOW(window->preference_dialog));
}



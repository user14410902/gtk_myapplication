#include "my-application.h"
#include "my-application-private.h"
#include "my-window.h"

static void my_application_activate(GApplication *application);
static void my_application_startup(GApplication *application);
static void my_application_shutdown(GApplication *application);
static void my_application_action_quit(GSimpleAction *action, GVariant *value,
                                       gpointer data);
static GtkWidget *my_application_create_window(MyApplication *application);

struct _MyApplication {
  GtkApplication __parent__;

  // GtkWidget *menubar;
  MyWindow *window;
};
/* stateless actions */
static const GActionEntry stateless_actions[] = {
    /* command line options */
    {"quit", my_application_action_quit, NULL, NULL, NULL}};
#define N_STATELESS G_N_ELEMENTS(stateless_actions)

G_DEFINE_TYPE(MyApplication, my_application, GTK_TYPE_APPLICATION)

static void my_application_class_init(MyApplicationClass *klass) {
  // GObjectClass *gobject_class = G_OBJECT_CLASS(klass);
  GApplicationClass *application_class = G_APPLICATION_CLASS(klass);
  application_class->activate = my_application_activate;
  application_class->startup = my_application_startup;
  // application_class->open= my_application_open;
  application_class->shutdown = my_application_shutdown;
}

static void my_application_init(MyApplication *application) {
  g_set_application_name("Lotus 123");
  g_set_prgname(MY_APPLICATION_ID);
}

static void my_application_activate(GApplication *gapplication) {
  GtkWidget *window =
      my_application_create_window(MY_APPLICATION(gapplication));
  (MY_APPLICATION(gapplication))->window = MY_WINDOW(window);
  gtk_application_window_set_show_menubar(GTK_APPLICATION_WINDOW(window), TRUE);
  gtk_window_present(GTK_WINDOW(window));

  //  GtkWidget *window =
  //  gtk_application_window_new(GTK_APPLICATION(gapplication));
  //  gtk_window_present(GTK_WINDOW(window));
}

static void my_application_startup(GApplication *gapplication) {
  MyApplication *application = MY_APPLICATION(gapplication);

  G_APPLICATION_CLASS(my_application_parent_class)->startup(gapplication);

  // GMenu *menu;
  // menu =
  //    gtk_application_get_menu_by_id(GTK_APPLICATION(application), "menubar");

  g_action_map_add_action_entries(G_ACTION_MAP(application), stateless_actions,
                                  N_STATELESS, application);
  const gchar *resourceBasePath =
      g_application_get_resource_base_path(gapplication);
  g_print("resourceBasePath=%s\n", resourceBasePath);
  g_free(resourceBasePath);
}

static void my_application_shutdown(GApplication *gapplication) {
  G_APPLICATION_CLASS(my_application_parent_class)->shutdown(gapplication);
}

static GtkWidget *my_application_create_window(MyApplication *application) {
  GtkWidget *window = my_window_new(application);
  // compiler error gtk_window_set_screen(GTK_WINDOW(window),
  // gdk_screen_get_default());
  return window;
}

static void my_application_action_quit(GSimpleAction *action, GVariant *value,
                                       gpointer data) {
  GList *windows = g_list_copy(gtk_application_get_windows(data));
  GList *window = NULL;
  for (window = windows; window != NULL; window = window->next) {
    gtk_window_destroy(GTK_WINDOW(window->data));
  }
  g_list_free(windows);
  g_print("quit\n");
}

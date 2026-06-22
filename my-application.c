#include "my-application.h"

static void my_application_activate(GApplication *application);
static void my_application_startup(GApplication *application);

struct _MyApplication {
  GtkApplication __parent__;

  GtkWidget *menubar;
};

G_DEFINE_TYPE(MyApplication, my_application, GTK_TYPE_APPLICATION)

static void my_application_class_init(MyApplicationClass *klass) {
  // GObjectClass *gobject_class = G_OBJECT_CLASS(klass);
  GApplicationClass *application_class = G_APPLICATION_CLASS(klass);
  application_class->activate = my_application_activate;
  application_class->startup = my_application_startup;
}

static void my_application_init(MyApplication *application) {}

static void my_application_activate(GApplication *application) {
  GtkWidget *window = gtk_application_window_new(GTK_APPLICATION(application));
  gtk_window_present(GTK_WINDOW(window));
}

static void my_application_startup(GApplication *gapplication) {
  MyApplication *application = MY_APPLICATION(gapplication);
  GMenu *menu;

  G_APPLICATION_CLASS(my_application_parent_class)->startup(gapplication);

  menu = gtk_application_get_menu_by_id(GTK_APPLICATION(application),"menubar");


}

#include "my-application.h"

static void my_application_activate(GApplication *application);

struct _MyApplication {
  GtkApplication __parent__;
};

G_DEFINE_TYPE(MyApplication, my_application, GTK_TYPE_APPLICATION)

static void my_application_class_init(MyApplicationClass *klass) {
  // GObjectClass *gobject_class = G_OBJECT_CLASS(klass);
  GApplicationClass *application_class = G_APPLICATION_CLASS(klass);
  application_class->activate = my_application_activate;
}

static void my_application_init(MyApplication *application) {}

static void my_application_activate(GApplication *application) {
  GtkWidget *window = gtk_application_window_new(GTK_APPLICATION(application));
  gtk_window_present(GTK_WINDOW(window));
}

static void my_application_startup(GApplication *gapplication) {}

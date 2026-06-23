#include "my-window.h"

static void my_window_finalize(GObject *object);

struct _MyWindow {
  GtkApplicationWindow __parent__;

  GtkWidget *menubar;
};

G_DEFINE_TYPE(MyWindow, my_window, GTK_TYPE_APPLICATION_WINDOW)

GtkWidget *my_window_new(MyApplication *application) {
  return g_object_new(MY_TYPE_WINDOW, "application",
                      GTK_APPLICATION(application), NULL);
}

static void my_window_class_init(MyWindowClass *klass) {
  GObjectClass * gobject_class;
//  GtkWidgetClass *gtkwidget_class;
//
  gobject_class = G_OBJECT_CLASS(klass);
  gobject_class->finalize=my_window_finalize;
//
//  gtkwidget_class = GTK_WIDGET_CLASS(klass);
}

static void my_window_finalize(GObject *object) {
  (*G_OBJECT_CLASS(my_window_parent_class)->finalize)(object);
}

static void my_window_init(MyWindow *window) {

}

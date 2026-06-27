#include "my-preference-dialog.h"
#include <threads.h>

struct _MyPreferenceDialog {
  GtkDialog parent;

  GtkBuilder *builder;
  MyWindow *parent_window;
};

static void my_preference_dialog_constructed(GObject *object);
static void my_preference_dialog_finalize(GObject *object);

G_DEFINE_TYPE(MyPreferenceDialog, my_preference_dialog, GTK_TYPE_DIALOG);

static void my_preference_dialog_class_init(MyPreferenceDialogClass *klass) {
  GObjectClass *g_object_class = G_OBJECT_CLASS(klass);
  g_object_class->constructed = my_preference_dialog_constructed;
  g_object_class->finalize = my_preference_dialog_finalize;
}

static void my_preference_dialog_constructed(GObject *object) {
  G_OBJECT_CLASS(my_preference_dialog_parent_class)->constructed(object);
}

static void my_preference_dialog_finalize(GObject *object) {
  MyPreferenceDialog *self;
  g_return_if_fail(MY_IS_PREFERENCE_DIALOG(object));
  self = MY_PREFERENCE_DIALOG(object);
  if (self->builder != NULL) {
    g_object_unref(self->builder);
  }
  G_OBJECT_CLASS(my_preference_dialog_parent_class)->finalize(object);
}

static void my_preference_dialog_init(MyPreferenceDialog *self) {
  self->builder = gtk_builder_new();
  GError *error = NULL;
  if (!gtk_builder_add_from_resource(
          self->builder, "/my/application/ui/my-preference-dialog-sample.ui",
          &error)) {
    g_error("failed to load preference dialog: %s", error->message);
    g_printerr("failed to load preference dialog: %s\n", error->message); //TODO are both g_error and g_printerr required?
    g_clear_error(&error);
    g_error_free(error); //TODO are both g_clear_error and g_error_free required?
    g_object_unref(self->builder);
    self->builder = NULL;
    return;
  }
  gtk_window_set_title(GTK_WINDOW(self),
                       "My Preferences"); // TODO use translation
  gtk_window_set_icon_name(GTK_WINDOW(self),
                           "preferences-desktop"); // TODO fix icon

  //GtkDialog *dialog = GTK_DIALOG(gtk_builder_get_object(self->builder, "my_dialog"));
  //gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(self->parent_window));
  //gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
  //gtk_widget_set_visible(GTK_WIDGET(dialog), TRUE);

  GtkFrame *frame = GTK_FRAME(gtk_builder_get_object(self->builder,"my_frame"));
  GtkDialog *dialog = GTK_DIALOG(self);
  GtkWidget *content_area = gtk_dialog_get_content_area(dialog);
  gtk_box_append(GTK_BOX(content_area),GTK_WIDGET(frame));

  g_object_unref(self->builder);
  self->builder = NULL;
}

GtkWidget *my_preference_dialog_new(MyWindow* parent_window) {
  GtkWidget *obj = g_object_new(MY_TYPE_PREFERENCE_DIALOG, NULL);
  MY_PREFERENCE_DIALOG(obj)->parent_window = parent_window;
  return obj;
}

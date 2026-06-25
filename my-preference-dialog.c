#include "my-preference-dialog.h"

struct _MyPreferenceDialog {
  GtkDialog parent;

  GtkBuilder *builder;
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
  GtkWindow *dialog = GTK_WINDOW(object);
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

}

GtkWidget *my_preference_dialog_new(void) {
  return g_object_new(MY_TYPE_PREFERENCE_DIALOG,NULL);
}

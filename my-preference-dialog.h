#ifndef __MY_PREFERENCE_DIALOG_H__
#define __MY_PREFERENCE_DIALOG_H__
#include <gtk/gtk.h>
#include "my-window.h"

G_BEGIN_DECLS

#define MY_TYPE_PREFERENCE_DIALOG (my_preference_dialog_get_type ())
G_DECLARE_FINAL_TYPE(MyPreferenceDialog,my_preference_dialog,MY,PREFERENCE_DIALOG,GtkDialog)
  
GtkWidget * my_preference_dialog_new(MyWindow* parent_window);
G_END_DECLS
#endif


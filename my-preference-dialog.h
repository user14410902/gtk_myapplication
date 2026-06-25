#ifndef __MY_PREFERENCE_DIALOG_H__
#define __MY_PREFERENCE_DIALOG_H__
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MY_TYPE_PREFERENCE_DIALOG (my_preference_dialog_get_type ())
G_DECLARE_FINAL_TYPE(MyPreferenceDialog,my_preference_dialog,MY,PREFERENCE_DIALOG,GtkDialog)
  
GtkWidget * my_preference_dialog_new(void);
G_END_DECLS
#endif


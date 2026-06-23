#ifndef __MY_WINDOW_H__
#define __MY_WINDOW_H__

#include "my-application.h"

G_BEGIN_DECLS

#define MY_TYPE_WINDOW (my_window_get_type())
G_DECLARE_FINAL_TYPE(MyWindow, my_window, MY, WINDOW, GtkApplicationWindow)

GtkWidget *my_window_new(MyApplication *application);

G_END_DECLS

#endif

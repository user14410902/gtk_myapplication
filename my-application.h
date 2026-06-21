#ifndef __MYAPPLICATION_H__
#define __MYAPPLICATION_H__

#include <gtk/gtk.h>


G_BEGIN_DECLS

#define MY_TYPE_APPLICATION (my_application_get_type ())
G_DECLARE_FINAL_TYPE(MyApplication, my_application, MY, APPLICATION, GtkApplication)

G_END_DECLS

#endif

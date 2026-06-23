#include "my-application-private.h"
#include "my-application.h"
#include <libintl.h>
#include <locale.h>
#include <stdlib.h>

#define _(STRING) gettext(STRING)
#define DOMAINNAME "messages"
int main(int argc, char *argv[]) {

  setlocale(LC_ALL, "");
  bindtextdomain(DOMAINNAME, getenv("PWD"));
  bind_textdomain_codeset(DOMAINNAME, "UTF-8");
  textdomain(DOMAINNAME);

  g_setenv("GSETTINGS_SCHEMA_DIR", ".", FALSE);

  MyApplication *application = g_object_new(
      MY_TYPE_APPLICATION, "application-id", MY_APPLICATION_ID, NULL);

  gint status = g_application_run(G_APPLICATION(application), argc, argv);
  g_object_unref(application);
  return status;
}

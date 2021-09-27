#include "keyb.h"
#include <glib.h>

#include "display-internal.h"
#include "display.h"

#include "view.h"

#include "view-internal.h"

static const display_proxy *proxy;

void display_init(const display_proxy *disp_in) {
  proxy = disp_in;
  view_init(proxy->view());
}

int monitor_active(workarea *mon) { return proxy->monitor_active(mon); }

void display_set_input_focus(guint w) { proxy->set_input_focus(w); }

void display_revert_input_focus() { proxy->revert_input_focus(); }

gboolean display_setup(GMainLoop *main_loop, NkBindings *bindings) {
  return proxy->setup(main_loop, bindings);
}

gboolean display_late_setup(void) { return proxy->late_setup(); }

void display_early_cleanup(void) { proxy->early_cleanup(); }

void display_cleanup(void) { proxy->cleanup(); }

void display_dump_monitor_layout(void) { proxy->dump_monitor_layout(); }

void display_startup_notification(RofiHelperExecuteContext *context,
                                  GSpawnChildSetupFunc *child_setup,
                                  gpointer *user_data) {
  proxy->startup_notification(context, child_setup, user_data);
}

guint display_scale(void) { return proxy->scale(); }

char *display_get_clipboard_data(enum clipboard_type type) {
  return proxy->get_clipboard_data(type);
}

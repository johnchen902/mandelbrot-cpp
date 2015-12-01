#include "gui.h"
#include <gtkmm/application.h>
#include <glibmm/refptr.h>
#include "gui-window.h"

namespace mdb {

    int start_gui(int argc, char **argv) {
        Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);
        
        MainWindow win;

        return app->run(win);
    }

}


#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H

#include <gtkmm/window.h>
#include "gui-myarea.h"

namespace mdb {
    class MainWindow : public Gtk::Window {
        MyArea myarea;
    public:
        MainWindow();
    };
}

#endif // GUI_WINDOW_H


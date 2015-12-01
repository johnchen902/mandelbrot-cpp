#include "gui-window.h"

namespace mdb {
    MainWindow::MainWindow() : myarea() {
        set_default_size(600, 600);
        set_title("Mandelbrot Viewer");
        add(myarea);
        show_all_children();
    }
}


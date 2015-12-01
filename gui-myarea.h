#ifndef GUI_MYAREA_H
#define GUI_MYAREA_H

#include <gtkmm/drawingarea.h>

namespace mdb {

    class MyArea : public Gtk::DrawingArea {
    public:
        MyArea();
    protected:
        virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
    };

}

#endif // GUI_MYAREA_H


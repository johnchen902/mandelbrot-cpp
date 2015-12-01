#include "gui-myarea.h"
#include <cstdint>
#include <complex>
#include <gdkmm/general.h>

namespace mdb {

    // XXX Computations should not be done on the EDT.

    template<typename Type>
    uint8_t sample(Type c) {
        uint8_t count = 0;
        for(Type z(c); std::norm(z) < 4 && count < 0xFF; z = z * z + c, count++)
            ;
        return count;
    }

    template<typename Type>
    uint8_t sample(Type cx, Type cy) {
        return sample(std::complex<Type>(cx, cy));
    }

    MyArea::MyArea() {
    }

    bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
        Gtk::Allocation allocation = get_allocation();
        const size_t width = allocation.get_width();
        const size_t height = allocation.get_height();
        
        Glib::RefPtr<Gdk::Pixbuf> image = Gdk::Pixbuf::create(Gdk::COLORSPACE_RGB, false, 8, width, height);
        guchar *px = image->get_pixels();
        size_t rs = image->get_rowstride(), nc = image->get_n_channels();

        for(size_t j = 0; j < height; j++)
            for(size_t i = 0; i < width; i++) {
                uint8_t s = 0xFF - sample((double) i / width * 2.5 - 2.0, (double) j / height * 2.5 - 1.25);
                // See https://developer.gnome.org/gdk-pixbuf/unstable/gdk-pixbuf-The-GdkPixbuf-Structure.html
                guchar *p = px + j * rs + i * nc;
                p[0] = p[1] = p[2] = s;
            }

        Gdk::Cairo::set_source_pixbuf(cr, image);
        cr->paint();

        return true;
    }

}


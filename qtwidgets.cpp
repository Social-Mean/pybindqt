#include <pybind11/pybind11.h>

#include "widgets_base.h"

namespace py = pybind11;

PYBIND11_MODULE(QtWidgets, m) {
    bind_widget(m);
    bind_application(m);
    bind_mainwindow(m);
    // bind_pushbutton(m);
}
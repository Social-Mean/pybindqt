#include "widgets_base.h"

namespace py = pybind11;

void bind_signal(py::module_ &m) {
    py::class_<Signal>(m, "Signal")
        .def(py::init([](QObject *self) { return Signal(self); }))
        .def("connect", &Signal::connect);
}

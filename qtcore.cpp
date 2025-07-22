#include <pybind11/pybind11.h>
#include "signal.h"

namespace py = pybind11;

PYBIND11_MODULE(QtCore, m) {
    py::class_<Signal>(m, "Signal").def("connect", &Signal::connect);
    py::class_<Clicked, Signal>(m, "Clicked").def("connect", &Clicked::connect);
}
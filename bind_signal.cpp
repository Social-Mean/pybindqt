#include <pybind11/pybind11.h>

#include "widgets_base.h"

namespace py = pybind11;

void bind_signal(py::module_ &m) {
  py::class_<Signal>(m, "Signal")
      .def(py::init([](QObject *self) { return Signal(self); }))
      .def("connect", &Signal::connect);

  py::class_<Destroyed, Signal>(m, "Destroyed").def(py::init([](QObject *self) {
    return Destroyed(self);
  }));

  py::class_<ObjectNameChanged, Signal>(m, "ObjectNameChanged")
      .def(py::init([](QObject *self) { return ObjectNameChanged(self); }));

  py::class_<Clicked, Signal>(m, "Clicked").def(py::init([](QPushButton *self) {
    return Clicked(self);
  }));
}

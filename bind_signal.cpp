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

  py::class_<CustomContextMenuRequested, Signal>(m,
                                                 "CustomContextMenuRequested")
      .def(py::init(
          [](QWidget *self) { return CustomContextMenuRequested(self); }));

  py::class_<WindowIconChanged, Signal>(m, "WindowIconChanged")
      .def(py::init([](QWidget *self) { return WindowIconChanged(self); }));

  py::class_<WindowIconTextChanged, Signal>(m, "WindowIconTextChanged")
      .def(py::init([](QWidget *self) { return WindowIconTextChanged(self); }));

  py::class_<WindowTitleChanged, Signal>(m, "WindowTitleChanged")
      .def(py::init([](QWidget *self) { return WindowTitleChanged(self); }));

  py::class_<Clicked, Signal>(m, "Clicked").def(py::init([](QPushButton *self) {
    return Clicked(self);
  }));

  py::class_<Pressed, Signal>(m, "Pressed").def(py::init([](QPushButton *self) {
    return Pressed(self);
  }));

  py::class_<Released, Signal>(m, "Released")
      .def(py::init([](QPushButton *self) { return Released(self); }));

  py::class_<Toggled, Signal>(m, "Toggled").def(py::init([](QPushButton *self) {
    return Toggled(self);
  }));
}

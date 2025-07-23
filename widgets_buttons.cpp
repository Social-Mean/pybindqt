#include "widgets_base.h"
#include "CustomPushButton.h"
#include <pybind11/pybind11.h>
#include <memory>

void bind_pushbutton(py::module_ &m) {
    py::class_<CustomPushButton, QWidget>(m, "QPushButton")
        .def(py::init([]() { return std::make_unique<CustomPushButton>(); }))
        .def("setText", &CustomPushButton::setText)
        .def("show", &CustomPushButton::show)
        .def_readonly("clicked", &CustomPushButton::clicked);
}
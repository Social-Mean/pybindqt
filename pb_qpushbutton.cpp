#include "pb_qpushbutton.h"
#include <pybind11/pybind11.h>
#include <memory>
namespace py = pybind11;

PB_QPushButton::PB_QPushButton(QWidget *parent)
    : QPushButton(parent), clicked(this) {}

void bind_pushbutton(py::module_ &m) {
    py::class_<PB_QPushButton, QWidget>(m, "QPushButton")
        .def(py::init([]() { return std::make_unique<PB_QPushButton>(); }))
        .def("setText", &PB_QPushButton::setText)
        .def("show", &PB_QPushButton::show)
        .def_readonly("clicked", &PB_QPushButton::clicked);
}
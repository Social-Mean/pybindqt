#include <pybind11/pybind11.h>

#include <QObject>
#include <QPushButton>
#include <QWidget>

namespace py = pybind11;

void bind_qpushbutton(py::module_ &m) {
  py::class_<QPushButton, QWidget>(m, "QPushButton")
      .def(py::init([]() { return std::make_unique<QPushButton>(); }))
      .def("show", &QPushButton::show)
      .def("setText", &QPushButton::setText)
      .def("text",
           [](QPushButton *self) { return self->text().toStdString(); });
}
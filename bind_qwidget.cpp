#include <pybind11/pybind11.h>

#include <QWidget>
namespace py = pybind11;

void bind_qwidget(py::module_ &m) {
  py::class_<QWidget>(m, "QWidget")
      .def("setParent", py::overload_cast<QWidget *>(&QWidget::setParent))
      .def("setParent",
           py::overload_cast<QWidget *, Qt::WindowFlags>(&QWidget::setParent));
}
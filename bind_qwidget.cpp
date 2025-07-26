#include <pybind11/stl.h>

#include "widgets_base.h"
#include <QWidget>

void bind_qwidget(py::module_ &m) {
  py::class_<QWidget>(m, "QWidget")
      .def("setParent", py::overload_cast<QWidget *>(&QWidget::setParent))
      .def("setParent",
           py::overload_cast<QWidget *, Qt::WindowFlags>(&QWidget::setParent));
}
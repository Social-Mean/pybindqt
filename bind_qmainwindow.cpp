#include <pybind11/stl.h>

#include "widgets_base.h"
#include <QMainWindow>
#include <QWidget>

void bind_qmainwindow(py::module_ &m) {
  py::class_<QMainWindow, QWidget>(m, "QMainWindow")
      .def(py::init([]() { return std::make_unique<QMainWindow>(); }))
      .def("show", &QMainWindow::show);
}
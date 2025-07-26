#include <pybind11/pybind11.h>

#include <QMainWindow>
#include <QWidget>
namespace py = pybind11;

void bind_qmainwindow(py::module_ &m) {
  py::class_<QMainWindow, QWidget>(m, "QMainWindow")
      .def(py::init([]() { return std::make_unique<QMainWindow>(); }))
      .def("show", &QMainWindow::show);
}
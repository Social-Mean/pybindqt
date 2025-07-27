#include <pybind11/pybind11.h>

#include <QMainWindow>
#include <QWidget>
namespace py = pybind11;

void bind_qmainwindow(py::module_ &m) {
  py::class_<QMainWindow, QWidget>(m, "QMainWindow")
      .def(py::init([]() { return std::make_unique<QMainWindow>(); }))
      .def("show", &QMainWindow::show)
      .def("setWindowTitle",
           [](QMainWindow *self, const std::string &title) {
             self->setWindowTitle(QString::fromStdString(title));
           })
      .def("resize",
           [](QMainWindow *self, int w, int h) { self->resize(w, h); });
}
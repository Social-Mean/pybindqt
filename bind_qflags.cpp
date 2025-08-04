#include <pybind11/pybind11.h>

#include <QFlags>

#include "widgets_base.h"

namespace py = pybind11;

void bind_qflags(py::module_ &m) {
  py::class_<QFlags<Qt::WindowType>>(m, "QFlags")
      .def(py::init<>())
      .def(py::init<Qt::WindowType>())
      .def("__or__", [](const QFlags<Qt::WindowType> &a,
                        Qt::WindowType b) { return a | b; })
      .def("__or__", [](const QFlags<Qt::WindowType> &a,
                        const QFlags<Qt::WindowType> &b) { return a | b; })
      .def("__and__", [](const QFlags<Qt::WindowType> &a,
                         Qt::WindowType b) { return a & b; })
      .def("__and__", [](const QFlags<Qt::WindowType> &a,
                         const QFlags<Qt::WindowType> &b) { return a & b; })
      .def("__invert__", [](const QFlags<Qt::WindowType> &a) { return ~a; })
      .def("__bool__", [](const QFlags<Qt::WindowType> &a) { return !!a; })
      .def("testFlag", &QFlags<Qt::WindowType>::testFlag);
}
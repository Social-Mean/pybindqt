#include <pybind11/functional.h>
#include <pybind11/pybind11.h>

#include <QMetaMethod>
#include <QObject>
#include <QPushButton>
#include <pybind11/pytypes.h>

namespace py = pybind11;

void bind_qobject(py::module_ &m) {
  py::class_<QObject>(m, "QObject")
      .def("setParent", py::overload_cast<QObject *>(&QObject::setParent));
}
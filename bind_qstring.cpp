#include <pybind11/pybind11.h>

#include <QByteArray>
#include <QString>

namespace py = pybind11;

void bind_qstring(py::module_ &m) { py::class_<QString>(m, "QString"); }
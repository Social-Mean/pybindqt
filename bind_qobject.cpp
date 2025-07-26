#include <pybind11/functional.h>
#include <pybind11/pybind11.h>

#include <QObject>

namespace py = pybind11;

void bind_qobject(py::module_ &m) {
  py::class_<QObject>(m, "QObject")
      .def("setParent", py::overload_cast<QObject *>(&QObject::setParent))
      // 基本的connect重载 - 使用字符串信号和槽
      .def_static(
          "connect",
          [](const QObject *sender, const char *signal, const QObject *receiver,
             const char *slot, Qt::ConnectionType type = Qt::AutoConnection) {
            return QObject::connect(sender, signal, receiver, slot, type);
          })
      // 使用QMetaMethod的connect重载
      .def_static(
          "connect", [](const QObject *sender, const QMetaMethod &signal,
                        const QObject *receiver, const QMetaMethod &method,
                        Qt::ConnectionType type = Qt::AutoConnection) {
            return QObject::connect(sender, signal, receiver, method, type);
          });
}
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>

#include <QMetaMethod>
#include <QObject>
#include <QPushButton>
#include <pybind11/pytypes.h>

#include <memory>

namespace py = pybind11;

void bind_qobject(py::module_ &m) {
  py::class_<QObject>(m, "QObject")
      .def_property_readonly("objectName",
                             [](QObject *self) { return self->objectName(); })
      .def(py::init([](QObject *parent) {
             return std::make_unique<QObject>(parent);
           }),
           py::arg("parent") = nullptr)
      .def("blockSignals", &QObject::blockSignals)
      .def("children", &QObject::children)
      //   .def("connect", &QObject::connect)
      //   .def("disconnect", &QObject::disconnect)  // 有重载
      //   .def("dumpObjectInfo", &QObject::dumpObjectInfo)
      //   .def("dumpObjectTree", &QObject::dumpObjectTree)
      //   .def("dynamicPropertyNames", &QObject::dynamicPropertyNames)
      //   .def("event", &QObject::event)
      //   .def("eventFilter", &QObject::eventFilter)
      //   .def("findChild", &QObject::findChild)
      //   .def("findChildren", &QObject::findChildren)  // 有重载
      .def("inherits", &QObject::inherits)
      .def("installEventFilter", &QObject::installEventFilter)
      .def("isWidgetType", &QObject::isWidgetType)
      .def("isWindowType", &QObject::isWindowType)
      .def("killTimer", &QObject::killTimer)
      //   .def("metaObject", &QObject::metaObject)
      //   .def("moveToThread", &QObject::moveToThread)
      .def("parent", &QObject::parent)
      //   .def("property", &QObject::property)
      .def("removeEventFilter", &QObject::removeEventFilter)
      .def("setObjectName", &QObject::setObjectName)
      .def("setParent", py::overload_cast<QObject *>(&QObject::setParent))
      //   .def("setProperty", &QObject::setProperty)
      .def("signalsBlocked", &QObject::signalsBlocked)
      //   .def("startTimer", &QObject::startTimer)
      //   .def("thread", &QObject::thread)
      ;
}
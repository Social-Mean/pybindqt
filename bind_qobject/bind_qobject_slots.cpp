#include <pybind11/pybind11.h>

#include <QPushButton>

#include <QByteArray>
#include <QEvent>
#include <QList>
#include <QMetaMethod>
#include <QMetaObject>
#include <QObject>
#include <QObjectList>
#include <QThread>
#include <QTimer>
#include <QVariant>

#include <widgets_base.h>

namespace py = pybind11;

void bind_qobject_slots(py::class_<QObject> &cls) {
  cls.def("deleteLater", &QObject::deleteLater);
}
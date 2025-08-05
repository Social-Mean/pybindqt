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

void bind_qobject_properties(py::class_<QObject> &cls);
void bind_qobject_methods(py::class_<QObject> &cls);
void bind_qobject_slots(py::class_<QObject> &cls);
void bind_qobject_signals(py::class_<QObject> &cls);

void bind_qobject(py::module_ &m) {
    auto cls = py::class_<QObject>(m, "QObject");
    bind_qobject_properties(cls);
    bind_qobject_methods(cls);
    bind_qobject_slots(cls);
    bind_qobject_signals(cls);
}
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

void bind_qobject_properties(py::class_<QObject> &cls) {
  cls.def_property_readonly("objectName",
                            [](QObject *self) { return self->objectName(); });
}

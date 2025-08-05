#include <pybind11/pybind11.h>

#include <QWidget>
#include <QObject>

#include <widgets_base.h>

namespace py = pybind11;

void bind_qwidget_properties(py::class_<QWidget, QObject> &cls);
void bind_qwidget_methods(py::class_<QWidget, QObject> &cls);
void bind_qwidget_slots(py::class_<QWidget, QObject> &cls);
void bind_qwidget_signals(py::class_<QWidget, QObject> &cls);

void bind_qwidget(py::module_ &m) {
    auto cls = py::class_<QWidget, QObject>(m, "QWidget");
    bind_qwidget_properties(cls);
    bind_qwidget_methods(cls);
    bind_qwidget_slots(cls);
    bind_qwidget_signals(cls);
}
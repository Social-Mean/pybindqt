#include <pybind11/pybind11.h>

#include <QAbstractButton>
#include <QWidget>

#include <widgets_base.h>

namespace py = pybind11;

void bind_qabstractbutton_properties(py::class_<QAbstractButton, QWidget> &cls);
void bind_qabstractbutton_methods(py::class_<QAbstractButton, QWidget> &cls);
void bind_qabstractbutton_slots(py::class_<QAbstractButton, QWidget> &cls);
void bind_qabstractbutton_signals(py::class_<QAbstractButton, QWidget> &cls);

void bind_qabstractbutton(py::module_ &m) {
    auto cls = py::class_<QAbstractButton, QWidget>(m, "QAbstractButton");
    bind_qabstractbutton_properties(cls);
    bind_qabstractbutton_methods(cls);
    bind_qabstractbutton_slots(cls);
    bind_qabstractbutton_signals(cls);
}
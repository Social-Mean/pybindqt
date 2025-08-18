#include <widgets_base.h>

namespace py = pybind11;

void bind_qpushbutton_properties(py::class_<QPushButton, QAbstractButton> &cls);
void bind_qpushbutton_methods(py::class_<QPushButton, QAbstractButton> &cls);
void bind_qpushbutton_slots(py::class_<QPushButton, QAbstractButton> &cls);
void bind_qpushbutton_signals(py::class_<QPushButton, QAbstractButton> &cls);

void bind_qpushbutton(py::module_ &m) {
    auto cls = py::class_<QPushButton, QAbstractButton>(m, "QPushButton");
    bind_qpushbutton_properties(cls);
    bind_qpushbutton_methods(cls);
    bind_qpushbutton_slots(cls);
    bind_qpushbutton_signals(cls);
}
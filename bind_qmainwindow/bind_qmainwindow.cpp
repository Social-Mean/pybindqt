#include <widgets_base.h>

namespace py = pybind11;

void bind_qmainwindow_properties(py::class_<QMainWindow, QWidget> &cls);
void bind_qmainwindow_methods(py::class_<QMainWindow, QWidget> &cls);
void bind_qmainwindow_slots(py::class_<QMainWindow, QWidget> &cls);
void bind_qmainwindow_signals(py::class_<QMainWindow, QWidget> &cls);

void bind_qmainwindow(py::module_ &m) {
    auto cls = py::class_<QMainWindow, QWidget>(m, "QMainWindow");
    bind_qmainwindow_properties(cls);
    bind_qmainwindow_methods(cls);
    bind_qmainwindow_slots(cls);
    bind_qmainwindow_signals(cls);
}
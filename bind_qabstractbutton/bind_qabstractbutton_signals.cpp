#include <pybind11/pybind11.h>

#include <QAbstractButton>
#include <QWidget>

#include <widgets_base.h>

namespace py = pybind11;

void bind_qabstractbutton_signals(py::class_<QAbstractButton, QWidget> &cls) {
    cls.def_property_readonly(
           "clicked", [](QAbstractButton *self) { return Clicked(self); })
        .def_property_readonly(
            "pressed", [](QAbstractButton *self) { return Pressed(self); })
        .def_property_readonly(
            "released", [](QAbstractButton *self) { return Released(self); })
        .def_property_readonly(
            "toggled", [](QAbstractButton *self) { return Toggled(self); });
}
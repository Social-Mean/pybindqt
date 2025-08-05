#include <pybind11/pybind11.h>

#include <QWidget>
#include <QObject>

#include <widgets_base.h>

namespace py = pybind11;

void bind_qwidget_signals(py::class_<QWidget, QObject> &cls) {
    cls.def_property_readonly(
           "customContextMenuRequested",
           [](QWidget *self) { return CustomContextMenuRequested(self); })
        .def_property_readonly(
            "windowIconChanged",
            [](QWidget *self) { return WindowIconChanged(self); })
        .def_property_readonly(
            "windowIconTextChanged",
            [](QWidget *self) { return WindowIconTextChanged(self); })
        .def_property_readonly(
            "windowTitleChanged",
            [](QWidget *self) { return WindowTitleChanged(self); });
}
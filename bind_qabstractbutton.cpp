#include <pybind11/pybind11.h>

#include <QAbstractButton>
#include <QButtonGroup>
#include <qabstractbutton.h>

#include "widgets_base.h"

namespace py = pybind11;

void bind_qabstractbutton(py::module_ &m) {
    py::class_<QAbstractButton, QWidget>(m, "QAbstractButton")
        .def("autoExclusive", &QAbstractButton::autoExclusive)
        .def("autoRepeat", &QAbstractButton::autoRepeat)
        .def("autoRepeatDelay", &QAbstractButton::autoRepeatDelay)
        .def("autoRepeatInterval", &QAbstractButton::autoRepeatInterval)
        .def("group", &QAbstractButton::group)
        .def("icon", &QAbstractButton::icon)
        .def("iconSize", &QAbstractButton::iconSize)
        .def("isCheckable", &QAbstractButton::isCheckable)
        .def("isChecked", &QAbstractButton::isChecked)
        .def("isDown", &QAbstractButton::isDown)
        .def("setAutoExclusive", &QAbstractButton::setAutoExclusive)
        .def("setAutoRepeat", &QAbstractButton::setAutoRepeat)
        .def("setAutoRepeatDelay", &QAbstractButton::setAutoRepeatDelay)
        .def("setAutoRepeatInterval", &QAbstractButton::setAutoRepeatInterval)
        .def("setCheckable", &QAbstractButton::setCheckable)
        .def("setDown", &QAbstractButton::setDown)
        .def("setIcon", &QAbstractButton::setIcon)
        .def("setShortcut", &QAbstractButton::setShortcut)
        .def("setText", &QAbstractButton::setText)
        .def("shortcut", &QAbstractButton::shortcut)
        .def("text", &QAbstractButton::text)
        .def("animateClick", &QAbstractButton::animateClick)
        .def("click", &QAbstractButton::click)
        .def("setChecked", &QAbstractButton::setChecked)
        .def("setIconSize", &QAbstractButton::setIconSize)
        .def("toggle", &QAbstractButton::toggle)

        // 添加信号作为静态属性
        .def_property_readonly(
            "clicked", [](QAbstractButton *self) { return Clicked(self); })
        .def_property_readonly(
            "pressed", [](QAbstractButton *self) { return Pressed(self); })
        .def_property_readonly(
            "released", [](QAbstractButton *self) { return Released(self); })
        .def_property_readonly(
            "toggled", [](QAbstractButton *self) { return Toggled(self); });
}
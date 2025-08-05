#include <pybind11/pybind11.h>

#include <QButtonGroup>
#include <QAbstractButton>
#include <QWidget>

#include <widgets_base.h>

namespace py = pybind11;

void bind_qabstractbutton_methods(py::class_<QAbstractButton, QWidget> &cls) {
    cls.def("autoExclusive", &QAbstractButton::autoExclusive)
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
        .def("text", &QAbstractButton::text);
}

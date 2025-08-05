#include <pybind11/pybind11.h>

#include <QAbstractButton>
#include <QWidget>

#include <widgets_base.h>

namespace py = pybind11;

void bind_qabstractbutton_properties(py::class_<QAbstractButton, QWidget> &cls) {
    // cls.def_property("autoExclusive",
    //                  &QAbstractButton::autoExclusive,
    //                  &QAbstractButton::setAutoExclusive);
    // cls.def_property("autoRepeat",
    //                  &QAbstractButton::autoRepeat,
    //                  &QAbstractButton::setAutoRepeat);
    // cls.def_property("autoRepeatDelay",
    //                  &QAbstractButton::autoRepeatDelay,
    //                  &QAbstractButton::setAutoRepeatDelay);
    // cls.def_property("autoRepeatInterval",
    //                  &QAbstractButton::autoRepeatInterval,
    //                  &QAbstractButton::setAutoRepeatInterval);
    // cls.def_property("checkable",
    //                  &QAbstractButton::isCheckable,
    //                  &QAbstractButton::setCheckable);
    // cls.def_property("checked",
    //                  &QAbstractButton::isChecked,
    //                  &QAbstractButton::setChecked);
    // cls.def_property("down",
    //                  &QAbstractButton::isDown,
    //                  &QAbstractButton::setDown);
    // cls.def_property("icon",
    //                  &QAbstractButton::icon,
    //                  &QAbstractButton::setIcon);
    // cls.def_property("iconSize",
    //                  &QAbstractButton::iconSize,
    //                  &QAbstractButton::setIconSize);
    // cls.def_property("shortcut",
    //                  &QAbstractButton::shortcut,
    //                  &QAbstractButton::setShortcut);
    // cls.def_property("text",
    //                  &QAbstractButton::text,
    //                  &QAbstractButton::setText);
}
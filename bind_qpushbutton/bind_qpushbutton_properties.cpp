#include <widgets_base.h>

namespace py = pybind11;

void bind_qpushbutton_properties(py::class_<QPushButton, QAbstractButton> &cls) {
    // cls.def_property("autoDefault",
    //                  &QPushButton::autoDefault,
    //                  &QPushButton::setAutoDefault,
    //                  "Whether the button is an auto default button.");
    // cls.def_property("default",
    //                  &QPushButton::isDefault,
    //                  &QPushButton::setDefault,
    //                  "Whether the button is the default button.");
    // cls.def_property("flat",
    //                  &QPushButton::isFlat,
    //                  &QPushButton::setFlat,
    //                  "Whether the button is flat.");
}
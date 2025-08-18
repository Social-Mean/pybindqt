#include <widgets_base.h>

namespace py = pybind11;

void bind_qmainwindow_signals(py::class_<QMainWindow, QWidget> &cls) {
    cls.def_property_readonly(
           "iconSizeChanged",
           [](QMainWindow *self) { return IconSizeChanged(self); })
        .def_property_readonly("toolButtonStyleChanged", [](QMainWindow *self) {
            return ToolButtonStyleChanged(self);
        });
}
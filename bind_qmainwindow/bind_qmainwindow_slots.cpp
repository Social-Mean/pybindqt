#include <widgets_base.h>

namespace py = pybind11;

void bind_qmainwindow_slots(py::class_<QMainWindow, QWidget> &cls) {
    cls.def("setAnimated", &QMainWindow::setAnimated, py::arg("enabled"))
        .def("setDockNestingEnabled", &QMainWindow::setDockNestingEnabled,
             py::arg("enabled"))
        .def("setUnifiedTitleAndToolBarOnMac",
             &QMainWindow::setUnifiedTitleAndToolBarOnMac, py::arg("set"));
}
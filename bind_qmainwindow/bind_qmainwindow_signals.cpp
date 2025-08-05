#include <pybind11/pybind11.h>

#include <QDockWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QString>
#include <QToolBar>
#include <QWidget>
#include <Qt>

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
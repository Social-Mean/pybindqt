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

void bind_qmainwindow_slots(py::class_<QMainWindow, QWidget> &cls) {
  cls.def("setAnimated", &QMainWindow::setAnimated, py::arg("enabled"))
      .def("setDockNestingEnabled", &QMainWindow::setDockNestingEnabled,
           py::arg("enabled"))
      .def("setUnifiedTitleAndToolBarOnMac",
           &QMainWindow::setUnifiedTitleAndToolBarOnMac, py::arg("set"));
}
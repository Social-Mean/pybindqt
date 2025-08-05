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

void bind_qmainwindow_properties(py::class_<QMainWindow, QWidget> &cls) {

  //    cls.def_property("animated", &QMainWindow::isAnimated,
  //                  &QMainWindow::setAnimated)
  //    .def_property("dockNestingEnabled",
  //    &QMainWindow::isDockNestingEnabled,
  //                  &QMainWindow::setDockNestingEnabled)
  //    .def_property("dockOptions", &QMainWindow::dockOptions,
  //                  &QMainWindow::setDockOptions)
  //    .def_property("documentMode", &QMainWindow::documentMode,
  //                  &QMainWindow::setDocumentMode)
  //    .def_property("iconSize", &QMainWindow::iconSize,
  //                  &QMainWindow::setIconSize)
  //    .def_property("tabShape", &QMainWindow::tabShape,
  //                  &QMainWindow::setTabShape)
  //    .def_property("toolButtonStyle", &QMainWindow::toolButtonStyle,
  //                  &QMainWindow::setToolButtonStyle)
  //    .def_property("unifiedTitleAndToolBarOnMac",
  //                  &QMainWindow::unifiedTitleAndToolBarOnMac,
  //                  &QMainWindow::setUnifiedTitleAndToolBarOnMac)

  ;
}
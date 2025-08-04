#include <pybind11/pybind11.h>

#include <QMainWindow>
#include <QWidget>
namespace py = pybind11;

void bind_qmainwindow(py::module_ &m) {
  py::class_<QMainWindow, QWidget>(m, "QMainWindow")
      .def_property("animated", &QMainWindow::isAnimated,
                    &QMainWindow::setAnimated)
      .def_property("dockNestingEnabled", &QMainWindow::isDockNestingEnabled,
                    &QMainWindow::setDockNestingEnabled)
      .def_property("dockOptions", &QMainWindow::dockOptions,
                    &QMainWindow::setDockOptions)
      .def_property("documentMode", &QMainWindow::documentMode,
                    &QMainWindow::setDocumentMode)
      .def_property("iconSize", &QMainWindow::iconSize,
                    &QMainWindow::setIconSize)
      .def_property("tabShape", &QMainWindow::tabShape,
                    &QMainWindow::setTabShape)
      .def_property("toolButtonStyle", &QMainWindow::toolButtonStyle,
                    &QMainWindow::setToolButtonStyle)
      .def_property("unifiedTitleAndToolBarOnMac",
                    &QMainWindow::unifiedTitleAndToolBarOnMac,
                    &QMainWindow::setUnifiedTitleAndToolBarOnMac)
      .def(py::init([]() { return std::make_unique<QMainWindow>(); }))
      .def("show", &QMainWindow::show);
}
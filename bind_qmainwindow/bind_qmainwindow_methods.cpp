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

void bind_qmainwindow_methods(py::class_<QMainWindow, QWidget> &cls) {
    cls.def(py::init<QWidget *, Qt::WindowFlags>(), py::arg("parent") = nullptr,
            py::arg("flags") = Qt::WindowFlags())
        .def("show", &QMainWindow::show)
        .def("addDockWidget",
             py::overload_cast<Qt::DockWidgetArea, QDockWidget *>(
                 &QMainWindow::addDockWidget),
             py::arg("area"), py::arg("dockwidget"))
        .def(
            "addDockWidget",
            py::overload_cast<Qt::DockWidgetArea, QDockWidget *, Qt::Orientation>(
                &QMainWindow::addDockWidget),
            py::arg("area"), py::arg("dockwidget"), py::arg("orientation"))
        .def("addToolBar",
             py::overload_cast<Qt::ToolBarArea, QToolBar *>(
                 &QMainWindow::addToolBar),
             py::arg("area"), py::arg("toolbar"))
        .def("addToolBar",
             py::overload_cast<QToolBar *>(&QMainWindow::addToolBar),
             py::arg("toolbar"))
        .def("addToolBar",
             py::overload_cast<const QString &>(&QMainWindow::addToolBar),
             py::arg("title"))
        .def("addToolBarBreak", &QMainWindow::addToolBarBreak,
             py::arg("area") = Qt::TopToolBarArea)
        .def("centralWidget", &QMainWindow::centralWidget,
             py::return_value_policy::reference)
        .def("corner", &QMainWindow::corner)
        .def("createPopupMenu", &QMainWindow::createPopupMenu,
             py::return_value_policy::reference)
        .def("dockOptions", &QMainWindow::dockOptions)
        .def("dockWidgetArea", &QMainWindow::dockWidgetArea)
        .def("documentMode", &QMainWindow::documentMode)
        .def("iconSize", &QMainWindow::iconSize)
        .def("insertToolBar", &QMainWindow::insertToolBar)
        .def("insertToolBarBreak", &QMainWindow::insertToolBarBreak)
        .def("isAnimated", &QMainWindow::isAnimated)
        .def("isDockNestingEnabled", &QMainWindow::isDockNestingEnabled)
        .def("menuBar", &QMainWindow::menuBar, py::return_value_policy::reference)
        .def("menuWidget", &QMainWindow::menuWidget,
             py::return_value_policy::reference)
        .def("removeDockWidget", &QMainWindow::removeDockWidget)
        .def("removeToolBar", &QMainWindow::removeToolBar)
        .def("removeToolBarBreak", &QMainWindow::removeToolBarBreak)
        .def("restoreDockWidget", &QMainWindow::restoreDockWidget)
        .def("restoreState", &QMainWindow::restoreState, py::arg("state"),
             py::arg("version") = 0)
        .def("saveState", &QMainWindow::saveState, py::arg("version") = 0)
        .def("setCentralWidget", &QMainWindow::setCentralWidget)
        .def("setCorner", &QMainWindow::setCorner)
        .def("setDockOptions", &QMainWindow::setDockOptions)
        .def("setDocumentMode", &QMainWindow::setDocumentMode)
        .def("setIconSize", &QMainWindow::setIconSize)
        .def("setMenuBar", &QMainWindow::setMenuBar)
        .def("setMenuWidget", &QMainWindow::setMenuWidget)
        .def("setStatusBar", &QMainWindow::setStatusBar)
        .def("setTabPosition", &QMainWindow::setTabPosition)
        .def("setTabShape", &QMainWindow::setTabShape)
        .def("setToolButtonStyle", &QMainWindow::setToolButtonStyle)
        .def("splitDockWidget", &QMainWindow::splitDockWidget)
        .def("statusBar", &QMainWindow::statusBar,
             py::return_value_policy::reference)
        .def("tabPosition", &QMainWindow::tabPosition)
        .def("tabShape", &QMainWindow::tabShape)
        .def("tabifiedDockWidgets", &QMainWindow::tabifiedDockWidgets)
        .def("tabifyDockWidget", &QMainWindow::tabifyDockWidget)
        .def("takeCentralWidget", &QMainWindow::takeCentralWidget)
        .def("toolBarArea", &QMainWindow::toolBarArea)
        .def("toolBarBreak", &QMainWindow::toolBarBreak)
        .def("toolButtonStyle", &QMainWindow::toolButtonStyle)
        .def("unifiedTitleAndToolBarOnMac",
             &QMainWindow::unifiedTitleAndToolBarOnMac);
}
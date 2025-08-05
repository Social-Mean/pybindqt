#include <pybind11/pybind11.h>

#include <QWidget>
#include <QObject>

#include <widgets_base.h>

namespace py = pybind11;

void bind_qwidget_slots(py::class_<QWidget, QObject> &cls) {
    cls.def("close", &QWidget::close)
        .def("hide", &QWidget::hide)
        .def("lower", &QWidget::lower)
        .def("raise", &QWidget::raise)
        .def("repaint", py::overload_cast<>(&QWidget::repaint))
        .def("setDisabled", &QWidget::setDisabled)
        .def("setEnabled", &QWidget::setEnabled)
        .def("setFocus", py::overload_cast<>(&QWidget::setFocus))
        .def("setHidden", &QWidget::setHidden)
        .def("setStyleSheet", &QWidget::setStyleSheet)
        .def("setVisible", &QWidget::setVisible)
        .def("setWindowModified", &QWidget::setWindowModified)
        .def("setWindowTitle", &QWidget::setWindowTitle)
        .def("show", &QWidget::show)
        .def("showFullScreen", &QWidget::showFullScreen)
        .def("showMaximized", &QWidget::showMaximized)
        .def("showMinimized", &QWidget::showMinimized)
        .def("showNormal", &QWidget::showNormal)
        .def("showFullScreen", &QWidget::showFullScreen)
        .def("update", py::overload_cast<>(&QWidget::update));
}
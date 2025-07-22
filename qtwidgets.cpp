#include <pybind11/pybind11.h>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include "CustomPushButton.h"

namespace py = pybind11;

PYBIND11_MODULE(QtWidgets, m) {
    py::class_<QWidget>(m, "QWidget")
        .def("setParent", py::overload_cast<QWidget *>(&QWidget::setParent))
        .def("setParent", py::overload_cast<QWidget *, Qt::WindowFlags>(
                              &QWidget::setParent));

    py::class_<QApplication>(m, "QApplication")
        .def(py::init([](py::list args) {
            std::vector<QByteArray> argData;
            std::vector<char*> argPtrs;
            for (auto item : args) {
                argData.emplace_back(py::str(item).cast<std::string>().c_str());
                argPtrs.push_back(const_cast<char*>(argData.back().data()));
            }
            int argc = static_cast<int>(argPtrs.size());
            return std::make_unique<QApplication>(argc, argPtrs.data());
        }))
        .def("exec_", [](QApplication &self) { return self.exec(); });

    py::class_<QMainWindow, QWidget>(m, "QMainWindow")
        .def(py::init([]() { return std::make_unique<QMainWindow>(); }))
        .def("show", &QMainWindow::show);

    py::class_<CustomPushButton, QWidget>(m, "QPushButton")
        .def(py::init([]() { return std::make_unique<CustomPushButton>(); }))
        .def("setText", &CustomPushButton::setText)
        .def("show", &CustomPushButton::show)
        .def_readonly("clicked", &CustomPushButton::clicked);
}
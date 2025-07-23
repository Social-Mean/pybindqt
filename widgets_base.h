#pragma once
#include <pybind11/pybind11.h>
namespace py = pybind11;

void bind_qwidget(py::module_ &m);
void bind_qapplication(py::module_ &m);
void bind_qmainwindow(py::module_ &m);
void bind_qpushbutton(py::module_ &m);
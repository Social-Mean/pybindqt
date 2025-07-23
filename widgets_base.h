#pragma once
#include <pybind11/pybind11.h>
namespace py = pybind11;

void bind_widget(py::module_ &m);
void bind_application(py::module_ &m);
void bind_mainwindow(py::module_ &m);
void bind_pushbutton(py::module_ &m);
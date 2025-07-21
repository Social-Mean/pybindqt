#include <pybind11/pybind11.h>
#include <QApplication>
namespace py = pybind11;

int add(int i, int j) { return i + j; }

PYBIND11_MODULE(pybind11_test, m) {
    m.def("add", &add, "A function which adds two numbers");
}
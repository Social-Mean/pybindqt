#include <pybind11/pybind11.h>

#include <QButtonGroup>
#include <QMenu>
#include <QObject>
#include <QPushButton>
#include <QWidget>

#include <widgets_base.h>

namespace py = pybind11;

void bind_qpushbutton_slots(py::class_<QPushButton, QAbstractButton> &cls) {
    cls.def("showMenu", &QPushButton::showMenu);
}
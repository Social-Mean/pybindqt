#include <pybind11/pybind11.h>

#include <QButtonGroup>
#include <QMenu>
#include <QObject>
#include <QPushButton>
#include <QWidget>

#include <widgets_base.h>

namespace py = pybind11;

void bind_qpushbutton_signals(py::class_<QPushButton, QAbstractButton> &cls) {
}
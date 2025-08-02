#include <pybind11/pybind11.h>

#include <QObject>
#include <QPushButton>
#include <QWidget>

#include "signal.h"

namespace py = pybind11;

void bind_qpushbutton(py::module_ &m) {
  // 绑定Signal类
  py::class_<Signal>(m, "Signal")
      .def(py::init([](QObject *self) { return Signal(self); }))
      .def("connect", &Signal::connect);
  py::class_<Clicked, Signal>(m, "Clicked").def(py::init([](QPushButton *self) {
    return Clicked(self);
  }));

  py::class_<QPushButton, QWidget>(m, "QPushButton")
      .def(py::init([]() { return std::make_unique<QPushButton>(); }))
      .def(py::init([](QWidget *parent) {
        return std::make_unique<QPushButton>(parent);
      }))
      .def("show", &QPushButton::show)
      .def("setText",
           [](QPushButton *self, const std::string &text) {
             self->setText(QString::fromStdString(text));
           })
      .def("text", [](QPushButton *self) { return self->text().toStdString(); })
      .def("setGeometry", [](QPushButton *self, int x, int y, int w,
                             int h) { self->setGeometry(x, y, w, h); })
      // 添加clicked信号作为静态属性
      .def_property_readonly("clicked",
                             [](QPushButton *self) { return Clicked(self); });
}
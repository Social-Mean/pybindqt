#include <pybind11/pybind11.h>

#include <QButtonGroup>
#include <QMenu>
#include <QObject>
#include <QPushButton>
#include <QWidget>

#include "widgets_base.h"

namespace py = pybind11;

void bind_qpushbutton(py::module_ &m) {
  // 绑定Signal类
  py::class_<Signal>(m, "Signal")
      .def(py::init([](QObject *self) { return Signal(self); }))
      .def("connect", &Signal::connect);
  py::class_<Clicked, Signal>(m, "Clicked").def(py::init([](QPushButton *self) {
    return Clicked(self);
  }));

  py::class_<QPushButton, QAbstractButton>(m, "QPushButton")
      .def(py::init([](QWidget *parent) {
             return std::make_unique<QPushButton>(parent);
           }),
           py::arg("parent") = nullptr)
      .def(py::init([](const QString &text, QWidget *parent) {
             return std::make_unique<QPushButton>(text, parent);
           }),
           py::arg("text"), py::arg("parent") = nullptr)
      .def(
          py::init([](const QIcon &icon, const QString &text, QWidget *parent) {
            return std::make_unique<QPushButton>(icon, text, parent);
          }),
          py::arg("icon"), py::arg("text"), py::arg("parent") = nullptr)
      .def("autoDefault", &QPushButton::autoDefault)
      .def("isDefault", &QPushButton::isDefault)
      .def("isFlat", &QPushButton::isFlat)
      .def("menu", &QPushButton::menu)
      .def("setAutoDefault", &QPushButton::setAutoDefault)
      .def("setDefault", &QPushButton::setDefault)
      .def("setFlat", &QPushButton::setFlat)
      .def("setMenu", &QPushButton::setMenu)

      //   .def("minimumSizeHint", &QPushButton::minimumSizeHint)
      //   .def("sizeHint", &QPushButton::sizeHint)

      // 添加clicked信号作为静态属性
      .def_property_readonly("clicked",
                             [](QPushButton *self) { return Clicked(self); });
}
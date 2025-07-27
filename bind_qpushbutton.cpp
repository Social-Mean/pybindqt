#include <pybind11/pybind11.h>

#include <QObject>
#include <QPushButton>
#include <QWidget>

namespace py = pybind11;

// 简单的Signal包装类
class Signal {
public:
  Signal() = default;
};

void bind_qpushbutton(py::module_ &m) {
  // 绑定Signal类
  py::class_<Signal>(m, "Signal");

  py::class_<QPushButton, QWidget>(m, "QPushButton")
      .def(py::init([]() { return std::make_unique<QPushButton>(); }))
      .def("show", &QPushButton::show)
      .def("setText", &QPushButton::setText)
      .def("text", [](QPushButton *self) { return self->text().toStdString(); })
      .def("setGeometry", [](QPushButton *self, int x, int y, int w,
                             int h) { self->setGeometry(x, y, w, h); })
      // 添加clicked信号作为静态属性
      .def_property_readonly_static("clicked",
                                    [](py::object) { return Signal(); });
}
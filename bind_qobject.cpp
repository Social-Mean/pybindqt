#include <pybind11/functional.h>
#include <pybind11/pybind11.h>

#include <QMetaMethod>
#include <QObject>
#include <QPushButton>
#include <pybind11/pytypes.h>

namespace py = pybind11;

void bind_qobject(py::module_ &m) {
  py::class_<QObject>(m, "QObject")
      .def("setParent", py::overload_cast<QObject *>(&QObject::setParent))
      // 基本的connect重载 - 使用字符串信号和槽
      .def_static("connect",
                  [](const QObject *sender, const char *signal,
                     const QObject *receiver, const char *slot) {
                    auto type = Qt::AutoConnection;
                    QObject::connect(sender, signal, receiver, slot, type);
                    return;
                  })
      // 支持信号和lambda函数的connect
      .def_static("connect",
                  [](QObject *sender, py::object signal_obj, QObject *receiver,
                     py::function slot_func) {
                    // 这里我们假设signal_obj是clicked信号的引用
                    // 为了简化，我们直接连接QPushButton的clicked信号
                    if (auto *button = qobject_cast<QPushButton *>(sender)) {
                      QObject::connect(
                          button, &QPushButton::clicked,
                          [slot_func](bool checked) { slot_func(checked); });
                    }
                    return;
                  })
      // 支持信号和lambda函数的connect（不带receiver）
      .def_static("connect", [](QObject *sender, py::object signal_obj,
                                py::function slot_func) {
        // 这里我们假设signal_obj是clicked信号的引用
        if (auto *button = qobject_cast<QPushButton *>(sender)) {
          QObject::connect(button, &QPushButton::clicked,
                           [slot_func](bool checked) { slot_func(checked); });
        }
        return;
      });
}
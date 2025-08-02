#pragma once

#include <pybind11/pybind11.h>

#include <QObject>
#include <QPushButton>

namespace py = pybind11;

class Signal {
public:
  Signal(QObject *obj) { m_obj = obj; }
  virtual void connect(py::function slot_func) const {
    throw std::runtime_error("Not implemented");
  }
  QObject *get_obj() const { return m_obj; }

private:
  QObject *m_obj;
};

class Clicked : public Signal {
public:
  Clicked(QObject *obj) : Signal(obj) {}
  void connect(py::function slot_func) const override {
    QPushButton *button = qobject_cast<QPushButton *>(get_obj());
    if (button) {
      QObject::connect(button, &QPushButton::clicked,
                       [slot_func](bool checked) { slot_func(checked); });
    }
  }
};

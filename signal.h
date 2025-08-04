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

class Destroyed : public Signal {
public:
  Destroyed(QObject *obj) : Signal(obj) {}
  void connect(py::function slot_func) const override {
    QObject::connect(get_obj(), &QObject::destroyed, slot_func);
  }
};

class ObjectNameChanged : public Signal {
public:
  ObjectNameChanged(QObject *obj) : Signal(obj) {}
  void connect(py::function slot_func) const override {
    QObject::connect(get_obj(), &QObject::objectNameChanged, slot_func);
  }
};

class CustomContextMenuRequested : public Signal {
public:
  CustomContextMenuRequested(QObject *obj) : Signal(obj) {}
  void connect(py::function slot_func) const override {
    QWidget *widget = qobject_cast<QWidget *>(get_obj());
    if (widget) {
      QObject::connect(widget, &QWidget::customContextMenuRequested,
                       [slot_func](const QPoint &pos) { slot_func(pos); });
    }
  }
};

class WindowIconChanged : public Signal {
public:
  WindowIconChanged(QObject *obj) : Signal(obj) {}
  void connect(py::function slot_func) const override {
    QWidget *widget = qobject_cast<QWidget *>(get_obj());
    if (widget) {
      QObject::connect(widget, &QWidget::windowIconChanged,
                       [slot_func](const QIcon &icon) { slot_func(icon); });
    }
  }
};

class WindowIconTextChanged : public Signal {
public:
  WindowIconTextChanged(QObject *obj) : Signal(obj) {}
  void connect(py::function slot_func) const override {
    QWidget *widget = qobject_cast<QWidget *>(get_obj());
    if (widget) {
      QObject::connect(
          widget, &QWidget::windowIconTextChanged,
          [slot_func](const QString &iconText) { slot_func(iconText); });
    }
  }
};

class WindowTitleChanged : public Signal {
public:
  WindowTitleChanged(QObject *obj) : Signal(obj) {}
  void connect(py::function slot_func) const override {
    QWidget *widget = qobject_cast<QWidget *>(get_obj());
    if (widget) {
      QObject::connect(widget, &QWidget::windowTitleChanged,
                       [slot_func](const QString &title) { slot_func(title); });
    }
  }
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

class Pressed : public Signal {
public:
  Pressed(QObject *obj) : Signal(obj) {}
  void connect(py::function slot_func) const override {
    QPushButton *button = qobject_cast<QPushButton *>(get_obj());
    if (button) {
      QObject::connect(button, &QPushButton::pressed,
                       [slot_func]() { slot_func(); });
    }
  }
};

class Released : public Signal {
public:
  Released(QObject *obj) : Signal(obj) {}
  void connect(py::function slot_func) const override {
    QPushButton *button = qobject_cast<QPushButton *>(get_obj());
    if (button) {
      QObject::connect(button, &QPushButton::released,
                       [slot_func]() { slot_func(); });
    }
  }
};

class Toggled : public Signal {
public:
  Toggled(QObject *obj) : Signal(obj) {}
  void connect(py::function slot_func) const override {
    QPushButton *button = qobject_cast<QPushButton *>(get_obj());
    if (button) {
      QObject::connect(button, &QPushButton::toggled,
                       [slot_func](bool checked) { slot_func(checked); });
    }
  }
};

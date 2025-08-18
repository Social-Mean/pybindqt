#pragma once

namespace py = pybind11;

class Signal {
public:
    Signal(QObject *obj) {
        m_obj = obj;
    }
    virtual void connect(py::function slot_func) const {
        throw std::runtime_error("Not implemented");
    }
    QObject *get_obj() const {
        return m_obj;
    }

private:
    QObject *m_obj;
};

class Destroyed : public Signal {
public:
    Destroyed(QObject *obj) :
        Signal(obj) {
    }
    void connect(py::function slot_func) const override {
        QObject::connect(get_obj(), &QObject::destroyed, slot_func);
    }
};

class ObjectNameChanged : public Signal {
public:
    ObjectNameChanged(QObject *obj) :
        Signal(obj) {
    }
    void connect(py::function slot_func) const override {
        QObject::connect(get_obj(), &QObject::objectNameChanged, slot_func);
    }
};

class CustomContextMenuRequested : public Signal {
public:
    CustomContextMenuRequested(QWidget *obj) :
        Signal(obj) {
    }
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
    WindowIconChanged(QWidget *obj) :
        Signal(obj) {
    }
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
    WindowIconTextChanged(QWidget *obj) :
        Signal(obj) {
    }
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
    WindowTitleChanged(QWidget *obj) :
        Signal(obj) {
    }
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
    Clicked(QAbstractButton *obj) :
        Signal(obj) {
    }
    void connect(py::function slot_func) const override {
        QAbstractButton *button = qobject_cast<QAbstractButton *>(get_obj());
        if (button) {
            QObject::connect(button, &QAbstractButton::clicked,
                             [slot_func](bool checked) { slot_func(checked); });
        }
    }
};

class Pressed : public Signal {
public:
    Pressed(QAbstractButton *obj) :
        Signal(obj) {
    }
    void connect(py::function slot_func) const override {
        QAbstractButton *button = qobject_cast<QAbstractButton *>(get_obj());
        if (button) {
            QObject::connect(button, &QAbstractButton::pressed,
                             [slot_func]() { slot_func(); });
        }
    }
};

class Released : public Signal {
public:
    Released(QAbstractButton *obj) :
        Signal(obj) {
    }
    void connect(py::function slot_func) const override {
        QAbstractButton *button = qobject_cast<QAbstractButton *>(get_obj());
        if (button) {
            QObject::connect(button, &QAbstractButton::released,
                             [slot_func]() { slot_func(); });
        }
    }
};

class Toggled : public Signal {
public:
    Toggled(QAbstractButton *obj) :
        Signal(obj) {
    }
    void connect(py::function slot_func) const override {
        QAbstractButton *button = qobject_cast<QAbstractButton *>(get_obj());
        if (button) {
            QObject::connect(button, &QAbstractButton::toggled,
                             [slot_func](bool checked) { slot_func(checked); });
        }
    }
};

class IconSizeChanged : public Signal {
public:
    IconSizeChanged(QMainWindow *obj) :
        Signal(obj) {
    }
    void connect(py::function slot_func) const override {
        QMainWindow *mainWindow = qobject_cast<QMainWindow *>(get_obj());
        if (mainWindow) {
            QObject::connect(
                mainWindow, &QMainWindow::iconSizeChanged,
                [slot_func](const QSize &iconSize) { slot_func(iconSize); });
        }
    }
};

class ToolButtonStyleChanged : public Signal {
public:
    ToolButtonStyleChanged(QMainWindow *obj) :
        Signal(obj) {
    }
    void connect(py::function slot_func) const override {
        QMainWindow *mainWindow = qobject_cast<QMainWindow *>(get_obj());
        if (mainWindow) {
            QObject::connect(
                mainWindow, &QMainWindow::toolButtonStyleChanged,
                [slot_func](Qt::ToolButtonStyle style) { slot_func(style); });
        }
    }
};

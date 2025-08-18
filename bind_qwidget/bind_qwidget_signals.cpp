#include <widgets_base.h>

namespace py = pybind11;

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

void bind_qwidget_signals(py::class_<QWidget, QObject> &cls) {
    py::class_<CustomContextMenuRequested, Signal>(cls,
                                                   "CustomContextMenuRequested")
        .def(py::init(
            [](QWidget *self) { return CustomContextMenuRequested(self); }));

    py::class_<WindowIconChanged, Signal>(cls, "WindowIconChanged")
        .def(py::init([](QWidget *self) { return WindowIconChanged(self); }));

    py::class_<WindowIconTextChanged, Signal>(cls, "WindowIconTextChanged")
        .def(py::init([](QWidget *self) { return WindowIconTextChanged(self); }));

    py::class_<WindowTitleChanged, Signal>(cls, "WindowTitleChanged")
        .def(py::init([](QWidget *self) { return WindowTitleChanged(self); }));

    cls.def_property_readonly(
           "customContextMenuRequested",
           [](QWidget *self) { return CustomContextMenuRequested(self); })
        .def_property_readonly(
            "windowIconChanged",
            [](QWidget *self) { return WindowIconChanged(self); })
        .def_property_readonly(
            "windowIconTextChanged",
            [](QWidget *self) { return WindowIconTextChanged(self); })
        .def_property_readonly(
            "windowTitleChanged",
            [](QWidget *self) { return WindowTitleChanged(self); });
}
#include <widgets_base.h>

namespace py = pybind11;

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

void bind_qabstractbutton_signals(py::class_<QAbstractButton, QWidget> &cls) {
    py::class_<Clicked, Signal>(cls, "Clicked").def(py::init([](QPushButton *self) {
        return Clicked(self);
    }));

    py::class_<Pressed, Signal>(cls, "Pressed").def(py::init([](QPushButton *self) {
        return Pressed(self);
    }));

    py::class_<Released, Signal>(cls, "Released")
        .def(py::init([](QPushButton *self) { return Released(self); }));

    py::class_<Toggled, Signal>(cls, "Toggled").def(py::init([](QPushButton *self) {
        return Toggled(self);
    }));

    cls.def_property_readonly(
           "clicked", [](QAbstractButton *self) { return Clicked(self); })
        .def_property_readonly(
            "pressed", [](QAbstractButton *self) { return Pressed(self); })
        .def_property_readonly(
            "released", [](QAbstractButton *self) { return Released(self); })
        .def_property_readonly(
            "toggled", [](QAbstractButton *self) { return Toggled(self); });
}
#include <widgets_base.h>

namespace py = pybind11;

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

void bind_qobject_signals(py::class_<QObject> &cls) {
    py::class_<Destroyed, Signal>(cls, "Destroyed").def(py::init([](QObject *self) {
        return Destroyed(self);
    }));

    py::class_<ObjectNameChanged, Signal>(cls, "ObjectNameChanged")
        .def(py::init([](QObject *self) { return ObjectNameChanged(self); }));

    cls.def_property_readonly("destroyed",
                              [](QObject *self) { return Destroyed(self); })
        .def_property_readonly("objectNameChanged", [](QObject *self) {
            return ObjectNameChanged(self);
        });
}
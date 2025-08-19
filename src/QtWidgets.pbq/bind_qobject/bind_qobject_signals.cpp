namespace py = pybind11;

class Destroyed : public Signal {
    PBQ_SIGNAL(Destroyed, QObject)
    void connect(py::function slot_func) const override {
        QObject::connect(get_obj(), &QObject::destroyed, slot_func);
    }
};

class ObjectNameChanged : public Signal {
    PBQ_SIGNAL(ObjectNameChanged, QObject)
    void connect(py::function slot_func) const override {
        QObject::connect(get_obj(), &QObject::objectNameChanged, slot_func);
    }
};

void bind_qobject_signals(py::class_<QObject> &cls) {
    PBQ_BIND_SIGNAL(QObject, Destroyed, ObjectNameChanged);
}
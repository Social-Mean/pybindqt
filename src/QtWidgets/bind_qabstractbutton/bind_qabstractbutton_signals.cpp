namespace py = pybind11;

class Clicked : public Signal {
    PBQ_SIGNAL(Clicked, QAbstractButton)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QAbstractButton *>(get_obj());
        QObject::connect(obj, &QAbstractButton::clicked,
                         [slot_func](bool checked) { slot_func(checked); });
    }
};

class Pressed : public Signal {
    PBQ_SIGNAL(Pressed, QAbstractButton)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QAbstractButton *>(get_obj());
        QObject::connect(obj, &QAbstractButton::pressed,
                         [slot_func]() { slot_func(); });
    }
};

class Released : public Signal {
    PBQ_SIGNAL(Released, QAbstractButton)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QAbstractButton *>(get_obj());
        QObject::connect(obj, &QAbstractButton::released,
                         [slot_func]() { slot_func(); });
    }
};

class Toggled : public Signal {
    PBQ_SIGNAL(Toggled, QAbstractButton)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QAbstractButton *>(get_obj());
        QObject::connect(obj, &QAbstractButton::toggled,
                         [slot_func](bool checked) { slot_func(checked); });
    }
};

void bind_qabstractbutton_signals(py::class_<QAbstractButton, QWidget> &cls) {
    PBQ_BIND_SIGNAL(QAbstractButton,
                    Clicked, Pressed, Released, Toggled);
}
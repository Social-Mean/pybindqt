namespace py = pybind11;

class FocusChanged : public Signal {
    PBQ_SIGNAL(FocusChanged, QApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QApplication *>(get_obj());
        QObject::connect(
            obj, &QApplication::focusChanged,
            [slot_func](QWidget *old, QWidget *now) { slot_func(old, now); });
    }
};

void bind_qapplication_signals(py::class_<QApplication, QGuiApplication> &cls) {
    PBQ_BIND_SIGNAL(QApplication, FocusChanged);
}

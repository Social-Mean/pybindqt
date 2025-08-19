namespace py = pybind11;

void bind_qapplication_properties(py::class_<QApplication, QGuiApplication> &cls);
void bind_qapplication_methods(py::class_<QApplication, QGuiApplication> &cls);
void bind_qapplication_slots(py::class_<QApplication, QGuiApplication> &cls);
void bind_qapplication_signals(py::class_<QApplication, QGuiApplication> &cls);

void bind_qapplication(py::module_ &m) {
    auto cls = py::class_<QApplication, QGuiApplication>(m, "QApplication");
    bind_qapplication_properties(cls);
    bind_qapplication_methods(cls);
    bind_qapplication_slots(cls);
    bind_qapplication_signals(cls);
}
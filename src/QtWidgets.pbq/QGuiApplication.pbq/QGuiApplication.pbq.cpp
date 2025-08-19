namespace py = pybind11;

void bind_qguiapplication_properties(py::class_<QGuiApplication, QCoreApplication> &cls);
void bind_qguiapplication_methods(py::class_<QGuiApplication, QCoreApplication> &cls);
void bind_qguiapplication_slots(py::class_<QGuiApplication, QCoreApplication> &cls);
void bind_qguiapplication_signals(py::class_<QGuiApplication, QCoreApplication> &cls);

void bind_qguiapplication(py::module_ &m) {
    auto cls = py::class_<QGuiApplication, QCoreApplication>(m, "QGuiApplication");
    bind_qguiapplication_properties(cls);
    bind_qguiapplication_methods(cls);
    bind_qguiapplication_slots(cls);
    bind_qguiapplication_signals(cls);
}
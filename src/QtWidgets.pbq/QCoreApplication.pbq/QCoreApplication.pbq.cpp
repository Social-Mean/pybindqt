namespace py = pybind11;

void bind_qcoreapplication_properties(py::class_<QCoreApplication, QObject> &cls);
void bind_qcoreapplication_methods(py::class_<QCoreApplication, QObject> &cls);
void bind_qcoreapplication_slots(py::class_<QCoreApplication, QObject> &cls);
void bind_qcoreapplication_signals(py::class_<QCoreApplication, QObject> &cls);

void bind_qcoreapplication(py::module_ &m) {
    auto cls = py::class_<QCoreApplication, QObject>(m, "QCoreApplication");
    bind_qcoreapplication_properties(cls);
    bind_qcoreapplication_methods(cls);
    bind_qcoreapplication_slots(cls);
    bind_qcoreapplication_signals(cls);
}
namespace py = pybind11;

void bind_qcoreapplication_slots(py::class_<QCoreApplication, QObject> &cls) {
    cls.def("quit", &QCoreApplication::quit);
}
namespace py = pybind11;

void bind_qobject_slots(py::class_<QObject> &cls) {
    cls.def("deleteLater", &QObject::deleteLater);
}
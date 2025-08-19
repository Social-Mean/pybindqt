namespace py = pybind11;

void bind_signal(py::module_ &m);
void bind_qflags(py::module_ &m);
void bind_qstring(py::module_ &m);
void bind_enum(py::module_ &m);

PYBIND11_MODULE(QtCore, m) {
    bind_signal(m);
    bind_qflags(m);
    bind_qstring(m);
    bind_enum(m);
}
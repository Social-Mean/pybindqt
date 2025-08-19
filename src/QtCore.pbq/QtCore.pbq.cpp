namespace py = pybind11;

void bind_qobject(py::module_ &m);
void bind_signal(py::module_ &m);
void bind_qflags(py::module_ &m);
void bind_qstring(py::module_ &m);
void bind_enum(py::module_ &m);

PYBIND11_MODULE(QtCore, m) {
    bind_signal(m); // signal 需要第一个绑定
    bind_enum(m);
    bind_qobject(m);
    bind_qflags(m);
    bind_qstring(m);
}
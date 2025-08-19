namespace py = pybind11;

void bind_enum(py::module_ &m);

PYBIND11_MODULE(QtCore, m) {
    bind_enum(m);
}
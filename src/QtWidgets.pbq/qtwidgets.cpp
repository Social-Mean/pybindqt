namespace py = pybind11;

void bind_qcoreapplication(py::module_ &m);
void bind_qguiapplication(py::module_ &m);
void bind_qwidget(py::module_ &m);
void bind_qapplication(py::module_ &m);
void bind_qmainwindow(py::module_ &m);
void bind_qabstractbutton(py::module_ &m);
void bind_qpushbutton(py::module_ &m);
void bind_qframe(py::module_ &m);
void bind_qlabel(py::module_ &m);

PYBIND11_MODULE(QtWidgets, m) {
    bind_qwidget(m);
    bind_qcoreapplication(m);
    bind_qguiapplication(m);
    bind_qapplication(m);
    bind_qmainwindow(m);
    bind_qabstractbutton(m);
    bind_qpushbutton(m);
    bind_qframe(m);
    bind_qlabel(m);
}
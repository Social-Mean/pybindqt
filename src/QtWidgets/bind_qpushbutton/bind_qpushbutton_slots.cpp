namespace py = pybind11;

void bind_qpushbutton_slots(py::class_<QPushButton, QAbstractButton> &cls) {
    cls.def("showMenu", &QPushButton::showMenu);
}
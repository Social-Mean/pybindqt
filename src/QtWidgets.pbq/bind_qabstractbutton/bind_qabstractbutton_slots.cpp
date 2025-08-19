namespace py = pybind11;

void bind_qabstractbutton_slots(py::class_<QAbstractButton, QWidget> &cls) {
    cls.def("animateClick", &QAbstractButton::animateClick)
        .def("click", &QAbstractButton::click)
        .def("setChecked", &QAbstractButton::setChecked)
        .def("setIconSize", &QAbstractButton::setIconSize)
        .def("toggle", &QAbstractButton::toggle);
}

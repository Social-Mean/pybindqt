

void bind_qframe(py::module_ &m) {
    auto cls = py::class_<QFrame, QWidget>(m, "QFrame");

    // cls.def_property_readonly("frameRect", &QFrame::frameRect)
    //     .def_property("frameShadow", &QFrame::frameShadow, &QFrame::setFrameShadow)
    //     .def_property("frameShape", &QFrame::frameShape, &QFrame::setFrameShape)
    //     .def_property_readonly("frameWidth", &QFrame::frameWidth)
    //     .def_property("lineWidth", &QFrame::lineWidth, &QFrame::setLineWidth)
    //     .def_property("midLineWidth", &QFrame::midLineWidth, &QFrame::setMidLineWidth);

    cls.def(py::init<QWidget *, Qt::WindowFlags>(), py::arg("parent") = nullptr, py::arg("f") = Qt::WindowFlags())
        .def("frameRect", &QFrame::frameRect)
        .def("frameShadow", &QFrame::frameShadow)
        .def("frameShape", &QFrame::frameShape)
        .def("frameStyle", &QFrame::frameStyle)
        .def("frameWidth", &QFrame::frameWidth)
        .def("lineWidth", &QFrame::lineWidth)
        .def("midLineWidth", &QFrame::midLineWidth)
        .def("setFrameRect", &QFrame::setFrameRect)
        .def("setFrameShadow", &QFrame::setFrameShadow)
        .def("setFrameShape", &QFrame::setFrameShape)
        .def("setFrameStyle", &QFrame::setFrameStyle)
        .def("setLineWidth", &QFrame::setLineWidth)
        .def("setMidLineWidth", &QFrame::setMidLineWidth);
}
void bind_qpoint(py::module_ &m) {
    auto cls = py::class_<QPoint>(m, "QPoint");

    cls
        .def(py::init<>())
        .def(py::init<int, int>())
        .def("isNull", &QPoint::isNull)
        .def("manhattanLength", &QPoint::manhattanLength)
        .def("rx", &QPoint::rx, py::return_value_policy::reference_internal)
        .def("ry", &QPoint::ry, py::return_value_policy::reference_internal)
        .def("setX", &QPoint::setX)
        .def("setY", &QPoint::setY)
        // .def("toCGPoint", &QPoint::toCGPoint)
        .def("transposed", &QPoint::transposed)
        .def("x", &QPoint::x)
        .def("y", &QPoint::y)
        .def("__imul__", py::overload_cast<float>(&QPoint::operator*=), py::is_operator())
        .def("__imul__", py::overload_cast<double>(&QPoint::operator*=), py::is_operator())
        .def("__imul__", py::overload_cast<int>(&QPoint::operator*=), py::is_operator())
        .def("__iadd__", &QPoint::operator+=, py::is_operator())
        .def("__isub__", &QPoint::operator-=, py::is_operator())
        .def("__itruediv__", &QPoint::operator/=, py::is_operator());

    cls.def_static("dotProduct", &QPoint::dotProduct);
    // 绑定QPoint的全局运算符
    cls
        .def(py::self != py::self)
        .def(py::self == py::self)
        .def(py::self + py::self)
        .def(+py::self)
        .def(py::self - py::self)
        .def(-py::self)
        .def(py::self * float())
        .def(float() * py::self)
        .def(py::self * double())
        .def(double() * py::self)
        .def(py::self * int())
        .def(int() * py::self)
        .def(py::self / float())
        .def(py::self / double());

    // QDataStream << >> 绑定（可选，通常不直接暴露到Python，除非有特殊需求）
    // 如需绑定QDataStream相关操作，可在此处补充实现
}
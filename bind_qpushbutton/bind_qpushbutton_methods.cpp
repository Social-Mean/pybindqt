#include <widgets_base.h>

void bind_qpushbutton_methods(py::class_<QPushButton, QAbstractButton> &cls) {
    cls.def(py::init([](QWidget *parent) {
                return std::make_unique<QPushButton>(parent);
            }),
            py::arg("parent") = nullptr)
        .def(py::init([](const QString &text, QWidget *parent) {
                 return std::make_unique<QPushButton>(text, parent);
             }),
             py::arg("text"), py::arg("parent") = nullptr)
        .def(
            py::init([](const QIcon &icon, const QString &text, QWidget *parent) {
                return std::make_unique<QPushButton>(icon, text, parent);
            }),
            py::arg("icon"), py::arg("text"), py::arg("parent") = nullptr)
        .def("autoDefault", &QPushButton::autoDefault)
        .def("isDefault", &QPushButton::isDefault)
        .def("isFlat", &QPushButton::isFlat)
        .def("menu", &QPushButton::menu)
        .def("setAutoDefault", &QPushButton::setAutoDefault)
        .def("setDefault", &QPushButton::setDefault)
        .def("setFlat", &QPushButton::setFlat)
        .def("setMenu", &QPushButton::setMenu)
        //   .def("minimumSizeHint", &QPushButton::minimumSizeHint)
        //   .def("sizeHint", &QPushButton::sizeHint)
        ;
}
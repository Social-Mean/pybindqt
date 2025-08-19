namespace py = pybind11;

void bind_qapplication_slots(py::class_<QApplication, QGuiApplication> &cls) {
    cls.def("aboutQt", &QApplication::aboutQt);
    cls.def("autoSipEnabled", &QApplication::autoSipEnabled);
    cls.def("closeAllWindows", &QApplication::closeAllWindows);
    cls.def("setAutoSipEnabled", &QApplication::setAutoSipEnabled, py::arg("enabled"));
    cls.def("setStyleSheet", &QApplication::setStyleSheet, py::arg("sheet"));
}
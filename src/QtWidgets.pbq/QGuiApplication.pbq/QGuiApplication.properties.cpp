
namespace py = pybind11;

void bind_qguiapplication_properties(py::class_<QGuiApplication, QCoreApplication> &cls) {
    // cls.def_property(
    //        "applicationDisplayName",
    //        &QGuiApplication::applicationDisplayName,
    //        &QGuiApplication::setApplicationDisplayName)
    //     .def_property(
    //         "desktopFileName",
    //         &QGuiApplication::desktopFileName,
    //         &QGuiApplication::setDesktopFileName)
    //     .def_property(
    //         "layoutDirection",
    //         &QGuiApplication::layoutDirection,
    //         &QGuiApplication::setLayoutDirection)
    //     .def_property_readonly(
    //         "platformName",
    //         &QGuiApplication::platformName)
    //     .def_property_readonly(
    //         "primaryScreen",
    //         &QGuiApplication::primaryScreen, py::return_value_policy::reference)
    //     .def_property(
    //         "quitOnLastWindowClosed",
    //         &QGuiApplication::quitOnLastWindowClosed,
    //         &QGuiApplication::setQuitOnLastWindowClosed)
    //     .def_property(
    //         "windowIcon",
    //         &QGuiApplication::windowIcon,
    //         &QGuiApplication::setWindowIcon)
    ;
}
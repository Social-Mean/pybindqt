
namespace py = pybind11;

void bind_qcoreapplication_properties(py::class_<QCoreApplication, QObject> &cls) {
    // cls.def_property(
    //        "applicationName",
    //        &QCoreApplication::applicationName,
    //        &QCoreApplication::setApplicationName)
    //     .def_property(
    //         "applicationVersion",
    //         &QCoreApplication::applicationVersion,
    //         &QCoreApplication::setApplicationVersion)
    //     .def_property(
    //         "organizationDomain",
    //         &QCoreApplication::organizationDomain,
    //         &QCoreApplication::setOrganizationDomain)
    //     .def_property(
    //         "organizationName",
    //         &QCoreApplication::organizationName,
    //         &QCoreApplication::setOrganizationName)
    ;
}
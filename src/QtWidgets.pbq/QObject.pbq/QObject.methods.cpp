namespace py = pybind11;

void bind_qobject_methods(py::class_<QObject> &cls) {
    cls.def(py::init([](QObject *parent) { return std::make_unique<QObject>(parent); }), py::arg("parent") = nullptr)
        .def("blockSignals", &QObject::blockSignals)
        .def("children", &QObject::children)
        //   .def("connect",
        //        py::overload_cast<const QObject *, const char *, const char *,
        //                          Qt::ConnectionType>(&QObject::connect),
        //        py::arg("sender"), py::arg("signal"), py::arg("receiver"),
        //        py::arg("type") = Qt::AutoConnection)
        // .def("disconnect",
        //      py::overload_cast<const char *, const QObject *, const char *>(
        //          &QObject::disconnect),
        //      py::arg("signal") = 0, py::arg("receiver") = 0,
        //      py::arg("method") = 0)
        // .def("disconnect",
        //      py::overload_cast<const QObject *, const char *>(
        //          &QObject::disconnect),
        //      py::arg("receiver"), py::arg("method") = 0)
        .def("dumpObjectInfo", py::overload_cast<>(&QObject::dumpObjectInfo))
        .def("dumpObjectTree", py::overload_cast<>(&QObject::dumpObjectTree))
        .def("dynamicPropertyNames", &QObject::dynamicPropertyNames)
        .def("event", &QObject::event)
        .def("eventFilter", &QObject::eventFilter)
        // .def("findChild", &QObject::findChild)
        //   .def("findChildren", &QObject::findChildren)  // 有重载
        .def("inherits", &QObject::inherits)
        .def("installEventFilter", &QObject::installEventFilter)
        .def("isWidgetType", &QObject::isWidgetType)
        .def("isWindowType", &QObject::isWindowType)
        .def("killTimer", &QObject::killTimer)
        .def("metaObject", &QObject::metaObject)
        .def("moveToThread", &QObject::moveToThread)
        .def("parent", &QObject::parent)
        .def("property", &QObject::property)
        .def("removeEventFilter", &QObject::removeEventFilter)
        .def("setObjectName", &QObject::setObjectName)
        .def("setParent", py::overload_cast<QObject *>(&QObject::setParent))
        .def("setProperty", &QObject::setProperty)
        .def("signalsBlocked", &QObject::signalsBlocked)
        .def("startTimer",
             py::overload_cast<int, Qt::TimerType>(&QObject::startTimer),
             py::arg("interval"),
             py::arg("timerType") = Qt::CoarseTimer)
        .def("thread", &QObject::thread);
}

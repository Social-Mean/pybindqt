#include <PyQObject.hpp>

class Destroyed : public Signal {
    PBQ_SIGNAL(Destroyed, QObject)
    void connect(py::function slot_func) const override {
        QObject::connect(get_obj(), &QObject::destroyed, slot_func);
    }
};

class ObjectNameChanged : public Signal {
    PBQ_SIGNAL(ObjectNameChanged, QObject)
    void connect(py::function slot_func) const override {
        QObject::connect(get_obj(), &QObject::objectNameChanged, slot_func);
    }
};

void bind_qobject(py::module_ &m) {
    auto cls = py::class_<QObject, PyQObject<>, py::smart_holder>(m, "QObject");
    cls.def_property_readonly("objectName",
                              [](QObject *self) { return self->objectName(); });
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

    cls.def("deleteLater", &QObject::deleteLater);

    cls.def("childEvent", &QObject::childEvent);
    cls.def("connectNotify", &QObject::connectNotify);
    cls.def("customEvent", &QObject::customEvent);
    cls.def("disconnectNotify", &QObject::disconnectNotify);
    // cls.def("isSignalConnected", &QObject::isSignalConnected);
    // cls.def("receivers", &QObject::receivers);
    // cls.def("sender", &QObject::sender);
    // cls.def("senderSignalIndex", &QObject::senderSignalIndex);
    cls.def("timerEvent", &QObject::timerEvent);

    PBQ_BIND_SIGNAL(QObject, Destroyed, ObjectNameChanged);
}
namespace py = pybind11;

class AboutToQuit : public Signal {
    PBQ_SIGNAL(AboutToQuit, QCoreApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QCoreApplication *>(get_obj());
        QObject::connect(
            obj, &QCoreApplication::aboutToQuit,
            [slot_func]() { slot_func(); });
    }
};

class ApplicationNameChanged : public Signal {
    PBQ_SIGNAL(ApplicationNameChanged, QCoreApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QCoreApplication *>(get_obj());
        QObject::connect(
            obj, &QCoreApplication::applicationNameChanged,
            [slot_func]() { slot_func(); });
    }
};

class ApplicationVersionChanged : public Signal {
    PBQ_SIGNAL(ApplicationVersionChanged, QCoreApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QCoreApplication *>(get_obj());
        QObject::connect(
            obj, &QCoreApplication::applicationVersionChanged,
            [slot_func]() { slot_func(); });
    }
};

class OrganizationDomainChanged : public Signal {
    PBQ_SIGNAL(OrganizationDomainChanged, QCoreApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QCoreApplication *>(get_obj());
        QObject::connect(
            obj, &QCoreApplication::organizationDomainChanged,
            [slot_func]() { slot_func(); });
    }
};

class OrganizationNameChanged : public Signal {
    PBQ_SIGNAL(OrganizationNameChanged, QCoreApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QCoreApplication *>(get_obj());
        QObject::connect(
            obj, &QCoreApplication::organizationNameChanged,
            [slot_func]() { slot_func(); });
    }
};

void bind_qcoreapplication_signals(py::class_<QCoreApplication, QObject> &cls) {
    PBQ_BIND_SIGNAL(QCoreApplication, AboutToQuit, ApplicationNameChanged, ApplicationVersionChanged, OrganizationDomainChanged, OrganizationNameChanged);
}
namespace py = pybind11;

class ApplicationDisplayNameChanged : public Signal {
    PBQ_SIGNAL(ApplicationDisplayNameChanged, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::applicationDisplayNameChanged,
            [slot_func]() { slot_func(); });
    }
};

class ApplicationStateChanged : public Signal {
    PBQ_SIGNAL(ApplicationStateChanged, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::applicationStateChanged,
            [slot_func](Qt::ApplicationState state) { slot_func(state); });
    }
};

class CommitDataRequest : public Signal {
    PBQ_SIGNAL(CommitDataRequest, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::commitDataRequest,
            [slot_func](QSessionManager &manager) { slot_func(manager); });
    }
};

class FocusObjectChanged : public Signal {
    PBQ_SIGNAL(FocusObjectChanged, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::focusObjectChanged,
            [slot_func](QObject *focusObject) { slot_func(focusObject); });
    }
};

class FocusWindowChanged : public Signal {
    PBQ_SIGNAL(FocusWindowChanged, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::focusWindowChanged,
            [slot_func](QWindow *focusWindow) { slot_func(focusWindow); });
    }
};

class FontChanged : public Signal {
    PBQ_SIGNAL(FontChanged, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::fontChanged,
            [slot_func](const QFont &font) { slot_func(font); });
    }
};

class FontDatabaseChanged : public Signal {
    PBQ_SIGNAL(FontDatabaseChanged, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::fontDatabaseChanged,
            [slot_func]() { slot_func(); });
    }
};

class LastWindowClosed : public Signal {
    PBQ_SIGNAL(LastWindowClosed, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::lastWindowClosed,
            [slot_func]() { slot_func(); });
    }
};

class LayoutDirectionChanged : public Signal {
    PBQ_SIGNAL(LayoutDirectionChanged, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::layoutDirectionChanged,
            [slot_func](Qt::LayoutDirection direction) { slot_func(direction); });
    }
};

class PaletteChanged : public Signal {
    PBQ_SIGNAL(PaletteChanged, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::paletteChanged,
            [slot_func](const QPalette &palette) { slot_func(palette); });
    }
};

class PrimaryScreenChanged : public Signal {
    PBQ_SIGNAL(PrimaryScreenChanged, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::primaryScreenChanged,
            [slot_func](QScreen *screen) { slot_func(screen); });
    }
};

class SaveStateRequest : public Signal {
    PBQ_SIGNAL(SaveStateRequest, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::saveStateRequest,
            [slot_func](QSessionManager &manager) { slot_func(manager); });
    }
};

class ScreenAdded : public Signal {
    PBQ_SIGNAL(ScreenAdded, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::screenAdded,
            [slot_func](QScreen *screen) { slot_func(screen); });
    }
};

class ScreenRemoved : public Signal {
    PBQ_SIGNAL(ScreenRemoved, QGuiApplication)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QGuiApplication *>(get_obj());
        QObject::connect(
            obj, &QGuiApplication::screenRemoved,
            [slot_func](QScreen *screen) { slot_func(screen); });
    }
};

void bind_qguiapplication_signals(py::class_<QGuiApplication, QCoreApplication> &cls) {
    PBQ_BIND_SIGNAL(QGuiApplication,
                    ApplicationDisplayNameChanged,
                    ApplicationStateChanged,
                    CommitDataRequest,
                    FocusObjectChanged,
                    FocusWindowChanged,
                    FontChanged,
                    FontDatabaseChanged,
                    LastWindowClosed,
                    LayoutDirectionChanged,
                    PaletteChanged,
                    PrimaryScreenChanged,
                    SaveStateRequest,
                    ScreenAdded,
                    ScreenRemoved);
}

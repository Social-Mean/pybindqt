namespace py = pybind11;

void bind_qguiapplication_methods(py::class_<QGuiApplication, QCoreApplication> &cls) {
    // QGuiApplication 构造函数绑定
    cls.def(py::init([](py::list args) {
                static std::vector<std::string> storage;
                static std::vector<char *> argv;
                storage.clear();
                argv.clear();
                for (auto item : args) {
                    storage.push_back(py::cast<std::string>(item));
                }
                for (auto &s : storage) {
                    argv.push_back(const_cast<char *>(s.c_str()));
                }
                int argc = static_cast<int>(argv.size());
                return new QGuiApplication(argc, argv.data());
            }),
            py::arg("args"));

    // 析构函数无需显式绑定，pybind11会自动处理

    // 绑定成员方法
    cls.def("devicePixelRatio", &QGuiApplication::devicePixelRatio);
    cls.def("isSavingSession", &QGuiApplication::isSavingSession);
    cls.def("isSessionRestored", &QGuiApplication::isSessionRestored);
    cls.def("sessionId", &QGuiApplication::sessionId);
    cls.def("sessionKey", &QGuiApplication::sessionKey);

    // 绑定 QCoreApplication 的静态方法和部分成员方法
    // 绑定 QGuiApplication 的静态方法和部分成员方法
    cls.def_static("allWindows", &QGuiApplication::allWindows);
    cls.def_static("applicationDisplayName", &QGuiApplication::applicationDisplayName);
    cls.def_static("applicationState", &QGuiApplication::applicationState);
    cls.def_static("changeOverrideCursor", &QGuiApplication::changeOverrideCursor, py::arg("cursor"));
    cls.def_static("clipboard", &QGuiApplication::clipboard, py::return_value_policy::reference);
    cls.def_static("desktopFileName", &QGuiApplication::desktopFileName);
    cls.def_static("desktopSettingsAware", &QGuiApplication::desktopSettingsAware);
    cls.def_static("exec", &QGuiApplication::exec);
    cls.def_static("focusObject", &QGuiApplication::focusObject, py::return_value_policy::reference);
    cls.def_static("focusWindow", &QGuiApplication::focusWindow, py::return_value_policy::reference);
    cls.def_static("font", &QGuiApplication::font);
    cls.def_static("highDpiScaleFactorRoundingPolicy", &QGuiApplication::highDpiScaleFactorRoundingPolicy);
    cls.def_static("inputMethod", &QGuiApplication::inputMethod, py::return_value_policy::reference);
    cls.def_static("isFallbackSessionManagementEnabled", &QGuiApplication::isFallbackSessionManagementEnabled);
    cls.def_static("isLeftToRight", &QGuiApplication::isLeftToRight);
    cls.def_static("isRightToLeft", &QGuiApplication::isRightToLeft);
    cls.def_static("keyboardModifiers", &QGuiApplication::keyboardModifiers);
    cls.def_static("layoutDirection", &QGuiApplication::layoutDirection);
    cls.def_static("modalWindow", &QGuiApplication::modalWindow, py::return_value_policy::reference);
    cls.def_static("mouseButtons", &QGuiApplication::mouseButtons);
    cls.def_static("overrideCursor", &QGuiApplication::overrideCursor, py::return_value_policy::reference);
    cls.def_static("palette", &QGuiApplication::palette);
    cls.def_static("platformFunction", &QGuiApplication::platformFunction, py::arg("function"));
    cls.def_static("platformName", &QGuiApplication::platformName);
    // cls.def_static("platformNativeInterface", &QGuiApplication::platformNativeInterface, py::return_value_policy::reference);
    cls.def_static("primaryScreen", &QGuiApplication::primaryScreen, py::return_value_policy::reference);
    cls.def_static("queryKeyboardModifiers", &QGuiApplication::queryKeyboardModifiers);
    cls.def_static("quitOnLastWindowClosed", &QGuiApplication::quitOnLastWindowClosed);
    cls.def_static("restoreOverrideCursor", &QGuiApplication::restoreOverrideCursor);
    cls.def_static("screenAt", &QGuiApplication::screenAt, py::arg("point"), py::return_value_policy::reference);
    cls.def_static("screens", &QGuiApplication::screens);
    cls.def_static("setApplicationDisplayName", &QGuiApplication::setApplicationDisplayName, py::arg("name"));
    cls.def_static("setDesktopFileName", &QGuiApplication::setDesktopFileName, py::arg("name"));
    cls.def_static("setDesktopSettingsAware", &QGuiApplication::setDesktopSettingsAware, py::arg("on"));
    cls.def_static("setFallbackSessionManagementEnabled", &QGuiApplication::setFallbackSessionManagementEnabled, py::arg("enabled"));
    cls.def_static("setFont", &QGuiApplication::setFont, py::arg("font"));
    cls.def_static("setHighDpiScaleFactorRoundingPolicy", &QGuiApplication::setHighDpiScaleFactorRoundingPolicy, py::arg("policy"));
    cls.def_static("setLayoutDirection", &QGuiApplication::setLayoutDirection, py::arg("direction"));
    cls.def_static("setOverrideCursor", &QGuiApplication::setOverrideCursor, py::arg("cursor"));
    cls.def_static("setPalette", &QGuiApplication::setPalette, py::arg("pal"));
    cls.def_static("setQuitOnLastWindowClosed", &QGuiApplication::setQuitOnLastWindowClosed, py::arg("quit"));
    cls.def_static("setWindowIcon", &QGuiApplication::setWindowIcon, py::arg("icon"));
    cls.def_static("styleHints", &QGuiApplication::styleHints, py::return_value_policy::reference);
    cls.def_static("sync", &QGuiApplication::sync);
    cls.def_static("topLevelAt", &QGuiApplication::topLevelAt, py::arg("pos"), py::return_value_policy::reference);
    cls.def_static("topLevelWindows", &QGuiApplication::topLevelWindows);
    cls.def_static("windowIcon", &QGuiApplication::windowIcon);
}
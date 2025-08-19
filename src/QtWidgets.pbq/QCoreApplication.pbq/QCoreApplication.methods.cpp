namespace py = pybind11;

void bind_qcoreapplication_methods(py::class_<QCoreApplication, QObject> &cls) {
    // QCoreApplication 构造函数绑定
    cls.def(py::init([](py::list args) {
                // 将 Python 的 list 转换为 argc/argv
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
                return new QCoreApplication(argc, argv.data());
            }),
            py::arg("args"));

    // 析构函数无需显式绑定，pybind11会自动处理

    // installNativeEventFilter
    cls.def("installNativeEventFilter", &QCoreApplication::installNativeEventFilter, py::arg("filterObj"));

    // notify
    cls.def("notify", &QCoreApplication::notify, py::arg("receiver"), py::arg("event"));

    // removeNativeEventFilter
    cls.def("removeNativeEventFilter", &QCoreApplication::removeNativeEventFilter, py::arg("filterObject"));

    // 绑定 QCoreApplication 的静态方法和部分成员方法
    cls.def_static("addLibraryPath", &QCoreApplication::addLibraryPath, py::arg("path"));
    cls.def_static("applicationDirPath", &QCoreApplication::applicationDirPath);
    cls.def_static("applicationFilePath", &QCoreApplication::applicationFilePath);
    cls.def_static("applicationName", &QCoreApplication::applicationName);
    cls.def_static("applicationPid", &QCoreApplication::applicationPid);
    cls.def_static("applicationVersion", &QCoreApplication::applicationVersion);
    cls.def_static("arguments", &QCoreApplication::arguments);
    cls.def_static("closingDown", &QCoreApplication::closingDown);
    cls.def_static("eventDispatcher", &QCoreApplication::eventDispatcher, py::return_value_policy::reference);
    cls.def_static("exec", &QCoreApplication::exec);
    cls.def_static("exit", py::overload_cast<int>(&QCoreApplication::exit), py::arg("returnCode") = 0);
    cls.def_static("installTranslator", &QCoreApplication::installTranslator, py::arg("translationFile"));
    cls.def_static("instance", &QCoreApplication::instance, py::return_value_policy::reference);
    cls.def_static("isQuitLockEnabled", &QCoreApplication::isQuitLockEnabled);
    cls.def_static("isSetuidAllowed", &QCoreApplication::isSetuidAllowed);
    cls.def_static("libraryPaths", &QCoreApplication::libraryPaths);
    cls.def_static("organizationDomain", &QCoreApplication::organizationDomain);
    cls.def_static("organizationName", &QCoreApplication::organizationName);
    // TODO
    // cls.def_static(
    //     "postEvent",
    //     py::overload_cast<QObject *, QEvent *, int>(&QCoreApplication::postEvent),
    //     py::arg("receiver"), py::arg("event"), py::arg("priority") = Qt::NormalEventPriority);
    // cls.def_static(
    //     "processEvents",
    //     py::overload_cast<QEventLoop::ProcessEventsFlags>(&QCoreApplication::processEvents),
    //     py::arg("flags") = QEventLoop::AllEvents);
    // cls.def_static(
    //     "processEvents",
    //     py::overload_cast<QEventLoop::ProcessEventsFlags, int>(&QCoreApplication::processEvents),
    //     py::arg("flags"), py::arg("ms"));
    cls.def_static("removeLibraryPath", &QCoreApplication::removeLibraryPath, py::arg("path"));
    cls.def_static(
        "removePostedEvents",
        py::overload_cast<QObject *, int>(&QCoreApplication::removePostedEvents),
        py::arg("receiver"), py::arg("eventType") = 0);
    cls.def_static("removeTranslator", &QCoreApplication::removeTranslator, py::arg("translationFile"));
    cls.def_static(
        "sendEvent",
        &QCoreApplication::sendEvent,
        py::arg("receiver"), py::arg("event"));
    cls.def_static(
        "sendPostedEvents",
        py::overload_cast<QObject *, int>(&QCoreApplication::sendPostedEvents),
        py::arg("receiver") = nullptr, py::arg("event_type") = 0);
    cls.def_static("setApplicationName", &QCoreApplication::setApplicationName, py::arg("application"));
    cls.def_static("setApplicationVersion", &QCoreApplication::setApplicationVersion, py::arg("version"));
    cls.def_static(
        "setAttribute",
        py::overload_cast<Qt::ApplicationAttribute, bool>(&QCoreApplication::setAttribute),
        py::arg("attribute"), py::arg("on") = true);
    cls.def_static("setEventDispatcher", &QCoreApplication::setEventDispatcher, py::arg("eventDispatcher"));
    cls.def_static("setLibraryPaths", &QCoreApplication::setLibraryPaths, py::arg("paths"));
    cls.def_static("setOrganizationDomain", &QCoreApplication::setOrganizationDomain, py::arg("orgDomain"));
    cls.def_static("setOrganizationName", &QCoreApplication::setOrganizationName, py::arg("orgName"));
    cls.def_static("setQuitLockEnabled", &QCoreApplication::setQuitLockEnabled, py::arg("enabled"));
    cls.def_static("setSetuidAllowed", &QCoreApplication::setSetuidAllowed, py::arg("allow"));
    cls.def_static("startingUp", &QCoreApplication::startingUp);
    cls.def_static("testAttribute", &QCoreApplication::testAttribute, py::arg("attribute"));
    cls.def_static(
        "translate",
        py::overload_cast<const char *, const char *, const char *, int>(&QCoreApplication::translate),
        py::arg("context"), py::arg("sourceText"), py::arg("disambiguation") = nullptr, py::arg("n") = -1);
}
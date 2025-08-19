namespace py = pybind11;

void bind_qapplication_methods(py::class_<QApplication, QGuiApplication> &cls) {
    // 绑定QApplication的构造函数：QApplication(int &argc, char **argv)
    cls.def(py::init([](py::list args) {
        // 将Python列表转换为C++的argc和argv
        std::vector<QByteArray> argData;
        std::vector<char *> argPtrs;
        for (auto item : args) {
            argData.emplace_back(py::str(item).cast<std::string>().c_str());
            argPtrs.push_back(const_cast<char *>(argData.back().data()));
        }
        int argc = static_cast<int>(argPtrs.size());
        return std::make_unique<QApplication>(argc, argPtrs.data());
    }));

    // 绑定QApplication的析构函数（虚析构函数，pybind11会自动处理）

    // 绑定styleSheet方法
    cls.def("styleSheet", &QApplication::styleSheet);

    // 绑定QApplication的静态方法
    cls.def_static("activeModalWidget", &QApplication::activeModalWidget, py::return_value_policy::reference);
    cls.def_static("activePopupWidget", &QApplication::activePopupWidget, py::return_value_policy::reference);
    cls.def_static("activeWindow", &QApplication::activeWindow, py::return_value_policy::reference);
    cls.def_static(
        "alert",
        [](QWidget *widget, int msec = 0) {
            QApplication::alert(widget, msec);
        },
        py::arg("widget"), py::arg("msec") = 0);
    cls.def_static("allWidgets", &QApplication::allWidgets);
    cls.def_static("beep", &QApplication::beep);
    cls.def_static("cursorFlashTime", &QApplication::cursorFlashTime);
    cls.def_static("doubleClickInterval", &QApplication::doubleClickInterval);
    cls.def_static("exec_", &QApplication::exec);
    cls.def_static("focusWidget", &QApplication::focusWidget, py::return_value_policy::reference);
    cls.def_static(
        "font",
        py::overload_cast<>(&QApplication::font));
    cls.def_static(
        "font",
        py::overload_cast<const QWidget *>(&QApplication::font),
        py::arg("widget"));
    cls.def_static(
        "font",
        py::overload_cast<const char *>(&QApplication::font),
        py::arg("className"));
    cls.def_static("fontMetrics", &QApplication::fontMetrics);
    cls.def_static("isEffectEnabled", &QApplication::isEffectEnabled, py::arg("effect"));
    cls.def_static("keyboardInputInterval", &QApplication::keyboardInputInterval);
    // cls.def_static("navigationMode", &QApplication::navigationMode);
    cls.def_static(
        "palette",
        py::overload_cast<const QWidget *>(&QApplication::palette),
        py::arg("widget"));
    cls.def_static(
        "palette",
        py::overload_cast<const char *>(&QApplication::palette),
        py::arg("className"));
    cls.def_static("setActiveWindow", &QApplication::setActiveWindow, py::arg("active"));
    cls.def_static("setCursorFlashTime", &QApplication::setCursorFlashTime, py::arg("time"));
    cls.def_static("setDoubleClickInterval", &QApplication::setDoubleClickInterval, py::arg("interval"));
    cls.def_static(
        "setEffectEnabled",
        [](Qt::UIEffect effect, bool enable = true) {
            QApplication::setEffectEnabled(effect, enable);
        },
        py::arg("effect"), py::arg("enable") = true);
    cls.def_static(
        "setFont",
        [](const QFont &font, const char *className = nullptr) {
            QApplication::setFont(font, className);
        },
        py::arg("font"), py::arg("className") = nullptr);
    cls.def_static("setKeyboardInputInterval", &QApplication::setKeyboardInputInterval, py::arg("interval"));
    // cls.def_static("setNavigationMode", &QApplication::setNavigationMode, py::arg("mode"));
    cls.def_static(
        "setPalette",
        [](const QPalette &palette, const char *className = nullptr) {
            QApplication::setPalette(palette, className);
        },
        py::arg("palette"), py::arg("className") = nullptr);
    cls.def_static("setStartDragDistance", &QApplication::setStartDragDistance, py::arg("l"));
    cls.def_static("setStartDragTime", &QApplication::setStartDragTime, py::arg("ms"));
    cls.def_static("setStyle", py::overload_cast<QStyle *>(&QApplication::setStyle), py::arg("style"));
    cls.def_static(
        "setStyle",
        py::overload_cast<const QString &>(&QApplication::setStyle),
        py::arg("style"));
    cls.def_static("setWheelScrollLines", &QApplication::setWheelScrollLines, py::arg("lines"));
    cls.def_static("setWindowIcon", &QApplication::setWindowIcon, py::arg("icon"));
    cls.def_static("startDragDistance", &QApplication::startDragDistance);
    cls.def_static("startDragTime", &QApplication::startDragTime);
    cls.def_static("style", &QApplication::style, py::return_value_policy::reference);
    cls.def_static(
        "topLevelAt",
        py::overload_cast<const QPoint &>(&QApplication::topLevelAt),
        py::arg("point"),
        py::return_value_policy::reference);
    cls.def_static(
        "topLevelAt",
        py::overload_cast<int, int>(&QApplication::topLevelAt),
        py::arg("x"), py::arg("y"),
        py::return_value_policy::reference);
    cls.def_static("topLevelWidgets", &QApplication::topLevelWidgets);
    cls.def_static("wheelScrollLines", &QApplication::wheelScrollLines);
    cls.def_static(
        "widgetAt",
        py::overload_cast<const QPoint &>(&QApplication::widgetAt),
        py::arg("point"),
        py::return_value_policy::reference);
    cls.def_static(
        "widgetAt",
        py::overload_cast<int, int>(&QApplication::widgetAt),
        py::arg("x"), py::arg("y"),
        py::return_value_policy::reference);
    cls.def_static("windowIcon", &QApplication::windowIcon);
}
class LinkActivated : public Signal {
    PBQ_SIGNAL(LinkActivated, QLabel)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QLabel *>(get_obj());
        QObject::connect(
            obj, &QLabel::linkActivated,
            [slot_func](const QString &link) { slot_func(link); });
    }
};

class LinkHovered : public Signal {
    PBQ_SIGNAL(LinkHovered, QLabel)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QLabel *>(get_obj());
        QObject::connect(
            obj, &QLabel::linkHovered,
            [slot_func](const QString &link) { slot_func(link); });
    }
};

void bind_qlabel(py::module_ &m) {
    auto cls = py::class_<QLabel, QFrame>(m, "QLabel");

    // cls.def_property(
    //     "alignment",
    //     &QLabel::alignment,
    //     &QLabel::setAlignment);
    // cls.def_property_readonly(
    //     "hasSelectedText",
    //     &QLabel::hasSelectedText);
    // cls.def_property(
    //     "indent",
    //     &QLabel::indent,
    //     &QLabel::setIndent);
    // cls.def_property(
    //     "margin",
    //     &QLabel::margin,
    //     &QLabel::setMargin);
    // cls.def_property(
    //     "openExternalLinks",
    //     &QLabel::openExternalLinks,
    //     &QLabel::setOpenExternalLinks);
    // cls.def_property(
    //     "pixmap",
    //     [](const QLabel &self) { return self.pixmap() ? *self.pixmap() : QPixmap(); },
    //     &QLabel::setPixmap);
    // cls.def_property(
    //     "scaledContents",
    //     &QLabel::hasScaledContents,
    //     &QLabel::setScaledContents);
    // cls.def_property_readonly(
    //     "selectedText",
    //     &QLabel::selectedText);
    // cls.def_property(
    //     "text",
    //     &QLabel::text,
    //     &QLabel::setText);
    // cls.def_property(
    //     "textFormat",
    //     &QLabel::textFormat,
    //     &QLabel::setTextFormat);
    // cls.def_property(
    //     "textInteractionFlags",
    //     &QLabel::textInteractionFlags,
    //     &QLabel::setTextInteractionFlags);
    // cls.def_property(
    //     "wordWrap",
    //     &QLabel::wordWrap,
    //     &QLabel::setWordWrap);

    cls.def(py::init<const QString &, QWidget *, Qt::WindowFlags>(),
            py::arg("text"), py::arg("parent") = nullptr, py::arg("f") = Qt::WindowFlags());
    cls.def(py::init<QWidget *, Qt::WindowFlags>(),
            py::arg("parent") = nullptr, py::arg("f") = Qt::WindowFlags());
    // 析构函数通常不需要显式绑定

    cls.def("alignment", &QLabel::alignment);
    cls.def("buddy", &QLabel::buddy, py::return_value_policy::reference);
    cls.def("hasScaledContents", &QLabel::hasScaledContents);
    cls.def("hasSelectedText", &QLabel::hasSelectedText);
    cls.def("indent", &QLabel::indent);
    cls.def("margin", &QLabel::margin);
    cls.def("movie", &QLabel::movie, py::return_value_policy::reference);
    cls.def("openExternalLinks", &QLabel::openExternalLinks);
    cls.def("picture", [](const QLabel &self) { return self.picture(Qt::ReturnByValue); });
    cls.def("pixmap", [](const QLabel &self) { return self.pixmap(Qt::ReturnByValue); });
    cls.def("selectedText", &QLabel::selectedText);
    cls.def("selectionStart", &QLabel::selectionStart);
    cls.def("setAlignment", &QLabel::setAlignment, py::arg("alignment"));
    cls.def("setBuddy", &QLabel::setBuddy, py::arg("buddy"));
    cls.def("setIndent", &QLabel::setIndent, py::arg("indent"));
    cls.def("setMargin", &QLabel::setMargin, py::arg("margin"));
    cls.def("setOpenExternalLinks", &QLabel::setOpenExternalLinks, py::arg("open"));
    cls.def("setScaledContents", &QLabel::setScaledContents, py::arg("scaled"));
    cls.def("setSelection", &QLabel::setSelection, py::arg("start"), py::arg("length"));
    cls.def("setTextFormat", &QLabel::setTextFormat, py::arg("format"));
    cls.def("setTextInteractionFlags", &QLabel::setTextInteractionFlags, py::arg("flags"));
    cls.def("setWordWrap", &QLabel::setWordWrap, py::arg("on"));
    cls.def("text", &QLabel::text);
    cls.def("textFormat", &QLabel::textFormat);
    cls.def("textInteractionFlags", &QLabel::textInteractionFlags);
    cls.def("wordWrap", &QLabel::wordWrap);

    cls.def("clear", &QLabel::clear);
    cls.def("setMovie", &QLabel::setMovie, py::arg("movie"));
    cls.def("setNum", py::overload_cast<double>(&QLabel::setNum), py::arg("num"));
    cls.def("setNum", py::overload_cast<int>(&QLabel::setNum), py::arg("num"));
    cls.def("setPicture", &QLabel::setPicture, py::arg("picture"));
    cls.def("setPixmap", &QLabel::setPixmap, py::arg("pixmap"));
    cls.def("setText", &QLabel::setText, py::arg("text"));

    PBQ_BIND_SIGNAL(QLabel, LinkActivated, LinkHovered);
}
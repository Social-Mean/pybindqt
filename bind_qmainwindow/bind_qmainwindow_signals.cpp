#include <widgets_base.h>

namespace py = pybind11;

class IconSizeChanged : public Signal {
public:
    IconSizeChanged(QMainWindow *obj) :
        Signal(obj) {
    }
    void connect(py::function slot_func) const override {
        QMainWindow *mainWindow = qobject_cast<QMainWindow *>(get_obj());
        if (mainWindow) {
            QObject::connect(
                mainWindow, &QMainWindow::iconSizeChanged,
                [slot_func](const QSize &iconSize) { slot_func(iconSize); });
        }
    }
};

class ToolButtonStyleChanged : public Signal {
public:
    ToolButtonStyleChanged(QMainWindow *obj) :
        Signal(obj) {
    }
    void connect(py::function slot_func) const override {
        QMainWindow *mainWindow = qobject_cast<QMainWindow *>(get_obj());
        if (mainWindow) {
            QObject::connect(
                mainWindow, &QMainWindow::toolButtonStyleChanged,
                [slot_func](Qt::ToolButtonStyle style) { slot_func(style); });
        }
    }
};

void bind_qmainwindow_signals(py::class_<QMainWindow, QWidget> &cls) {
    py::class_<IconSizeChanged, Signal>(cls, "IconSizeChanged")
        .def(py::init([](QMainWindow *self) { return IconSizeChanged(self); }));

    py::class_<ToolButtonStyleChanged, Signal>(cls, "ToolButtonStyleChanged")
        .def(py::init(
            [](QMainWindow *self) { return ToolButtonStyleChanged(self); }));

    cls.def_property_readonly(
           "iconSizeChanged",
           [](QMainWindow *self) { return IconSizeChanged(self); })
        .def_property_readonly("toolButtonStyleChanged", [](QMainWindow *self) {
            return ToolButtonStyleChanged(self);
        });
}
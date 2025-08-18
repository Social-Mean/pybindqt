#include <widgets_base.h>

namespace py = pybind11;

class IconSizeChanged : public Signal {
    PBQ_SIGNAL(IconSizeChanged, QMainWindow)
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
    PBQ_SIGNAL(ToolButtonStyleChanged, QMainWindow)
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
    PBQ_BIND_SIGNAL(QMainWindow, IconSizeChanged, ToolButtonStyleChanged);
}
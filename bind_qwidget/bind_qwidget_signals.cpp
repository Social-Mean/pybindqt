#include <widgets_base.h>

namespace py = pybind11;

class CustomContextMenuRequested : public Signal {
    PBQ_SIGNAL(CustomContextMenuRequested, QWidget)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QWidget *>(get_obj());
        QObject::connect(obj, &QWidget::customContextMenuRequested,
                         [slot_func](const QPoint &pos) { slot_func(pos); });
    }
};

class WindowIconChanged : public Signal {
    PBQ_SIGNAL(WindowIconChanged, QWidget)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QWidget *>(get_obj());
        QObject::connect(obj, &QWidget::windowIconChanged,
                         [slot_func](const QIcon &icon) { slot_func(icon); });
    }
};

class WindowIconTextChanged : public Signal {
    PBQ_SIGNAL(WindowIconTextChanged, QWidget)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QWidget *>(get_obj());
        QObject::connect(obj, &QWidget::windowIconTextChanged,
                         [slot_func](const QString &iconText) { slot_func(iconText); });
    }
};

class WindowTitleChanged : public Signal {
    PBQ_SIGNAL(WindowTitleChanged, QWidget)
    void connect(py::function slot_func) const override {
        auto *obj = qobject_cast<QWidget *>(get_obj());
        QObject::connect(obj, &QWidget::windowTitleChanged,
                         [slot_func](const QString &title) { slot_func(title); });
    }
};

void bind_qwidget_signals(py::class_<QWidget, QObject> &cls) {
    PBQ_BIND_SIGNAL(QWidget, CustomContextMenuRequested, WindowIconChanged,
                    WindowIconTextChanged, WindowTitleChanged);
}
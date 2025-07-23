#include "signal.h"
#include <QAbstractButton>

Signal::Signal(QObject *parent) : m_parent(parent) {}

Clicked::Clicked(QObject *parent) : Signal(parent) {}

void Clicked::connect(const pybind11::function &func) {
    auto btn = qobject_cast<QAbstractButton *>(parent());
    if (btn) {
        QObject::connect(btn, &QAbstractButton::clicked, btn,
                         [func](bool checked) { func(checked); });
    }
}
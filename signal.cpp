#include "signal.h"
#include <QPushButton>

Signal::Signal(QObject *parent) : m_parent(parent) {}

Clicked::Clicked(QObject *parent) : Signal(parent) {}

void Clicked::connect(const pybind11::function &func) {
    auto btn = qobject_cast<QPushButton *>(parent());
    if (btn) {
        QObject::connect(btn, &QPushButton::clicked, btn,
                         [func](bool checked) { func(checked); });
    }
}
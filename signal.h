#pragma once
#include <pybind11/pybind11.h>
#include <vector>
#include <QObject>

class Signal {
public:
    Signal(QObject *parent = nullptr);
    virtual void connect(const pybind11::function &func) = 0;
    QObject *parent() const { return m_parent; }

protected:
    QObject *m_parent;
};

class Clicked : public Signal {
public:
    Clicked(QObject *parent);
    void connect(const pybind11::function &func) override;
};
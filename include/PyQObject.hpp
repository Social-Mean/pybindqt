#pragma once

template <class QBase = QObject>
class PyQObject : public QBase, public py::trampoline_self_life_support {
public:
    void childEvent(QChildEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, childEvent, event);
    }
    void connectNotify(const QMetaMethod &signal) override {
        PYBIND11_OVERRIDE(void, QBase, connectNotify, signal);
    }

    void customEvent(QEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, customEvent, event);
    }

    void disconnectNotify(const QMetaMethod &signal) override {
        PYBIND11_OVERRIDE(void, QBase, disconnectNotify, signal);
    }

    // bool isSignalConnected(const QMetaMethod &signal) const override {
    //     PYBIND11_OVERRIDE(bool, QBase, isSignalConnected, signal);
    // }

    int receivers(const char *signal) const {
        PYBIND11_OVERRIDE(int, QBase, receivers, signal);
    }

    // QObject *sender() const override {
    //     PYBIND11_OVERRIDE(QObject *, QBase, sender, );
    // }

    // int senderSignalIndex() const override {
    //     PYBIND11_OVERRIDE(int, QBase, senderSignalIndex, );
    // }

    void timerEvent(QTimerEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, timerEvent, event);
    }
};
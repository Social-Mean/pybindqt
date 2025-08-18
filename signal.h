#pragma once

namespace py = pybind11;

class Signal {
public:
    Signal(QObject *obj) {
        m_obj = obj;
    }
    virtual void connect(py::function slot_func) const {
        throw std::runtime_error("Not implemented");
    }
    QObject *get_obj() const {
        return m_obj;
    }

private:
    QObject *m_obj;
};

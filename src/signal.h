#pragma once

#include <boost/preprocessor.hpp>

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

#define PBQ_SIGNAL(SignalType, ClsType) \
public:                                 \
    SignalType(ClsType *obj) :          \
        Signal(obj) {                   \
    }

// 辅助宏：将 SIGNAL 转为小写字符串（如 "Clicked" → "clicked"）

inline const char *signal_to_lower(const char *s) {
    static thread_local std::string str; // 线程局部存储避免竞争
    str = s;
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return str.c_str();
}

#define PBQ_SIGNAL_TO_LOWER(signal) \
    signal_to_lower(BOOST_PP_STRINGIZE(signal))

// 主宏：生成信号绑定 + def_property_readonly
#define PBQ_BIND_SIGNAL(CLASS, ...) \
    BOOST_PP_SEQ_FOR_EACH(          \
        PBQ_BIND_SIGNAL_HELPER,     \
        CLASS,                      \
        BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

// 宏辅助函数：处理每个信号
#define PBQ_BIND_SIGNAL_HELPER(r, CLASS, SIGNAL)                                                  \
    py::class_<SIGNAL, Signal>(cls, BOOST_PP_STRINGIZE(SIGNAL))                                   \
                                        .def(py::init([](CLASS *self) { return SIGNAL(self); })); \
    cls.def_property_readonly(                                                                    \
        PBQ_SIGNAL_TO_LOWER(SIGNAL),                                                              \
        [](CLASS *self) { return SIGNAL(self); });
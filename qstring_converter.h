#pragma once

namespace py = pybind11;

// QString 和 Python str 相互转换
namespace pybind11 {
namespace detail {
template <>
struct type_caster<QString> {
public:
    PYBIND11_TYPE_CASTER(QString, _("str"));
    static handle cast(const QString &src, return_value_policy /* policy */,
                       handle /* parent */) {
        py::gil_scoped_acquire gil;
        QByteArray utf8 = src.toUtf8(); // 保持生命周期
        return PyUnicode_FromStringAndSize(utf8.constData(), utf8.size());
    }

    bool load(handle src, bool) {
        py::gil_scoped_acquire gil;
        if (!PyUnicode_Check(src.ptr()))
            return false;

        PyObject *utf8 = PyUnicode_AsUTF8String(src.ptr());
        if (!utf8)
            return false;

        char *data = PyBytes_AsString(utf8);
        QByteArray byteArray(data); // 复制数据
        Py_DECREF(utf8);

        value = QString::fromUtf8(byteArray);
        return true;
    }
};
}
} // namespace pybind11::detail
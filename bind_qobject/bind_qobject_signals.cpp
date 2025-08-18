#include <widgets_base.h>

namespace py = pybind11;

void bind_qobject_signals(py::class_<QObject> &cls) {
    cls.def_property_readonly("destroyed",
                              [](QObject *self) { return Destroyed(self); })
        .def_property_readonly("objectNameChanged", [](QObject *self) {
            return ObjectNameChanged(self);
        });
}
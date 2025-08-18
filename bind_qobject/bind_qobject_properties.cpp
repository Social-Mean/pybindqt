#include <widgets_base.h>

void bind_qobject_properties(py::class_<QObject> &cls) {
    cls.def_property_readonly("objectName",
                              [](QObject *self) { return self->objectName(); });
}

#include <pybind11/pybind11.h>

#include "widgets_base.h"

namespace py = pybind11;

PYBIND11_MODULE(QtWidgets, m) {
  bind_signal(m);
  bind_enum(m);
  bind_qflags(m);
  bind_qstring(m);
  bind_qobject(m);
  bind_qwidget(m);
  bind_qapplication(m);
  bind_qmainwindow(m);
  bind_qabstractbutton(m);
  bind_qpushbutton(m);
}
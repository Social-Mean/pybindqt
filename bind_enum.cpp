#include <pybind11/pybind11.h>

#include <QTimer>

namespace py = pybind11;

void bind_enum(py::module_ &m) {
  py::enum_<Qt::TimerType>(m, "TimerType")
      .value("PreciseTimer", Qt::PreciseTimer)
      .value("CoarseTimer", Qt::CoarseTimer)
      .value("VeryCoarseTimer", Qt::VeryCoarseTimer)
      .export_values();
}

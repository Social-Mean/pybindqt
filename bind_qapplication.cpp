#include <pybind11/stl.h>

#include <QApplication>
namespace py = pybind11;

void bind_qapplication(py::module_ &m) {
  py::class_<QApplication>(m, "QApplication")
      .def(py::init([](py::list args) {
        std::vector<QByteArray> argData;
        std::vector<char *> argPtrs;
        for (auto item : args) {
          argData.emplace_back(py::str(item).cast<std::string>().c_str());
          argPtrs.push_back(const_cast<char *>(argData.back().data()));
        }
        int argc = static_cast<int>(argPtrs.size());
        return std::make_unique<QApplication>(argc, argPtrs.data());
      }))
      .def("exec_", [](QApplication &self) { return self.exec(); });
}
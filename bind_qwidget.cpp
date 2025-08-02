#include <pybind11/pybind11.h>

#include <QObject>
#include <QWidget>
namespace py = pybind11;

void bind_qwidget(py::module_ &m) {
  py::class_<QWidget, QObject>(m, "QWidget")
      .def_property_readonly("acceptDrops",
                             [](QWidget *self) { return self->acceptDrops(); })
      .def_property_readonly(
          "accessibleDescription",
          [](QWidget *self) { return self->accessibleDescription(); })
      .def_property_readonly(
          "accessibleName",
          [](QWidget *self) { return self->accessibleName(); })
      .def_property_readonly(
          "autoFillBackground",
          [](QWidget *self) { return self->autoFillBackground(); })
      .def_property_readonly("baseSize",
                             [](QWidget *self) { return self->baseSize(); })
      .def_property_readonly("childrenRect",
                             [](QWidget *self) { return self->childrenRect(); })
      .def_property_readonly(
          "childrenRegion",
          [](QWidget *self) { return self->childrenRegion(); })
      .def_property_readonly(
          "contextMenuPolicy",
          [](QWidget *self) { return self->contextMenuPolicy(); })
      .def_property_readonly("cursor",
                             [](QWidget *self) { return self->cursor(); })
      //   .def_property_readonly("enabled",
      //                          [](QWidget *self) { return self->enabled(); })
      //   .def_property_readonly("focus",
      //                          [](QWidget *self) { return self->focus(); })
      .def_property_readonly("focusPolicy",
                             [](QWidget *self) { return self->focusPolicy(); })
      .def_property_readonly("font", [](QWidget *self) { return self->font(); })
      .def_property_readonly(
          "frameGeometry", [](QWidget *self) { return self->frameGeometry(); })
      .def_property_readonly("frameSize",
                             [](QWidget *self) { return self->frameSize(); })
      //   .def_property_readonly("fullScreen",
      //                          [](QWidget *self) { return self->fullScreen();
      //                          })
      .def_property_readonly("geometry",
                             [](QWidget *self) { return self->geometry(); })
      .def_property_readonly("height",
                             [](QWidget *self) { return self->height(); })
      //   .def_property_readonly(
      //       "inputMethodHints",
      //       [](QWidget *self) { return self->inputMethodHints(); })
      .def_property_readonly(
          "isActiveWindow",
          [](QWidget *self) { return self->isActiveWindow(); })
      .def_property_readonly(
          "layoutDirection",
          [](QWidget *self) { return self->layoutDirection(); })
      //   .def_property_readonly("locale",
      //                          [](QWidget *self) { return self->locale(); })
      //   .def_property_readonly("maximized",
      //                          [](QWidget *self) { return self->maximized();
      //                          })
      .def_property_readonly(
          "maximumHeight", [](QWidget *self) { return self->maximumHeight(); })
      .def_property_readonly("maximumSize",
                             [](QWidget *self) { return self->maximumSize(); })
      .def_property_readonly("maximumWidth",
                             [](QWidget *self) { return self->maximumWidth(); })
      //   .def_property_readonly("minimized",
      //                          [](QWidget *self) { return self->minimized();
      //                          })
      .def_property_readonly(
          "minimumHeight", [](QWidget *self) { return self->minimumHeight(); })
      .def_property_readonly("minimumSize",
                             [](QWidget *self) { return self->minimumSize(); })
      .def_property_readonly(
          "minimumSizeHint",
          [](QWidget *self) { return self->minimumSizeHint(); })
      .def_property_readonly("minimumWidth",
                             [](QWidget *self) { return self->minimumWidth(); })
      //   .def_property_readonly("modal",
      //                          [](QWidget *self) { return self->modal(); })
      //   .def_property_readonly(
      //       "mouseTracking", [](QWidget *self) { return
      //       self->mouseTracking(); })
      .def_property_readonly(
          "normalGeometry",
          [](QWidget *self) { return self->normalGeometry(); })
      .def_property_readonly("palette",
                             [](QWidget *self) { return self->palette(); })

      ;
}
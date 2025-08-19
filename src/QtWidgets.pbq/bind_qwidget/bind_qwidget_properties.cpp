namespace py = pybind11;

void bind_qwidget_properties(py::class_<QWidget, QObject> &cls) {
    // cls.def_property_readonly("acceptDrops",
    //                          [](QWidget *self) { return
    //                          self->acceptDrops(); })
    //   .def_property_readonly(
    //       "accessibleDescription",
    //       [](QWidget *self) { return self->accessibleDescription(); })
    //   .def_property_readonly(
    //       "accessibleName",
    //       [](QWidget *self) { return self->accessibleName(); })
    //   .def_property_readonly(
    //       "autoFillBackground",
    //       [](QWidget *self) { return self->autoFillBackground(); })
    //   .def_property_readonly("baseSize",
    //                          [](QWidget *self) { return self->baseSize();
    //                          })
    //   .def_property_readonly("childrenRect",
    //                          [](QWidget *self) { return
    //                          self->childrenRect(); })
    //   .def_property_readonly(
    //       "childrenRegion",
    //       [](QWidget *self) { return self->childrenRegion(); })
    //   .def_property_readonly(
    //       "contextMenuPolicy",
    //       [](QWidget *self) { return self->contextMenuPolicy(); })
    //   .def_property_readonly("cursor",
    //                          [](QWidget *self) { return self->cursor(); })
    //   .def_property_readonly("enabled",
    //                          [](QWidget *self) { return self->enabled(); })
    //   .def_property_readonly("focus",
    //                          [](QWidget *self) { return self->focus(); })
    //   .def_property_readonly("focusPolicy",
    //                          [](QWidget *self) { return
    //                          self->focusPolicy(); })
    //   .def_property_readonly("font", [](QWidget *self) { return
    //   self->font(); }) .def_property_readonly(
    //       "frameGeometry", [](QWidget *self) { return
    //       self->frameGeometry(); })
    //   .def_property_readonly("frameSize",
    //                          [](QWidget *self) { return self->frameSize();
    //                          })
    //   .def_property_readonly("fullScreen",
    //                          [](QWidget *self) { return self->fullScreen();
    //                          })
    //   .def_property_readonly("geometry",
    //                          [](QWidget *self) { return self->geometry();
    //                          })
    //   .def_property_readonly("height",
    //                          [](QWidget *self) { return self->height(); })
    //   .def_property_readonly(
    //       "inputMethodHints",
    //       [](QWidget *self) { return self->inputMethodHints(); })
    //   .def_property_readonly(
    //       "isActiveWindow",
    //       [](QWidget *self) { return self->isActiveWindow(); })
    //   .def_property_readonly(
    //       "layoutDirection",
    //       [](QWidget *self) { return self->layoutDirection(); })
    //   .def_property_readonly("locale",
    //                          [](QWidget *self) { return self->locale(); })
    //   .def_property_readonly("maximized",
    //                          [](QWidget *self) { return self->maximized();
    //                          })
    //   .def_property_readonly(
    //       "maximumHeight", [](QWidget *self) { return
    //       self->maximumHeight(); })
    //   .def_property_readonly("maximumSize",
    //                          [](QWidget *self) { return
    //                          self->maximumSize(); })
    //   .def_property_readonly("maximumWidth",
    //                          [](QWidget *self) { return
    //                          self->maximumWidth(); })
    //   .def_property_readonly("minimized",
    //                          [](QWidget *self) { return self->minimized();
    //                          })
    //   .def_property_readonly(
    //       "minimumHeight", [](QWidget *self) { return
    //       self->minimumHeight(); })
    //   .def_property_readonly("minimumSize",
    //                          [](QWidget *self) { return
    //                          self->minimumSize(); })
    //   .def_property_readonly(
    //       "minimumSizeHint",
    //       [](QWidget *self) { return self->minimumSizeHint(); })
    //   .def_property_readonly("minimumWidth",
    //                          [](QWidget *self) { return
    //                          self->minimumWidth(); })
    //   .def_property_readonly("modal",
    //                          [](QWidget *self) { return self->modal(); })
    //   .def_property_readonly(
    //       "mouseTracking", [](QWidget *self) { return
    //       self->mouseTracking(); })
    //   .def_property_readonly(
    //       "normalGeometry",
    //       [](QWidget *self) { return self->normalGeometry(); })
    //   .def_property_readonly("palette",
    //                          [](QWidget *self) { return self->palette(); })
    //   .def_property_readonly("pos", [](QWidget *self) { return self->pos();
    //   }) .def_property_readonly("rect", [](QWidget *self) { return
    //   self->rect(); }) .def_property_readonly("size", [](QWidget *self) {
    //   return self->size(); }) .def_property_readonly("sizeHint",
    //                          [](QWidget *self) { return self->sizeHint();
    //                          })
    //   .def_property_readonly(
    //       "sizeIncrement", [](QWidget *self) { return
    //       self->sizeIncrement(); })
    //   .def_property_readonly("sizePolicy",
    //                          [](QWidget *self) { return self->sizePolicy();
    //                          })
    //   .def_property_readonly("statusTip",
    //                          [](QWidget *self) { return self->statusTip();
    //                          })
    //   .def_property_readonly("styleSheet",
    //                          [](QWidget *self) { return self->styleSheet();
    //                          })
    //   .def_property_readonly(
    //       "tabletTracking",
    //       [](QWidget *self) { return self->tabletTracking(); })
    //   .def_property_readonly("toolTip",
    //                          [](QWidget *self) { return self->toolTip(); })
    //   .def_property_readonly(
    //       "toolTipDuration",
    //       [](QWidget *self) { return self->toolTipDuration(); })
    //   .def_property_readonly(
    //       "updatesEnabled",
    //       [](QWidget *self) { return self->updatesEnabled(); })
    //   .def_property_readonly("visible",
    //                          [](QWidget *self) { return self->visible(); })
    //   .def_property_readonly("whatsThis",
    //                          [](QWidget *self) { return self->whatsThis();
    //                          })
    //   .def_property_readonly("width",
    //                          [](QWidget *self) { return self->width(); })
    //   .def_property_readonly(
    //       "windowFilePath",
    //       [](QWidget *self) { return self->windowFilePath(); })
    //   .def_property_readonly("windowFlags",
    //                          [](QWidget *self) { return
    //                          self->windowFlags(); })
    //   .def_property_readonly("windowIcon",
    //                          [](QWidget *self) { return self->windowIcon();
    //                          })
    //   .def_property_readonly(
    //       "windowModality",
    //       [](QWidget *self) { return self->windowModality(); })
    //   .def_property_readonly(
    //       "windowModified",
    //       [](QWidget *self) { return self->windowModified(); })
    //   .def_property_readonly(
    //       "windowOpacity", [](QWidget *self) { return
    //       self->windowOpacity(); })
    //   .def_property_readonly("windowTitle",
    //                          [](QWidget *self) { return
    //                          self->windowTitle(); })
    //   .def_property_readonly("x", [](QWidget *self) { return self->x(); })
    //   .def_property_readonly("y", [](QWidget *self) { return self->y(); })
}
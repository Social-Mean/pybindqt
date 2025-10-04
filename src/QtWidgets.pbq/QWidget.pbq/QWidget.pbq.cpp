#include <PyQObject.hpp>
#include <PyQWidget.hpp>

namespace py = pybind11;

void bind_qwidget(py::module_ &m) {
    auto cls = py::class_<QWidget,
                          QObject,
                          PyQWidget<>,
                          py::smart_holder>(m, "QWidget");

    // 属性绑定 - 移除有重载的setter方法
    cls.def_property("acceptDrops", &QWidget::acceptDrops, &QWidget::setAcceptDrops);
    cls.def_property("accessibleDescription", &QWidget::accessibleDescription, &QWidget::setAccessibleDescription);
    cls.def_property("accessibleName", &QWidget::accessibleName, &QWidget::setAccessibleName);
    cls.def_property("autoFillBackground", &QWidget::autoFillBackground, &QWidget::setAutoFillBackground);
    // 移除 baseSize - 有重载
    cls.def_property_readonly("childrenRect", &QWidget::childrenRect);
    cls.def_property_readonly("childrenRegion", &QWidget::childrenRegion);
    cls.def_property("contextMenuPolicy", &QWidget::contextMenuPolicy, &QWidget::setContextMenuPolicy);
    cls.def_property("cursor", &QWidget::cursor, &QWidget::setCursor);
    cls.def_property("enabled", &QWidget::isEnabled, &QWidget::setEnabled);
    cls.def_property_readonly("focus", &QWidget::hasFocus);
    cls.def_property("focusPolicy", &QWidget::focusPolicy, &QWidget::setFocusPolicy);
    cls.def_property("font", &QWidget::font, &QWidget::setFont);
    cls.def_property_readonly("frameGeometry", &QWidget::frameGeometry);
    cls.def_property_readonly("frameSize", &QWidget::frameSize);
    cls.def_property_readonly("fullScreen", &QWidget::isFullScreen);
    // 移除 geometry - 有重载
    cls.def_property_readonly("height", &QWidget::height);
    cls.def_property("inputMethodHints", &QWidget::inputMethodHints, &QWidget::setInputMethodHints);
    cls.def_property_readonly("isActiveWindow", &QWidget::isActiveWindow);
    cls.def_property("layoutDirection", &QWidget::layoutDirection, &QWidget::setLayoutDirection);
    cls.def_property("locale", &QWidget::locale, &QWidget::setLocale);
    cls.def_property_readonly("maximized", &QWidget::isMaximized);
    cls.def_property("maximumHeight", &QWidget::maximumHeight, &QWidget::setMaximumHeight);
    // 移除 maximumSize - 有重载
    cls.def_property("maximumWidth", &QWidget::maximumWidth, &QWidget::setMaximumWidth);
    cls.def_property_readonly("minimized", &QWidget::isMinimized);
    cls.def_property("minimumHeight", &QWidget::minimumHeight, &QWidget::setMinimumHeight);
    // 移除 minimumSize - 有重载
    cls.def_property_readonly("minimumSizeHint", &QWidget::minimumSizeHint);
    cls.def_property("minimumWidth", &QWidget::minimumWidth, &QWidget::setMinimumWidth);
    cls.def_property_readonly("modal", &QWidget::isModal);
    cls.def_property("mouseTracking", &QWidget::hasMouseTracking, &QWidget::setMouseTracking);
    cls.def_property_readonly("normalGeometry", &QWidget::normalGeometry);
    cls.def_property("palette", &QWidget::palette, &QWidget::setPalette);
    // 移除 pos - 有重载
    cls.def_property_readonly("rect", &QWidget::rect);
    // 移除 size - 有重载
    cls.def_property_readonly("sizeHint", &QWidget::sizeHint);
    // 移除 sizeIncrement - 有重载
    // 移除 sizePolicy - 有重载
    cls.def_property("statusTip", &QWidget::statusTip, &QWidget::setStatusTip);
    cls.def_property("styleSheet", &QWidget::styleSheet, &QWidget::setStyleSheet);
    cls.def_property("tabletTracking", &QWidget::hasTabletTracking, &QWidget::setTabletTracking);
    cls.def_property("toolTip", &QWidget::toolTip, &QWidget::setToolTip);
    cls.def_property("toolTipDuration", &QWidget::toolTipDuration, &QWidget::setToolTipDuration);
    cls.def_property("updatesEnabled", &QWidget::updatesEnabled, &QWidget::setUpdatesEnabled);
    cls.def_property("visible", &QWidget::isVisible, &QWidget::setVisible);
    cls.def_property("whatsThis", &QWidget::whatsThis, &QWidget::setWhatsThis);
    cls.def_property_readonly("width", &QWidget::width);
    cls.def_property("windowFilePath", &QWidget::windowFilePath, &QWidget::setWindowFilePath);
    cls.def_property("windowFlags", &QWidget::windowFlags, &QWidget::setWindowFlags);
    cls.def_property("windowIcon", &QWidget::windowIcon, &QWidget::setWindowIcon);
    cls.def_property("windowModality", &QWidget::windowModality, &QWidget::setWindowModality);
    cls.def_property("windowModified", &QWidget::isWindowModified, &QWidget::setWindowModified);
    cls.def_property("windowOpacity", &QWidget::windowOpacity, &QWidget::setWindowOpacity);
    cls.def_property("windowTitle", &QWidget::windowTitle, &QWidget::setWindowTitle);
    cls.def_property_readonly("x", &QWidget::x);
    cls.def_property_readonly("y", &QWidget::y);

    // 添加有重载的setter方法绑定
    cls.def("setGeometry", py::overload_cast<const QRect &>(&QWidget::setGeometry))
        .def("setGeometry", py::overload_cast<int, int, int, int>(&QWidget::setGeometry))
        .def("setBaseSize", py::overload_cast<const QSize &>(&QWidget::setBaseSize))
        .def("setBaseSize", py::overload_cast<int, int>(&QWidget::setBaseSize))
        .def("setMaximumSize", py::overload_cast<const QSize &>(&QWidget::setMaximumSize))
        .def("setMaximumSize", py::overload_cast<int, int>(&QWidget::setMaximumSize))
        .def("setMinimumSize", py::overload_cast<const QSize &>(&QWidget::setMinimumSize))
        .def("setMinimumSize", py::overload_cast<int, int>(&QWidget::setMinimumSize))
        .def("setSizeIncrement", py::overload_cast<const QSize &>(&QWidget::setSizeIncrement))
        .def("setSizeIncrement", py::overload_cast<int, int>(&QWidget::setSizeIncrement))
        .def("setSizePolicy", py::overload_cast<QSizePolicy>(&QWidget::setSizePolicy))
        .def("setSizePolicy", py::overload_cast<QSizePolicy::Policy, QSizePolicy::Policy>(&QWidget::setSizePolicy))
        .def("resize", py::overload_cast<const QSize &>(&QWidget::resize))
        .def("resize", py::overload_cast<int, int>(&QWidget::resize))
        .def("move", py::overload_cast<const QPoint &>(&QWidget::move))
        .def("move", py::overload_cast<int, int>(&QWidget::move));

    // 添加getter方法
    cls.def("geometry", &QWidget::geometry)
        .def("baseSize", &QWidget::baseSize)
        .def("maximumSize", &QWidget::maximumSize)
        .def("minimumSize", &QWidget::minimumSize)
        .def("sizeIncrement", &QWidget::sizeIncrement)
        .def("sizePolicy", &QWidget::sizePolicy)
        .def("size", &QWidget::size)
        .def("pos", &QWidget::pos);

    // 补充缺失的方法绑定
    cls
        //   .def("accessibleIdentifier", &QWidget::accessibleIdentifier)
        .def("actions", &QWidget::actions)
        .def("activateWindow", &QWidget::activateWindow)
        .def("addAction", &QWidget::addAction)
        .def("addActions", &QWidget::addActions)
        .def("adjustSize", &QWidget::adjustSize)
        .def("backingStore", &QWidget::backingStore)
        //   .def("childAt", py::overload_cast<int, int>(&QWidget::childAt))
        //   .def("childAt", py::overload_cast<const QPoint
        //   &>(&QWidget::childAt))
        .def("clearFocus", &QWidget::clearFocus)
        .def("clearMask", &QWidget::clearMask)
        .def("contentsMargins", &QWidget::contentsMargins)
        .def("contentsRect", &QWidget::contentsRect)
        .def("effectiveWinId", &QWidget::effectiveWinId)
        .def("ensurePolished", &QWidget::ensurePolished)
        .def("focusProxy", &QWidget::focusProxy)
        .def("focusWidget", &QWidget::focusWidget)
        .def("fontInfo", &QWidget::fontInfo)
        .def("fontMetrics", &QWidget::fontMetrics)
        .def("grab", &QWidget::grab)
        .def("grabGesture", &QWidget::grabGesture)
        .def("grabKeyboard", &QWidget::grabKeyboard)
        .def("grabMouse", py::overload_cast<>(&QWidget::grabMouse))
        //   .def("grabMouse", py::overload_cast<QCursor
        //   *>(&QWidget::grabMouse))
        .def("grabShortcut", &QWidget::grabShortcut)
        .def("graphicsEffect", &QWidget::graphicsEffect)
        .def("graphicsProxyWidget", &QWidget::graphicsProxyWidget)
        .def("hasHeightForWidth", &QWidget::hasHeightForWidth)
        .def("heightForWidth", &QWidget::heightForWidth)
        .def("inputMethodQuery", &QWidget::inputMethodQuery)
        .def("insertAction", &QWidget::insertAction)
        .def("insertActions", &QWidget::insertActions)
        .def("isAncestorOf", &QWidget::isAncestorOf)
        .def("isEnabledTo", &QWidget::isEnabledTo)
        .def("isHidden", &QWidget::isHidden)
        .def("isVisibleTo", &QWidget::isVisibleTo)
        .def("isWindow", &QWidget::isWindow)
        .def("layout", &QWidget::layout)
        .def("mapFrom", &QWidget::mapFrom)
        .def("mapFromGlobal", &QWidget::mapFromGlobal)
        .def("mapFromParent", &QWidget::mapFromParent)
        .def("mapTo", &QWidget::mapTo)
        .def("mapToGlobal", &QWidget::mapToGlobal)
        .def("mapToParent", &QWidget::mapToParent)
        .def("mask", &QWidget::mask)
        //   .def("move", py::overload_cast<QPoint>(&QWidget::move))
        .def("nativeParentWidget", &QWidget::nativeParentWidget)
        //   .def("nativeFocusChain", &QWidget::nativeFocusChain)
        .def("overrideWindowFlags", &QWidget::overrideWindowFlags)
        .def("parentWidget", &QWidget::parentWidget)
        .def("previousInFocusChain", &QWidget::previousInFocusChain)
        .def("releaseKeyboard", &QWidget::releaseKeyboard)
        .def("releaseMouse", &QWidget::releaseMouse)
        .def("releaseShortcut", &QWidget::releaseShortcut)
        .def("removeAction", &QWidget::removeAction)
        //   .def("render", &QWidget::render)
        .def("repaint", py::overload_cast<const QRect &>(&QWidget::repaint))
        .def("repaint", py::overload_cast<const QRegion &>(&QWidget::repaint))
        .def("repaint", py::overload_cast<int, int, int, int>(&QWidget::repaint))
        .def("restoreGeometry", &QWidget::restoreGeometry)
        .def("saveGeometry", &QWidget::saveGeometry)
        .def("screen", &QWidget::screen)
        //   .def("scroll", &QWidget::scroll)
        .def("scroll", py::overload_cast<int, int>(&QWidget::scroll))
        .def("scroll",
             py::overload_cast<int, int, const QRect &>(&QWidget::scroll))
        .def("setAttribute", &QWidget::setAttribute)
        .def("setBackgroundRole", &QWidget::setBackgroundRole)
        //   .def("setContentsMargins", &QWidget::setContentsMargins)
        // .def("setEditFocus", &QWidget::setEditFocus)
        .def("setFixedHeight", &QWidget::setFixedHeight)
        .def("setFixedSize",
             py::overload_cast<const QSize &>(&QWidget::setFixedSize))
        .def("setFixedSize", py::overload_cast<int, int>(&QWidget::setFixedSize))
        .def("setFixedWidth", &QWidget::setFixedWidth)
        //   .def("setFocus", &QWidget::setFocus)
        .def("setFocusProxy", &QWidget::setFocusProxy)
        .def("setForegroundRole", &QWidget::setForegroundRole)
        .def("setGraphicsEffect", &QWidget::setGraphicsEffect)
        .def("setLayout", &QWidget::setLayout)
        .def("setMask", py::overload_cast<const QBitmap &>(&QWidget::setMask))
        .def("setMask", py::overload_cast<const QRegion &>(&QWidget::setMask))
        .def("setParent", py::overload_cast<QWidget *>(&QWidget::setParent))
        .def("setParent",
             py::overload_cast<QWidget *, Qt::WindowFlags>(&QWidget::setParent))
        //   .def("setScreen", &QWidget::setScreen)
        .def("setShortcutAutoRepeat", &QWidget::setShortcutAutoRepeat)
        .def("setShortcutEnabled", &QWidget::setShortcutEnabled)
        .def("setStyle", &QWidget::setStyle)
        .def("setWindowFlag", &QWidget::setWindowFlag)
        .def("setWindowRole", &QWidget::setWindowRole)
        .def("setWindowState", &QWidget::setWindowState)
        //   .def("setupUi", &QWidget::setupUi)
        .def("stackUnder", &QWidget::stackUnder)
        .def("style", &QWidget::style)
        .def("testAttribute", &QWidget::testAttribute)
        .def("underMouse", &QWidget::underMouse)
        .def("ungrabGesture", &QWidget::ungrabGesture)
        .def("unsetCursor", &QWidget::unsetCursor)
        .def("unsetLayoutDirection", &QWidget::unsetLayoutDirection)
        .def("unsetLocale", &QWidget::unsetLocale)
        .def("update", py::overload_cast<const QRect &>(&QWidget::update))
        .def("update", py::overload_cast<const QRegion &>(&QWidget::update))
        .def("update", py::overload_cast<int, int, int, int>(&QWidget::update))
        .def("updateGeometry", &QWidget::updateGeometry)
        //   .def("updateEnabled", &QWidget::updateEnabled)
        .def("visibleRegion", &QWidget::visibleRegion)
        .def("winId", &QWidget::winId)
        .def("window", &QWidget::window)
        .def("windowHandle", &QWidget::windowHandle)
        .def("windowRole", &QWidget::windowRole)
        .def("windowType", &QWidget::windowType);

    cls.def("actionEvent", &QWidget::actionEvent);
}
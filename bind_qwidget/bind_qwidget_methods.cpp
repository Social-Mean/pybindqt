#include <pybind11/pybind11.h>

#include <QWidget>
#include <QObject>

#include <QAction>
#include <QActionGroup>
#include <QApplication>
#include <QBackingStore>
#include <QBitmap>
#include <QClipboard>
#include <QColor>
#include <QCursor>
#include <QDesktopWidget>
#include <QFocusEvent>
#include <QGraphicsEffect>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsView>
#include <QIcon>
#include <QInputMethodEvent>
#include <QKeyEvent>
#include <QLayout>
#include <QLocale>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QRect>
#include <QRegion>
#include <QResizeEvent>
#include <QScreen>
#include <QSize>
#include <QSizePolicy>
#include <QStyle>
#include <QStyleOption>
#include <QStyleOptionFrame>
#include <QStyleOptionFrameV2>
#include <QStyleOptionFrameV3>
#include <QWindow>
#include <Qt>

#include <widgets_base.h>

namespace py = pybind11;

void bind_qwidget_methods(py::class_<QWidget, QObject> &cls) {
    cls
        //   .def(py::init([](QWidget *parent, Qt::WindowFlags flags) {
        //          return std::make_unique<QWidget>(parent, flags);
        //        }),
        //        py::arg("parent") = nullptr, py::arg("flags") =
        //        Qt::WindowFlags())
        .def("acceptDrops", &QWidget::acceptDrops)
        .def("accessibleDescription", &QWidget::accessibleDescription)
        //   .def("accessibleIdentifier", &QWidget::accessibleIdentifier)
        .def("accessibleName", &QWidget::accessibleName)
        .def("actions", &QWidget::actions)
        .def("activateWindow", &QWidget::activateWindow)
        .def("addAction", &QWidget::addAction)
        .def("addActions", &QWidget::addActions)
        .def("adjustSize", &QWidget::adjustSize)
        .def("autoFillBackground", &QWidget::autoFillBackground)
        .def("backgroundRole", &QWidget::backgroundRole)
        .def("backingStore", &QWidget::backingStore)
        .def("baseSize", &QWidget::baseSize)
        //   .def("childAt", py::overload_cast<int, int>(&QWidget::childAt))
        //   .def("childAt", py::overload_cast<const QPoint
        //   &>(&QWidget::childAt))
        .def("childrenRect", &QWidget::childrenRect)
        .def("childrenRegion", &QWidget::childrenRegion)
        .def("clearFocus", &QWidget::clearFocus)
        .def("clearMask", &QWidget::clearMask)
        .def("contentsMargins", &QWidget::contentsMargins)
        .def("contentsRect", &QWidget::contentsRect)
        .def("contextMenuPolicy", &QWidget::contextMenuPolicy)
        .def("cursor", &QWidget::cursor)
        .def("effectiveWinId", &QWidget::effectiveWinId)
        .def("ensurePolished", &QWidget::ensurePolished)
        .def("focusPolicy", &QWidget::focusPolicy)
        .def("focusProxy", &QWidget::focusProxy)
        .def("focusWidget", &QWidget::focusWidget)
        .def("font", &QWidget::font)
        .def("fontInfo", &QWidget::fontInfo)
        .def("fontMetrics", &QWidget::fontMetrics)
        .def("foregroundRole", &QWidget::foregroundRole)
        .def("frameGeometry", &QWidget::frameGeometry)
        .def("frameSize", &QWidget::frameSize)
        .def("geometry", &QWidget::geometry)
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
        .def("hasMouseTracking", &QWidget::hasMouseTracking)
        .def("hasTabletTracking", &QWidget::hasTabletTracking)
        .def("height", &QWidget::height)
        .def("heightForWidth", &QWidget::heightForWidth)
        .def("inputMethodHints", &QWidget::inputMethodHints)
        .def("inputMethodQuery", &QWidget::inputMethodQuery)
        .def("insertAction", &QWidget::insertAction)
        .def("insertActions", &QWidget::insertActions)
        .def("isActiveWindow", &QWidget::isActiveWindow)
        .def("isAncestorOf", &QWidget::isAncestorOf)
        .def("isEnabled", &QWidget::isEnabled)
        .def("isEnabledTo", &QWidget::isEnabledTo)
        .def("isFullScreen", &QWidget::isFullScreen)
        .def("isHidden", &QWidget::isHidden)
        .def("isMaximized", &QWidget::isMaximized)
        .def("isMinimized", &QWidget::isMinimized)
        .def("isModal", &QWidget::isModal)
        .def("isVisible", &QWidget::isVisible)
        .def("isVisibleTo", &QWidget::isVisibleTo)
        .def("isWindow", &QWidget::isWindow)
        .def("isWindowModified", &QWidget::isWindowModified)
        .def("layout", &QWidget::layout)
        .def("layoutDirection", &QWidget::layoutDirection)
        .def("locale", &QWidget::locale)
        .def("mapFrom", &QWidget::mapFrom)
        .def("mapFromGlobal", &QWidget::mapFromGlobal)
        .def("mapFromParent", &QWidget::mapFromParent)
        .def("mapTo", &QWidget::mapTo)
        .def("mapToGlobal", &QWidget::mapToGlobal)
        .def("mapToParent", &QWidget::mapToParent)
        .def("mask", &QWidget::mask)
        .def("maximumHeight", &QWidget::maximumHeight)
        .def("maximumSize", &QWidget::maximumSize)
        .def("maximumWidth", &QWidget::maximumWidth)
        .def("minimumHeight", &QWidget::minimumHeight)
        .def("minimumSize", &QWidget::minimumSize)
        .def("minimumSizeHint", &QWidget::minimumSizeHint)
        .def("minimumWidth", &QWidget::minimumWidth)
        //   .def("move", py::overload_cast<QPoint>(&QWidget::move))
        .def("move", py::overload_cast<int, int>(&QWidget::move))
        .def("nativeParentWidget", &QWidget::nativeParentWidget)
        //   .def("nativeFocusChain", &QWidget::nativeFocusChain)
        .def("normalGeometry", &QWidget::normalGeometry)
        .def("overrideWindowFlags", &QWidget::overrideWindowFlags)
        .def("palette", &QWidget::palette)
        .def("parentWidget", &QWidget::parentWidget)
        .def("pos", &QWidget::pos)
        .def("previousInFocusChain", &QWidget::previousInFocusChain)
        .def("rect", &QWidget::rect)
        .def("releaseKeyboard", &QWidget::releaseKeyboard)
        .def("releaseMouse", &QWidget::releaseMouse)
        .def("releaseShortcut", &QWidget::releaseShortcut)
        .def("removeAction", &QWidget::removeAction)
        //   .def("render", &QWidget::render)
        .def("repaint", py::overload_cast<const QRect &>(&QWidget::repaint))
        .def("repaint", py::overload_cast<const QRegion &>(&QWidget::repaint))
        .def("repaint", py::overload_cast<int, int, int, int>(&QWidget::repaint))
        .def("resize", py::overload_cast<const QSize &>(&QWidget::resize))
        .def("resize", py::overload_cast<int, int>(&QWidget::resize))
        .def("restoreGeometry", &QWidget::restoreGeometry)
        .def("saveGeometry", &QWidget::saveGeometry)
        .def("screen", &QWidget::screen)
        //   .def("scroll", &QWidget::scroll)
        .def("scroll", py::overload_cast<int, int>(&QWidget::scroll))
        .def("scroll",
             py::overload_cast<int, int, const QRect &>(&QWidget::scroll))
        .def("setAcceptDrops", &QWidget::setAcceptDrops)
        .def("setAccessibleDescription", &QWidget::setAccessibleDescription)
        //   .def("setAccessibleIdentifier", &QWidget::setAccessibleIdentifier)
        .def("setAccessibleName", &QWidget::setAccessibleName)
        .def("setAttribute", &QWidget::setAttribute)
        .def("setAutoFillBackground", &QWidget::setAutoFillBackground)
        .def("setBackgroundRole", &QWidget::setBackgroundRole)
        .def("setBaseSize",
             py::overload_cast<const QSize &>(&QWidget::setBaseSize))
        .def("setBaseSize", py::overload_cast<int, int>(&QWidget::setBaseSize))
        //   .def("setContentsMargins", &QWidget::setContentsMargins)
        .def("setContextMenuPolicy", &QWidget::setContextMenuPolicy)
        .def("setCursor", &QWidget::setCursor)
        // .def("setEditFocus", &QWidget::setEditFocus)
        .def("setFixedHeight", &QWidget::setFixedHeight)
        .def("setFixedSize",
             py::overload_cast<const QSize &>(&QWidget::setFixedSize))
        .def("setFixedSize", py::overload_cast<int, int>(&QWidget::setFixedSize))
        .def("setFixedWidth", &QWidget::setFixedWidth)
        //   .def("setFocus", &QWidget::setFocus)
        .def("setFocusPolicy", &QWidget::setFocusPolicy)
        .def("setFocusProxy", &QWidget::setFocusProxy)
        .def("setFont", &QWidget::setFont)
        .def("setForegroundRole", &QWidget::setForegroundRole)
        .def("setGeometry",
             py::overload_cast<const QRect &>(&QWidget::setGeometry))
        .def("setGeometry",
             py::overload_cast<int, int, int, int>(&QWidget::setGeometry))
        .def("setGraphicsEffect", &QWidget::setGraphicsEffect)
        .def("setInputMethodHints", &QWidget::setInputMethodHints)
        .def("setLayout", &QWidget::setLayout)
        .def("setLayoutDirection", &QWidget::setLayoutDirection)
        .def("setLocale", &QWidget::setLocale)
        .def("setMask", py::overload_cast<const QBitmap &>(&QWidget::setMask))
        .def("setMask", py::overload_cast<const QRegion &>(&QWidget::setMask))
        .def("setMaximumHeight", &QWidget::setMaximumHeight)
        .def("setMaximumSize",
             py::overload_cast<const QSize &>(&QWidget::setMaximumSize))
        .def("setMaximumSize",
             py::overload_cast<int, int>(&QWidget::setMaximumSize))
        .def("setMaximumWidth", &QWidget::setMaximumWidth)
        .def("setMinimumHeight", &QWidget::setMinimumHeight)
        .def("setMinimumSize",
             py::overload_cast<const QSize &>(&QWidget::setMinimumSize))
        .def("setMinimumSize",
             py::overload_cast<int, int>(&QWidget::setMinimumSize))
        .def("setMinimumWidth", &QWidget::setMinimumWidth)
        .def("setMouseTracking", &QWidget::setMouseTracking)
        .def("setPalette", &QWidget::setPalette)
        .def("setParent", py::overload_cast<QWidget *>(&QWidget::setParent))
        .def("setParent",
             py::overload_cast<QWidget *, Qt::WindowFlags>(&QWidget::setParent))
        //   .def("setScreen", &QWidget::setScreen)
        .def("setShortcutAutoRepeat", &QWidget::setShortcutAutoRepeat)
        .def("setShortcutEnabled", &QWidget::setShortcutEnabled)
        .def("setSizeIncrement",
             py::overload_cast<const QSize &>(&QWidget::setSizeIncrement))
        .def("setSizeIncrement",
             py::overload_cast<int, int>(&QWidget::setSizeIncrement))
        .def("setSizePolicy",
             py::overload_cast<QSizePolicy>(&QWidget::setSizePolicy))
        .def("setSizePolicy",
             py::overload_cast<QSizePolicy::Policy, QSizePolicy::Policy>(
                 &QWidget::setSizePolicy))
        .def("setStatusTip", &QWidget::setStatusTip)
        .def("setStyle", &QWidget::setStyle)
        .def("setTabletTracking", &QWidget::setTabletTracking)
        .def("setToolTip", &QWidget::setToolTip)
        .def("setToolTipDuration", &QWidget::setToolTipDuration)
        .def("setUpdatesEnabled", &QWidget::setUpdatesEnabled)
        .def("setWhatsThis", &QWidget::setWhatsThis)
        .def("setWindowFilePath", &QWidget::setWindowFilePath)
        .def("setWindowFlag", &QWidget::setWindowFlag)
        .def("setWindowFlags", &QWidget::setWindowFlags)
        .def("setWindowIcon", &QWidget::setWindowIcon)
        .def("setWindowModality", &QWidget::setWindowModality)
        .def("setWindowOpacity", &QWidget::setWindowOpacity)
        .def("setWindowRole", &QWidget::setWindowRole)
        .def("setWindowState", &QWidget::setWindowState)
        //   .def("setupUi", &QWidget::setupUi)
        .def("size", &QWidget::size)
        .def("sizeHint", &QWidget::sizeHint)
        .def("sizeIncrement", &QWidget::sizeIncrement)
        .def("sizePolicy", &QWidget::sizePolicy)
        .def("stackUnder", &QWidget::stackUnder)
        .def("statusTip", &QWidget::statusTip)
        .def("style", &QWidget::style)
        .def("styleSheet", &QWidget::styleSheet)
        .def("testAttribute", &QWidget::testAttribute)
        .def("toolTip", &QWidget::toolTip)
        .def("toolTipDuration", &QWidget::toolTipDuration)
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
        .def("whatsThis", &QWidget::whatsThis)
        .def("width", &QWidget::width)
        .def("winId", &QWidget::winId)
        .def("window", &QWidget::window)
        .def("windowFilePath", &QWidget::windowFilePath)
        .def("windowFlags", &QWidget::windowFlags)
        .def("windowHandle", &QWidget::windowHandle)
        .def("windowIcon", &QWidget::windowIcon)
        .def("windowModality", &QWidget::windowModality)
        .def("windowOpacity", &QWidget::windowOpacity)
        .def("windowRole", &QWidget::windowRole)
        .def("windowState", &QWidget::windowState)
        .def("windowTitle", &QWidget::windowTitle)
        .def("windowType", &QWidget::windowType)
        .def("x", &QWidget::x)
        .def("y", &QWidget::y);
}
#include <pybind11/pybind11.h>

#include <QTimer>

#include "widgets_base.h"

namespace py = pybind11;

void bind_enum(py::module_ &m) {
    py::enum_<Qt::TimerType>(m, "TimerType")
        .value("PreciseTimer", Qt::PreciseTimer)
        .value("CoarseTimer", Qt::CoarseTimer)
        .value("VeryCoarseTimer", Qt::VeryCoarseTimer)
        .export_values();

    py::enum_<Qt::WindowType>(m, "WindowType")
        .value("Widget", Qt::Widget)
        .value("Window", Qt::Window)
        .value("Dialog", Qt::Dialog)
        .value("Sheet", Qt::Sheet)
        .value("Drawer", Qt::Drawer)
        .value("Popup", Qt::Popup)
        .value("Tool", Qt::Tool)
        .value("ToolTip", Qt::ToolTip)
        .value("SplashScreen", Qt::SplashScreen)
        .value("Desktop", Qt::Desktop)
        .value("SubWindow", Qt::SubWindow)
        .value("ForeignWindow", Qt::ForeignWindow)
        .value("CoverWindow", Qt::CoverWindow)
        .value("WindowType_Mask", Qt::WindowType_Mask)
        .value("MSWindowsFixedSizeDialogHint", Qt::MSWindowsFixedSizeDialogHint)
        .value("MSWindowsOwnDC", Qt::MSWindowsOwnDC)
        .value("BypassWindowManagerHint", Qt::BypassWindowManagerHint)
        .value("X11BypassWindowManagerHint", Qt::X11BypassWindowManagerHint)
        .value("FramelessWindowHint", Qt::FramelessWindowHint)
        .value("WindowTitleHint", Qt::WindowTitleHint)
        .value("WindowSystemMenuHint", Qt::WindowSystemMenuHint)
        .value("WindowMinimizeButtonHint", Qt::WindowMinimizeButtonHint)
        .value("WindowMaximizeButtonHint", Qt::WindowMaximizeButtonHint)
        .value("WindowMinMaxButtonsHint", Qt::WindowMinMaxButtonsHint)
        .value("WindowContextHelpButtonHint", Qt::WindowContextHelpButtonHint)
        .value("WindowShadeButtonHint", Qt::WindowShadeButtonHint)
        .value("WindowStaysOnTopHint", Qt::WindowStaysOnTopHint)
        .value("WindowTransparentForInput", Qt::WindowTransparentForInput)
        .value("WindowOverridesSystemGestures", Qt::WindowOverridesSystemGestures)
        .value("WindowDoesNotAcceptFocus", Qt::WindowDoesNotAcceptFocus)
        .value("MaximizeUsingFullscreenGeometryHint",
               Qt::MaximizeUsingFullscreenGeometryHint)
        .value("CustomizeWindowHint", Qt::CustomizeWindowHint)
        .value("WindowStaysOnBottomHint", Qt::WindowStaysOnBottomHint)
        .value("WindowCloseButtonHint", Qt::WindowCloseButtonHint)
        .value("MacWindowToolBarButtonHint", Qt::MacWindowToolBarButtonHint)
        .value("BypassGraphicsProxyWidget", Qt::BypassGraphicsProxyWidget)
        .value("NoDropShadowWindowHint", Qt::NoDropShadowWindowHint)
        .value("WindowFullscreenButtonHint", Qt::WindowFullscreenButtonHint)
        .export_values();

    py::enum_<Qt::ToolBarArea>(m, "ToolBarArea")
        .value("LeftToolBarArea", Qt::LeftToolBarArea)
        .value("RightToolBarArea", Qt::RightToolBarArea)
        .value("TopToolBarArea", Qt::TopToolBarArea)
        .value("BottomToolBarArea", Qt::BottomToolBarArea)
        .value("ToolBarArea_Mask", Qt::ToolBarArea_Mask)
        .value("AllToolBarAreas", Qt::AllToolBarAreas)
        .value("NoToolBarArea", Qt::NoToolBarArea)
        .export_values();
}

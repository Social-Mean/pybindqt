cmake_minimum_required(VERSION 3.27)



project(pybindqt)

# 设置虚拟环境路径
set(VENV_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.venv")
set(VENV_PYTHON "${VENV_DIR}/Scripts/python.exe")
set(VENV_SITE_PACKAGES "${VENV_DIR}/Lib/site-packages")

# 设置Python查找路径
set(Python3_FIND_REGISTRY "NEVER")
set(Python3_FIND_STRATEGY "LOCATION")
set(Python3_FIND_VIRTUALENV "FIRST")

# 设置Python可执行文件路径
set(Python3_EXECUTABLE "${VENV_PYTHON}")

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 CONFIG REQUIRED HINTS "${VENV_SITE_PACKAGES}")

# 查找Qt5，如果找不到则尝试Qt6
find_package(Qt5 EXACT 5.15.2 QUIET COMPONENTS Core Gui Widgets)

message(STATUS "Python executable: ${Python3_EXECUTABLE}")
message(STATUS "Python library: ${Python3_INCLUDE_DIRS}")
message(STATUS "Virtual environment site-packages: ${VENV_SITE_PACKAGES}")
message(STATUS "Qt5 found: ${Qt5_FOUND}")

include_directories(${Python3_INCLUDE_DIRS})
link_directories(${Python3_LIBRARIES}/python38.lib)

add_library(Signal STATIC signal.cpp)
target_link_libraries(Signal PUBLIC pybind11::pybind11)
target_link_libraries(Signal PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
target_link_libraries(Signal PRIVATE ${Python3_LIBRARIES}/python38.lib)

# add_library(CustomPushButton STATIC CustomPushButton.cpp)
# target_link_libraries(CustomPushButton PRIVATE Signal Qt5::Widgets)
# target_link_libraries(CustomPushButton PRIVATE ${Python3_LIBRARIES}/python38.lib)
pybind11_add_module(QtWidgets
    qtwidgets.cpp
    widgets_base.cpp
    # pb_qpushbutton.cpp
)
target_link_libraries(QtWidgets PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
target_link_libraries(QtWidgets PRIVATE Signal)

# pybind11_add_module(QtCore qtcore.cpp)
# target_link_libraries(QtCore PRIVATE Qt5::Core)
# target_link_libraries(QtCore PRIVATE Signal)






cmake_minimum_required(VERSION 3.27)
project(pybindqt)

set(Python3_FIND_REGISTRY "NEVER")

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 CONFIG REQUIRED HINTS "${Python3_SITELIB}")
find_package(Qt5 EXACT 5.15.2 QUIET COMPONENTS Xml OpenGL Gui Svg LinguistTools)

message(STATUS "Python library: ${Python3_INCLUDE_DIRS}")
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
    CustomPushButton.cpp
)
target_link_libraries(QtWidgets PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
target_link_libraries(QtWidgets PRIVATE Signal)

pybind11_add_module(QtCore qtcore.cpp)
target_link_libraries(QtCore PRIVATE Qt5::Core)
target_link_libraries(QtCore PRIVATE Signal)






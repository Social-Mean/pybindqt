cmake_minimum_required(VERSION 3.27)

find_package(Python3 3.8.10 EXACT REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED HINTS "${Python3_SITELIB}")
find_package(Qt5 EXACT 5.15.2 QUIET COMPONENTS Xml OpenGL Gui Svg LinguistTools)

pybind11_add_module(QtWidget qapplication.cpp)
target_link_libraries(QtWidget PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)

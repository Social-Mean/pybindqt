cmake_minimum_required(VERSION 3.27)

project(pybindqt)

if(MSVC)
    # 对于Visual Studio编译器
    add_compile_options(/utf-8)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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

pybind11_add_module(QtWidgets
    qtwidgets.cpp
    bind_qstring.cpp
    bind_qflags.cpp
    bind_qwidget.cpp
    bind_qapplication.cpp
    bind_qmainwindow.cpp
    bind_qobject.cpp
    bind_qabstractbutton.cpp
    bind_qpushbutton.cpp
    bind_enum.cpp
)
target_link_libraries(QtWidgets PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
target_compile_definitions(QtWidgets PRIVATE PYBIND11_DETAILED_ERROR_MESSAGES)
# Windows 平台特定的部署和生成命令
if(WIN32)
    # 先从环境变量 QTDIR 获取 windeployqt.exe 路径
    if(DEFINED ENV{QTDIR})
        set(WINDEPLOYQT_EXE "$ENV{QTDIR}/bin/windeployqt.exe")
    else()
        message(FATAL_ERROR "环境变量 QTDIR 未设置，无法找到 windeployqt.exe")
    endif()

    # 获取 QtWidgets 模块的实际输出文件名
    get_target_property(QTWIDGETS_OUTPUT_NAME QtWidgets OUTPUT_NAME)
    if(NOT QTWIDGETS_OUTPUT_NAME)
        set(QTWIDGETS_OUTPUT_NAME "QtWidgets")
    endif()

    # 部署 QtWidgets
    add_custom_command(
        TARGET QtWidgets POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "windeployqt..."
        COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_CURRENT_BINARY_DIR} ${WINDEPLOYQT_EXE} $<TARGET_FILE_NAME:QtWidgets>
        COMMENT "编译后自动运行 windeployqt 部署 QtWidgets"
    )

    # 生成 stub 文件
    add_custom_command(
        TARGET QtWidgets POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "生成 stub 文件..."
        COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_CURRENT_BINARY_DIR} uv run stubgen -p QtWidgets --include-docstrings -o .
        COMMENT "编译后自动生成 QtWidgets 的 stub 文件"
    )
endif()






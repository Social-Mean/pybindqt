cmake_minimum_required(VERSION 3.27)

project(pybindqt)

if(MSVC)
    # 对于Visual Studio编译器
    add_compile_options(/utf-8)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/pybindqt)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/pybindqt)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/pybindqt)

message(STATUS "CMAKE_LIBRARY_OUTPUT_DIRECTORY: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")



add_library(pbq_pch_interface INTERFACE)
target_precompile_headers(pbq_pch_interface INTERFACE
    src/pbq_pch.h
)

link_libraries(pbq_pch_interface)


find_package(Boost REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

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
message(STATUS "Python include: ${Python3_INCLUDE_DIRS}")
message(STATUS "Python library: ${Python3_LIBRARIES}")
message(STATUS "Virtual environment site-packages: ${VENV_SITE_PACKAGES}")
message(STATUS "Qt5 found: ${Qt5_FOUND}")

# include_directories(${Python3_INCLUDE_DIRS})
# link_directories(${Python3_LIBRARIES}/python38.lib)
# link_libraries(${Python3_LIBRARIES})

add_subdirectory(src/QtCore)

add_subdirectory(src/QtWidgets.pbq/bind_qobject)
add_subdirectory(src/QtWidgets.pbq/bind_qwidget)
add_subdirectory(src/QtWidgets.pbq/bind_qmainwindow)
add_subdirectory(src/QtWidgets.pbq/bind_qabstractbutton)
add_subdirectory(src/QtWidgets.pbq/bind_qpushbutton)

pybind11_add_module(QtWidgets
    src/qtwidgets.cpp
    # src/qstring_converter.cpp
    src/bind_qstring.cpp
    src/bind_qflags.cpp
    src/bind_qapplication.cpp
    src/bind_enum.cpp
    src/bind_signal.cpp
    ${BIND_QOBJECT_SOURCES}
    ${BIND_QWIDGET_SOURCES}
    ${BIND_QMAINWINDOW_SOURCES}
    ${BIND_QABSTRACTBUTTON_SOURCES}
    ${BIND_QPUSHBUTTON_SOURCES}
)
target_include_directories(QtWidgets PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
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
        COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ${WINDEPLOYQT_EXE} $<TARGET_FILE_NAME:QtWidgets> > NUL 2>&1
        COMMENT "编译后自动运行 windeployqt 部署 QtWidgets"
    )

    # 生成 stub 文件
    add_custom_command(
        TARGET QtWidgets POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "生成 stub 文件..."
        COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} uv run stubgen -p QtWidgets --include-docstrings -o .
        COMMENT "编译后自动生成 QtWidgets 的 stub 文件"
    )
endif()


project(QtWidgets)

add_subdirectory(QWidget.pbq)
add_subdirectory(QAbstractButton.pbq)
add_subdirectory(QMainWindow.pbq)
add_subdirectory(QObject.pbq)
add_subdirectory(QPushButton.pbq)

pybind11_add_module(QtWidgets
    qtwidgets.cpp
    bind_qapplication.cpp
    ${BIND_QOBJECT_SOURCES}
    ${BIND_QWIDGET_SOURCES}
    ${BIND_QMAINWINDOW_SOURCES}
    ${BIND_QABSTRACTBUTTON_SOURCES}
    ${BIND_QPUSHBUTTON_SOURCES}
)
target_include_directories(QtWidgets PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(QtWidgets PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
target_compile_definitions(QtWidgets PRIVATE PYBIND11_DETAILED_ERROR_MESSAGES)

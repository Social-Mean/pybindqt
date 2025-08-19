project(QtCore)

add_subdirectory(QObject.pbq)

pybind11_add_module(QtCore
    QtCore.pbq.cpp
    Qt.pbq.cpp
    bind_qflags.cpp
    bind_qstring.cpp
    bind_enum.cpp
    bind_signal.cpp
    ${BIND_QOBJECT_SOURCES}
)

target_link_libraries(QtCore PRIVATE Qt5::Core Qt5::Widgets Qt5::Gui)

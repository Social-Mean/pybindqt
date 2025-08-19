project(QtCore)

pybind11_add_module(QtCore
    QtCore.pbq.cpp
    Qt.pbq.cpp
    bind_qflags.cpp
    bind_qstring.cpp
    bind_enum.cpp
    bind_signal.cpp
)

target_link_libraries(QtCore PRIVATE Qt5::Core Qt5::Widgets Qt5::Gui)

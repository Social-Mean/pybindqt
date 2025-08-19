project(QtWidgets)

add_subdirectory(bind_qobject)
add_subdirectory(bind_qwidget)
add_subdirectory(bind_qmainwindow)
add_subdirectory(bind_qabstractbutton)
add_subdirectory(bind_qpushbutton)

pybind11_add_module(QtWidgets
    qtwidgets.cpp
    # src/qstring_converter.cpp
    bind_qstring.cpp
    bind_qflags.cpp
    bind_qapplication.cpp
    bind_enum.cpp
    bind_signal.cpp
    ${BIND_QOBJECT_SOURCES}
    ${BIND_QWIDGET_SOURCES}
    ${BIND_QMAINWINDOW_SOURCES}
    ${BIND_QABSTRACTBUTTON_SOURCES}
    ${BIND_QPUSHBUTTON_SOURCES}
)
target_include_directories(QtWidgets PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(QtWidgets PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
target_compile_definitions(QtWidgets PRIVATE PYBIND11_DETAILED_ERROR_MESSAGES)


    # 获取 QtWidgets 模块的实际输出文件名
    get_target_property(QTWIDGETS_OUTPUT_NAME QtWidgets OUTPUT_NAME)
    if(NOT QTWIDGETS_OUTPUT_NAME)
        set(QTWIDGETS_OUTPUT_NAME "QtWidgets")
    endif()

    # 部署 QtWidgets
    # add_custom_command(
    #     TARGET QtWidgets POST_BUILD
    #     COMMAND ${CMAKE_COMMAND} -E echo "windeployqt..."
    #     COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ${WINDEPLOYQT_EXE} $<TARGET_FILE_NAME:QtWidgets> > NUL 2>&1
    #     COMMENT "编译后自动运行 windeployqt 部署 QtWidgets"
    # )

    # 生成 stub 文件
    add_custom_command(
        TARGET QtWidgets POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "生成 stub 文件..."
        COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} uv run stubgen -p QtWidgets --include-docstrings -o .
        COMMENT "编译后自动生成 QtWidgets 的 stub 文件"
    )

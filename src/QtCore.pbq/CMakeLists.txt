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

install(TARGETS QtCore
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)



if(WIN32)
    # 先从环境变量 QTDIR 获取 windeployqt.exe 路径
    if(DEFINED ENV{QTDIR})
        set(WINDEPLOYQT_EXE "$ENV{QTDIR}/bin/windeployqt.exe")
    else()
        message(FATAL_ERROR "环境变量 QTDIR 未设置，无法找到 windeployqt.exe")
    endif()

    # 获取 QtCore 模块的实际输出文件名
    get_target_property(QTCORE_OUTPUT_NAME QtCore OUTPUT_NAME)
    if(NOT QTCORE_OUTPUT_NAME)
        set(QTCORE_OUTPUT_NAME "QtCore")
    endif()

    # # 部署 QtCore
    # add_custom_command(
    #     TARGET QtCore POST_BUILD
    #     COMMAND ${CMAKE_COMMAND} -E echo "windeployqt..."
    #     COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ${WINDEPLOYQT_EXE} $<TARGET_FILE_NAME:QtCore># > NUL 2>&1
    #     COMMENT "编译后自动运行 windeployqt 部署 QtCore"
    # )

    # 生成 stub 文件
    add_custom_command(
        TARGET QtCore POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "生成 stub 文件..."
        COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} uv run stubgen -p QtCore --include-docstrings -o .
        COMMENT "编译后自动生成 QtCore 的 stub 文件"
    )
endif()
project(bind_qmainwindow)

file(GLOB BIND_QMAINWINDOW_SOURCES
    CONFIGURE_DEPENDS  # 重要：当添加新文件时自动重新生成 build system
    "*.cpp"
)
set(BIND_QMAINWINDOW_SOURCES ${BIND_QMAINWINDOW_SOURCES} PARENT_SCOPE)
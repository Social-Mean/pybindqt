project(bind_qwidget)

file(GLOB BIND_QWIDGET_SOURCES
    CONFIGURE_DEPENDS  # 重要：当添加新文件时自动重新生成 build system
    "*.cpp"
)
set(BIND_QWIDGET_SOURCES ${BIND_QWIDGET_SOURCES} PARENT_SCOPE)
project(bind_qpushbutton)

file(GLOB BIND_QPUSHBUTTON_SOURCES
    CONFIGURE_DEPENDS  # 重要：当添加新文件时自动重新生成 build system
    "*.cpp"
)
set(BIND_QPUSHBUTTON_SOURCES ${BIND_QPUSHBUTTON_SOURCES} PARENT_SCOPE)
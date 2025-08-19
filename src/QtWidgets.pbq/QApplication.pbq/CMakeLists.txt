project(bind_qapplication)

file(GLOB BIND_QAPPLICATION_SOURCES
    CONFIGURE_DEPENDS  # 重要：当添加新文件时自动重新生成 build system
    "*.cpp"
)
set(BIND_QAPPLICATION_SOURCES ${BIND_QAPPLICATION_SOURCES} PARENT_SCOPE)
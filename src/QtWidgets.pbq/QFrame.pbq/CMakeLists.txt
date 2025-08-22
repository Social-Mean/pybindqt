project(bind_qframe)

file(GLOB BIND_QFRAME_SOURCES
    CONFIGURE_DEPENDS  # 重要：当添加新文件时自动重新生成 build system
    "*.cpp"
)
set(BIND_QFRAME_SOURCES ${BIND_QFRAME_SOURCES} PARENT_SCOPE)
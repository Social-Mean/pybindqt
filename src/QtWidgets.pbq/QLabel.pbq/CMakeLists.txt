project(bind_qlabel)

file(GLOB BIND_QLABEL_SOURCES
    CONFIGURE_DEPENDS  # 重要：当添加新文件时自动重新生成 build system
    "*.cpp"
)
set(BIND_QLABEL_SOURCES ${BIND_QLABEL_SOURCES} PARENT_SCOPE)
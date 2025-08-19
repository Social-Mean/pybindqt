project(bind_qobject)

file(GLOB BIND_QOBJECT_SOURCES
    CONFIGURE_DEPENDS  # 重要：当添加新文件时自动重新生成 build system
    "*.cpp"
)
set(BIND_QOBJECT_SOURCES ${BIND_QOBJECT_SOURCES} PARENT_SCOPE)
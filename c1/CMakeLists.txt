cmake_minimum_required(VERSION 3.16)
project(c1 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 查找 Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# 收集源文件（显式列出，避免依赖未定义的 PROJECT_SOURCES）
set(SOURCES
    mainai.cpp
    win.cpp
    win1.cpp
    AI.cpp
)

set(HEADERS
    win.h
    win1.h
    AI.h
    mainai.h
)

set(UIS
    win.ui
    win1.ui
)

# 注意：Qt6 中，qt_add_library 自动处理 .ui/.h/.qrc 等
qt_add_library(c1_lib STATIC
    ${SOURCES}
    ${HEADERS}
    ${UIS}
    mainai.h
)

# 链接 Qt 模块
target_link_libraries(c1_lib PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

# 可选：导出头文件路径（便于其他项目 include）
target_include_directories(c1_lib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/c1>
)

# 安装规则：静态库 + 头文件
install(TARGETS c1_lib
    EXPORT c1Targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY Header\ Files/ DESTINATION include/c1 FILES_MATCHING PATTERN "*.h")
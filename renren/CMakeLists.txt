cmake_minimum_required(VERSION 3.16)
project(untitled5 VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set up AUTOMOC and some sensible defaults for runtime execution
# When using Qt 6.3, you can replace the code block below with
# qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)
include(GNUInstallDirs)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

#qt_add_executable(untitled5 WIN32 MACOSX_BUNDLE
 #   chessboard3.cpp chessboard3.h chessboard3.ui
  #  demo.cpp demo.h
#
 #   record.cpp record.h record.ui

#)

add_library(renren_lib STATIC # 或者 SHARED

          ${PROJECT_SOURCES}
          chessboard3.h chessboard3.cpp chessboard3.ui
          record.h record.cpp record.ui
          demo.cpp demo.h
      )

#target_link_libraries(untitled5 PRIVATE
 #   Qt::Core
  #  Qt::Gui
   # Qt::Widgets
#)
target_link_libraries(renren_lib PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
#install(TARGETS untitled5
 #   BUNDLE DESTINATION .
  #  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)
install(TARGETS renren_lib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}  # 静态库路径
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}  # 动态库路径（如果以后改用 SHARED）
)

# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.

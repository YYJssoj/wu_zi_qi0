cmake_minimum_required(VERSION 3.16)
project(untitled3 VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set up AUTOMOC and some sensible defaults for runtime execution
# When using Qt 6.3, you can replace the code block below with
# qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)
include(GNUInstallDirs)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

#qt_add_executable(untitled3 WIN32 MACOSX_BUNDLE
 #   chessboard.cpp chessboard.h chessboard.ui
  #  demo.cpp demo.h
#
 #   record_2.cpp record_2.h record_2.ui

#)


add_library(renji_lib STATIC # 或者 SHARED

          ${PROJECT_SOURCES}
          chessboard2.h chessboard2.cpp chessboard2.ui
          record_2.h record_2.cpp record_2.ui
          demo.cpp demo.h
      )
#target_link_libraries(untitled3 PRIVATE
   # Qt::Core
  #  Qt::Gui
 #   Qt::Widgets
#)
target_link_libraries(renji_lib PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


#install(TARGETS untitled3
 #   BUNDLE DESTINATION .
  #  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)
install(TARGETS renji_lib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}  # 静态库路径
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}  # 动态库路径（如果以后改用 SHARED）
)
# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.

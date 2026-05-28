cmake_minimum_required(VERSION 3.16)
project(wu_zi_qi VERSION 1.0 LANGUAGES C CXX)
# 引入 wuziqi2 子目录
add_subdirectory(wuziqi2)
add_subdirectory(renren)
add_subdirectory(renji)
add_subdirectory(c1)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set up AUTOMOC and some sensible defaults for runtime execution
# When using Qt 6.3, you can replace the code block below with
# qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)
include(GNUInstallDirs)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Widgets)

qt_add_executable(wu_zi_qi WIN32 MACOSX_BUNDLE
    demo1.cpp demo1.h
    forget_pw.cpp forget_pw.h forget_pw.ui
    global.h
    login.cpp login.h login.ui
    main.cpp
    mainw.cpp mainw.h mainw.ui
    set_pw.cpp set_pw.h set_pw.ui
    set_question.cpp set_question.h set_question.ui
    widget.cpp widget.h widget.ui
    zhu_ce.cpp zhu_ce.h zhu_ce.ui

)
target_link_libraries(wu_zi_qi PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
      wuziqi2_lib
      renren_lib
      renji_lib
      c1_lib
)


# Resources:
set(loading_resource_files
        "1.png"
        "2.png"
)

qt_add_resources(wu_zi_qi "loading"
        PREFIX
        "/new/prefix1"
        FILES
        ${loading_resource_files}
)

install(TARGETS wu_zi_qi
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Consider using qt_generate_deploy_app_script() for app deployment if
# the project can use Qt 6.3. In that case rerun qmake2cmake with
# --min-qt-version=6.3.

QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    demo1.cpp \
    forget_pw.cpp \
    login.cpp \
    main.cpp \
    mainw.cpp \
    set_pw.cpp \
    set_question.cpp \
    widget.cpp \
    zhu_ce.cpp

HEADERS += \
    demo1.h \
    forget_pw.h \
    global.h \
    login.h \
    mainw.h \
    set_pw.h \
    set_question.h \
    widget.h \
    zhu_ce.h

FORMS += \
    forget_pw.ui \
    login.ui \
    mainw.ui \
    set_pw.ui \
    set_question.ui \
    widget.ui \
    zhu_ce.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    loading.qrc

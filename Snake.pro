QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    frame.cpp \
    gamefield.cpp \
    gamestat.cpp \
    main.cpp \
    mainmenu.cpp \
    settingframe.cpp \
    snakebody.cpp \
    window.cpp

HEADERS += \
    frame.h \
    gamefield.h \
    gamestat.h \
    mainmenu.h \
    settingframe.h \
    snakebody.h \
    window.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

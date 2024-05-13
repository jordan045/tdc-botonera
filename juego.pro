QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boton.cpp \
    botonera.cpp \
    center.cpp \
    display.cpp \
    icm.cpp \
    initmenu.cpp \
    label.cpp \
    main.cpp \
    mainwindow.cpp \
    qek.cpp \
    range.cpp \
    threat.cpp

HEADERS += \
    boton.h \
    botonera.h \
    center.h \
    display.h \
    icm.h \
    initmenu.h \
    label.h \
    mainwindow.h \
    qek.h \
    range.h \
    threat.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rsc.qrc

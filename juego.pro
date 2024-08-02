
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += uitools

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boton.cpp \
    botonera.cpp \
    center.cpp \
    estado.cpp \
    display_mode.cpp \
    display_selection.cpp \
    formatconcentrator.cpp \
    icm.cpp \
    initmenu.cpp \
    label.cpp \
    main.cpp \
    mainwindow.cpp \
    overlay_140_0001.cpp \
    overlay_140_0010.cpp \
    overlay_140_0011.cpp \
    overlay_140_0100.cpp \
    qek.cpp \
    range.cpp \
    threat.cpp \
    zone_icm.cpp \
    zone_range.cpp

HEADERS += \
    Zone.h \
    boton.h \
    botonera.h \
    center.h \
    estado.h \
    display_mode.h \
    display_selection.h \
    formatconcentrator.h \
    icm.h \
    initmenu.h \
    label.h \
    mainwindow.h \
    overlay_140_0001.h \
    overlay_140_0010.h \
    overlay_140_0011.h \
    overlay_140_0100.h \
    qek.h \
    range.h \
    threat.h \
    zone_icm.h \
    zone_range.h

FORMS += \
    0001.ui \
    0010.ui \
    0011.ui \
    0100.ui \
    mainwindow.ui \
    overlay_140_0001.ui \
    overlay_140_0010.ui \
    overlay_140_0011.ui \
    overlay_140_0100.ui \
    zone_icm.ui \
    zone_range.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    overlay.json

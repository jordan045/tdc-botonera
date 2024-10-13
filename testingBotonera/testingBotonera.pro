QT += testlib core
QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

INCLUDEPATH += \
    $$PWD/../botonera/headers \
    $$PWD/../botonera/sources

DEPENDPATH += \
    $$PWD/../botonera/headers \
    $$PWD/../botonera/sources

TEMPLATE = app

HEADERS += \
    $$PWD/../botonera/headers/formatconcentrator.h \
    $$PWD/../botonera/headers/iestado.h \
    bitarrayutils.h \
    driverestado.h

SOURCES +=  \
    bitarrayutils.cpp \
    driverestado.cpp \
    tst_formatconcentratortest.cpp \
    $$PWD/../botonera/sources/formatconcentrator.cpp

RESOURCES += \
    $$PWD/../botonera/resources.qrc

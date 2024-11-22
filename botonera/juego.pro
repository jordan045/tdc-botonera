QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += uitools
# QT += remoteobjects  #Invocacion remota de metodos

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/andGui.cpp \
    sources/AndTranslator.cpp \
    sources/boton.cpp \
    sources/botonera.cpp \
    sources/botoneraMaster.cpp \
    sources/botoneraSlave.cpp \
    sources/cursorMessage.cpp \
    sources/decenteredimage.cpp \
    sources/estado.cpp \
    sources/formatconcentrator.cpp \
    sources/initmenu.cpp \
    sources/lpdDecoder.cpp \
    sources/main.cpp \
    sources/markerMessage.cpp \
    sources/mik.cpp \
    sources/overlay_140_0001.cpp \
    sources/overlay_140_0010.cpp \
    sources/overlay_140_0011.cpp \
    sources/overlay_140_0100.cpp \
    sources/overlay_360_0001.cpp \
    sources/overlay_360_0010.cpp \
    sources/overlay_360_0011.cpp \
    sources/overlay_360_0100.cpp \
    sources/overlay_360_0101.cpp \
    sources/overlay_360_0110.cpp \
    sources/overlay_360_0111.cpp \
    sources/overlay_360_1000.cpp \
    sources/zone_center.cpp \
    sources/zone_displaymode.cpp \
    sources/zone_displayselection.cpp \
    sources/zone_icm.cpp \
    sources/zone_label.cpp \
    sources/zone_range.cpp \
    sources/zone_threat.cpp \
    sources/transciever_fpga.cpp \

HEADERS += \
    headers/Zone.h \
    headers/andGui.h \
    headers/andTranslator.h \
    headers/boton.h \
    headers/botonera.h \
    headers/botoneraMaster.h \
    headers/botoneraSlave.h \
    headers/estado.h \
    headers/formatconcentrator.h \
    headers/iestado.h \
    headers/initmenu.h \
    headers/overlay_140_0001.h \
    headers/overlay_140_0010.h \
    headers/overlay_140_0011.h \
    headers/overlay_140_0100.h \
    headers/overlay_360_0001.h \
    headers/overlay_360_0010.h \
    headers/overlay_360_0011.h \
    headers/overlay_360_0100.h \
    headers/overlay_360_0101.h \
    headers/overlay_360_0110.h \
    headers/overlay_360_0111.h \
    headers/overlay_360_1000.h \
    headers/qek.h \
    headers/zone_center.h \
    headers/zone_displaymode.h \
    headers/zone_displayselection.h \
    headers/zone_icm.h \
    headers/zone_label.h \
    headers/zone_range.h \
    headers/zone_threat.h \
    headers/mik.h \
    headers/transciever_fpga.h \
    headers/cursorMessage.h \
    headers/decenteredimage.h \
    headers/lpdDecoder.h \
    headers/markerMessage.h

FORMS += \
    forms/andGrilla.ui \
    forms/andGui.ui \
    forms/overlay_140_0001.ui \
    forms/overlay_140_0010.ui \
    forms/overlay_140_0011.ui \
    forms/overlay_140_0100.ui \
    forms/overlay_360_0001.ui \
    forms/overlay_360_0010.ui \
    forms/overlay_360_0011.ui \
    forms/overlay_360_0100.ui \
    forms/overlay_360_0101.ui \
    forms/overlay_360_0110.ui \
    forms/overlay_360_0111.ui \
    forms/overlay_360_1000.ui \
    forms/zone_center.ui \
    forms/zone_displaymode.ui \
    forms/zone_displayselection.ui \
    forms/zone_icm.ui \
    forms/zone_label.ui \
    forms/zone_range.ui \
    forms/zone_threat.ui \
    initmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    json/overlay.json \
    json/mik.json \
    mensajesFC/mensajes.txt



INCLUDEPATH += headers/

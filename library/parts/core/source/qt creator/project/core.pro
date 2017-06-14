#-------------------------------------------------
#
# Project created by QtCreator 2017-06-14T15:03:09
#
#-------------------------------------------------

QT       -= core gui

TARGET = core
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += core.cpp \
    ../../new_code/general/global.cpp \
    ../../new_code/hardware/device.cpp \
    ../../new_code/hardware/gadget.cpp \
    ../../new_code/hardware/hardware.cpp \
    ../../new_code/hardware/inputgadget.cpp \
    ../../new_code/hardware/iogadget.cpp \
    ../../new_code/hardware/outputgadget.cpp \
    ../../new_code/interface/debuggable.cpp \
    ../../new_code/interface/monitorable.cpp \
    ../../new_code/interface/programmable.cpp \
    ../../new_code/interface/turnable.cpp \
    ../../new_code/software/software.cpp

HEADERS += core.h \
    ../../new_code/general/config.h \
    ../../new_code/general/global.h \
    ../../new_code/hardware/device.h \
    ../../new_code/hardware/gadget.h \
    ../../new_code/hardware/hardware.h \
    ../../new_code/hardware/inputgadget.h \
    ../../new_code/hardware/iogadget.h \
    ../../new_code/hardware/outputgadget.h \
    ../../new_code/interface/debuggable.h \
    ../../new_code/interface/monitorable.h \
    ../../new_code/interface/programmable.h \
    ../../new_code/interface/turnable.h \
    ../../new_code/software/software.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

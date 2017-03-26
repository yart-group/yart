#-------------------------------------------------
#
# Project created by QtCreator 2017-03-25T19:42:51
#
#-------------------------------------------------

QT       -= core gui

TARGET = arduino
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

SOURCES += arduino.cpp \
    device.cpp \
    gadget.cpp \
    inputgadget.cpp \
    outputgadget.cpp \
    iogadget.cpp \
    programmer/programmer.cpp \
    devices/robot.cpp \
    devices/usb.cpp \
    devices/flash.cpp \
    devices/pilot.cpp \
    gadgets/input/battery.cpp \
    gadgets/input/sensor.cpp \
    gadgets/io/cable.cpp \
    gadgets/output/motor.cpp \
    gadgets/output/chassis.cpp \
    gadgets/input/sensors/ultrasonicsensor.cpp \
    gadgets/input/sensors/infraredsensor.cpp \
    general/switch.cpp \
    programmer/port.cpp \
    programmer/kernel.cpp

HEADERS += arduino.h \
    device.h \
    gadget.h \
    inputgadget.h \
    outputgadget.h \
    iogadget.h \
    programmer/programmer.h \
    devices/robot.h \
    devices/usb.h \
    devices/flash.h \
    devices/pilot.h \
    gadgets/input/battery.h \
    gadgets/input/sensor.h \
    gadgets/io/cable.h \
    gadgets/output/motor.h \
    gadgets/output/chassis.h \
    gadgets/input/sensors/ultrasonicsensor.h \
    gadgets/input/sensors/infraredsensor.h \
    general/switch.h \
    programmer/port.h \
    programmer/kernel.h \
    general/config.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

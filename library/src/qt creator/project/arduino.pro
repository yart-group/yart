#-------------------------------------------------
#
# Project created by QtCreator 2017-05-03T12:55:08
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

unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    ../../src/general/config.h \
    ../../src/general/global.h \
    ../../src/hardware/devices/components/flash.h \
    ../../src/hardware/devices/components/microcontroller.h \
    ../../src/hardware/devices/components/pilot.h \
    ../../src/hardware/devices/components/robot.h \
    ../../src/hardware/devices/components/usb.h \
    ../../src/hardware/devices/gadgets/input/sensors/infraredsensor.h \
    ../../src/hardware/devices/gadgets/input/sensors/ultrasonicsensor.h \
    ../../src/hardware/devices/gadgets/input/battery.h \
    ../../src/hardware/devices/gadgets/input/sensor.h \
    ../../src/hardware/devices/gadgets/io/cable.h \
    ../../src/hardware/devices/gadgets/output/motor.h \
    ../../src/hardware/devices/component.h \
    ../../src/hardware/devices/gadget.h \
    ../../src/hardware/devices/inputgadget.h \
    ../../src/hardware/devices/iogadget.h \
    ../../src/hardware/devices/outputgadget.h \
    ../../src/hardware/devices/port.h \
    ../../src/hardware/debugmanager.h \
    ../../src/hardware/device.h \
    ../../src/hardware/logger.h \
    ../../src/hardware/meta.h \
    ../../src/software/commandtable.h \
    ../../src/software/driver.h \
    ../../src/software/kernel.h \
    ../../src/software/program.h \
    ../../src/hardware.h \
    ../../src/programmable.h \
    ../../src/software.h

SOURCES += \
    ../../src/general/global.cpp \
    ../../src/hardware/devices/components/flash.cpp \
    ../../src/hardware/devices/components/microcontroller.cpp \
    ../../src/hardware/devices/components/pilot.cpp \
    ../../src/hardware/devices/components/robot.cpp \
    ../../src/hardware/devices/components/usb.cpp \
    ../../src/hardware/devices/gadgets/input/sensors/infraredsensor.cpp \
    ../../src/hardware/devices/gadgets/input/sensors/ultrasonicsensor.cpp \
    ../../src/hardware/devices/gadgets/input/battery.cpp \
    ../../src/hardware/devices/gadgets/input/sensor.cpp \
    ../../src/hardware/devices/gadgets/io/cable.cpp \
    ../../src/hardware/devices/gadgets/output/motor.cpp \
    ../../src/hardware/devices/component.cpp \
    ../../src/hardware/devices/gadget.cpp \
    ../../src/hardware/devices/inputgadget.cpp \
    ../../src/hardware/devices/iogadget.cpp \
    ../../src/hardware/devices/outputgadget.cpp \
    ../../src/hardware/devices/port.cpp \
    ../../src/hardware/debugmanager.cpp \
    ../../src/hardware/device.cpp \
    ../../src/hardware/logger.cpp \
    ../../src/hardware/meta.cpp \
    ../../src/software/commandtable.cpp \
    ../../src/software/driver.cpp \
    ../../src/software/kernel.cpp \
    ../../src/software/program.cpp \
    ../../src/hardware.cpp \
    ../../src/programmable.cpp \
    ../../src/software.cpp



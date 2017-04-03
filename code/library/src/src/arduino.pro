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

#INCLUDEPATH += portable/sketchbook/libraries/makeblock/src
#INCLUDEPATH += hardware/arduino/avr/variants
##INCLUDEPATH += ../../../../../../../Program\ Files\ (x86)/mBlock/Arduino/hardware/arduino/avr/cores/arduino
#INCLUDEPATH += "C:/Program Files (x86)/mBlock/Arduino/hardware/arduino/avr/cores/arduino"
#INCLUDEPATH += hardware/tools/avr/avr/include

SOURCES += \
    device.cpp \
    gadget.cpp \
    inputgadget.cpp \
    outputgadget.cpp \
    iogadget.cpp \
    motherboard/motherboard.cpp \
    devices/robot.cpp \
    devices/usb.cpp \
    devices/flash.cpp \
    devices/pilot.cpp \
    gadgets/input/battery.cpp \
    gadgets/input/sensor.cpp \
    gadgets/io/cable.cpp \
    gadgets/output/motor.cpp \
    gadgets/input/sensors/ultrasonicsensor.cpp \
    gadgets/input/sensors/infraredsensor.cpp \
    general/port.cpp \
    motherboard/kernel.cpp \
    general/meta.cpp \
    motherboard/program.cpp \
    motherboard/driver.cpp \
    motherboard/programcontainer.cpp \
    motherboard/commandtable.cpp \
    motherboard/commandtable.cpp \
    motherboard/driver.cpp \
    motherboard/kernel.cpp \
    motherboard/program.cpp \
    motherboard/programcontainer.cpp \
    motherboard/motherboard.cpp \
    motherboard/commandtable.cpp \
    motherboard/driver.cpp \
    motherboard/kernel.cpp \
    motherboard/motherboard.cpp \
    motherboard/program.cpp \
    motherboard/programcontainer.cpp \
    debugmanager.cpp \
    logger.cpp

HEADERS += \
    device.h \
    gadget.h \
    inputgadget.h \
    outputgadget.h \
    iogadget.h \
    motherboard/motherboard.h \
    devices/robot.h \
    devices/usb.h \
    devices/flash.h \
    devices/pilot.h \
    gadgets/input/battery.h \
    gadgets/input/sensor.h \
    gadgets/io/cable.h \
    gadgets/output/motor.h \
    gadgets/input/sensors/ultrasonicsensor.h \
    gadgets/input/sensors/infraredsensor.h \
    general/port.h \
    motherboard/kernel.h \
    general/config.h \
    general/meta.h \
    motherboard/program.h \
    motherboard/driver.h \
    motherboard/programcontainer.h \
    motherboard/commandtable.h \
    motherboard/commandtable.h \
    motherboard/driver.h \
    motherboard/kernel.h \
    motherboard/program.h \
    motherboard/programcontainer.h \
    motherboard/motherboard.h \
    motherboard/commandtable.h \
    motherboard/driver.h \
    motherboard/kernel.h \
    motherboard/motherboard.h \
    motherboard/program.h \
    motherboard/programcontainer.h \
    debugmanager.h \
    logger.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += build.ino.cpp \
    ../components/source/chassis.cpp \
    ../components/source/component.cpp \
    ../components/source/flash.cpp \
    ../components/source/pilot.cpp \
    ../components/source/programmer.cpp \
    ../components/source/robot.cpp \
    ../components/source/usb.cpp \
    ../devices/source/cable.cpp \
    ../devices/source/device.cpp \
    ../devices/source/infraredsensor.cpp \
    ../devices/source/inputdevice.cpp \
    ../devices/source/iodevice.cpp \
    ../devices/source/motor.cpp \
    ../devices/source/outputdevice.cpp \
    ../devices/source/sensor.cpp \
    ../devices/source/ultrasonicsensor.cpp \
    ../drivers/source/menu.cpp \
    ../programs/source/manualcontrol.cpp \
    ../programs/source/stay.cpp \
    ../programs/source/walk.cpp

HEADERS += \
    config/config.h \
    config/paths.h \
    ../devices/include/cable.h \
    ../devices/include/device.h \
    ../devices/include/infraredsensor.h \
    ../devices/include/inputdevice.h \
    ../devices/include/iodevice.h \
    ../devices/include/motor.h \
    ../devices/include/outputdevice.h \
    ../devices/include/sensor.h \
    ../devices/include/ultrasonicsensor.h \
    ../components/include/chassis.h \
    ../components/include/component.h \
    ../components/include/flash.h \
    ../components/include/pilot.h \
    ../components/include/programmer.h \
    ../components/include/robot.h \
    ../components/include/usb.h \
    ../programs/include/manualcontrol.h \
    ../programs/include/stay.h \
    ../programs/include/walk.h \
    ../drivers/include/menu.h

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

# LIBS += -L/home/robert/Projects/current/Goofy/arduino/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug -larduino

SOURCES += main.cpp


unix:!macx: LIBS += -L$$PWD/../../../src/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug/ -larduino

INCLUDEPATH += $$PWD/../../../src/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug
DEPENDPATH += $$PWD/../../../src/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../src/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug/libarduino.a

HEADERS += \
    ../../../static/libarduino.h

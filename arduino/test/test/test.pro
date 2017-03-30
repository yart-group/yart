TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

# LIBS += -L/home/robert/Projects/current/Goofy/arduino/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug -larduino

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug/release/ -larduino
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug/debug/ -larduino
else:unix: LIBS += -L$$PWD/../../lib/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug/ -larduino

INCLUDEPATH += $$PWD/../../lib/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug
DEPENDPATH += $$PWD/../../lib/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug/release/libarduino.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug/debug/libarduino.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug/release/arduino.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug/debug/arduino.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../lib/build-arduino-Desktop_Qt_5_8_0_GCC_64bit-Debug/libarduino.a

HEADERS += \
    ../../lib/arduino/libarduino.h

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ODESolver.cpp \
        Planets.cpp \
        ReadFiles.cpp \
        SolarSystem.cpp \
        WriteResults.cpp \
        main.cpp

HEADERS += \
    ODESolver.h \
    Planets.h \
    ReadFiles.h \
    SolarSystem.h \
    WriteResults.h

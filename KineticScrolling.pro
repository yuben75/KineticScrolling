#-------------------------------------------------
#
# Project created by QtCreator 2010-11-13T11:07:32
#
#-------------------------------------------------

QT       += core gui

TARGET = KineticScrollingExample
TEMPLATE = app


SOURCES += main.cpp \
    FlickableList/flickablelist.cpp \
    FlickableList/flickable.cpp \
    examplewindow.cpp

HEADERS  += \
    FlickableList/flickablelist.h \
    FlickableList/flickable.h \
    examplewindow.h

FORMS    +=

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xe014c9be
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

RESOURCES += \
    icons.qrc

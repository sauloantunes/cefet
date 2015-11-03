#-------------------------------------------------
#
# Project created by QtCreator 2015-10-20T17:40:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lig4
TEMPLATE = app

SOURCES += main.cpp\
        Lig4.cpp \
    BotaoJogar.cpp \
    sobre.cpp \
    termino.cpp

HEADERS  += Lig4.h \
    BotaoJogar.h \
    sobre.h \
    termino.h

FORMS    += Lig4.ui \
    sobre.ui \
    termino.ui

RESOURCES += \
    lig4.qrc

LIBS += -lGL

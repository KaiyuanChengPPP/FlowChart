#-------------------------------------------------
#
# Project created by QtCreator 2014-07-12T03:36:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlowChart
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    flowchart.cpp \
    symbol.cpp

HEADERS  += mainwindow.h \
    flowchart.h \
    symbol.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

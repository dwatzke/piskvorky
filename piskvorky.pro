QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = piskvorky
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += board.h mainwidget.h
SOURCES += board.cpp main.cpp mainwidget.cpp
TRANSLATIONS += piskvorky_cs_CZ.ts

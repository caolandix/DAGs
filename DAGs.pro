QT += core
QT -= gui

TARGET = DAGs
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    dagraph.cpp

HEADERS += \
    dagraph.h


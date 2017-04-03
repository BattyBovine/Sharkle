#-------------------------------------------------
#
# Project created by QtCreator 2017-04-01T17:38:19
#
#-------------------------------------------------

QT       += core gui svg multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sharkle
TEMPLATE = app


SOURCES += main.cpp\
        sharkle.cpp \
    sharkleview.cpp

HEADERS  += sharkle.h \
    sharkleview.h

FORMS    += sharkle.ui

RESOURCES += \
	data.qrc

RC_ICONS = res/sharkle.ico

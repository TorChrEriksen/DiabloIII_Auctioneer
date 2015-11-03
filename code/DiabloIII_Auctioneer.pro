#-------------------------------------------------
#
# Project created by QtCreator 2012-07-31T17:22:09
#
#-------------------------------------------------

QT       += core gui phonon

TARGET = DiabloIII_Auctioneer
TEMPLATE = app

SOURCES += main.cpp\
    gui/mainwindow.cpp \
    gui/newitem.cpp \
    data/item.cpp \
    models/itemmodel.cpp \
    control/itemmodelcontrol.cpp

HEADERS  += gui/mainwindow.h \
    gui/newitem.h \
    data/item.h \
    models/itemmodel.h \
    control/itemmodelcontrol.h

FORMS    += gui/mainwindow.ui \
    gui/newitem.ui

RESOURCES += \
    Resources.qrc

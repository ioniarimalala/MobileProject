#-------------------------------------------------
#
# Project created by QtCreator 2017-12-01T17:42:46
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetAfMobile
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    dataconnect.cpp \
    logindao.cpp \
    inscription.cpp \
    membre.cpp \
    membredao.cpp \
    netdataaccess.cpp \
    index.cpp \
    infodao.cpp \
    information.cpp \
    detailinfo.cpp

HEADERS  += mainwindow.h \
    login.h \
    dataconnect.h \
    logindao.h \
    inscription.h \
    membre.h \
    membredao.h \
    netdataaccess.h \
    index.h \
    infodao.h \
    information.h \
    detailinfo.h

FORMS    += mainwindow.ui \
    inscription.ui \
    index.ui \
    detailinfo.ui

CONFIG += mobility
MOBILITY = 

android
{
my_files.path = /assets
my_files.files += $$PWD/LOGIN/*
my_files.files += $$PWD/db/dbAft
INSTALLS += my_files
}
RESOURCES += \
    rsa.qrc

DISTFILES += \
    LOGIN/AndroidManifest.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/LOGIN

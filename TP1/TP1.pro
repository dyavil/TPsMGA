#-------------------------------------------------
#
# Project created by QtCreator 2013-09-12T03:27:41
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sierpinski
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gldisplay.cpp \
    gasket.cpp \
    mypoint.cpp \
    mytriangle.cpp \
    mymesh.cpp

HEADERS  += mainwindow.h \
    gldisplay.h \
    gasket.h \
    myvector.h \
    mypoint.h \
    mytriangle.h \
    mymesh.h

FORMS    += mainwindow.ui

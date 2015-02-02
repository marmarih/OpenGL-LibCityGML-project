#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T10:44:47
#
#-------------------------------------------------

QT       += core gui
QT += opengl

CONFIG  += qtestlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# TARGET = nom de l'executable
TARGET = OpenGL

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mqcam.cpp \
    glwidget.cpp \
    citygmlhandler.cpp \
    autotest.cpp \
    test/camtest.cpp \
    test/glwidgettest.cpp \
    test/cgmltest.cpp

HEADERS  += mainwindow.h \
    mqcam.h \
    glwidget.h \
    citygmlhandler.h \
    autotest.h \
    test/camtest.h \
    test/glwidgettest.h \
    test/cgmltest.h

FORMS    += mainwindow.ui


LIBS += -lGL -lGLU -lglut -lcitygml

QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS +=  -fopenmp

OBJECTS_DIR = ./obj
RCC_DIR = ./cpp

UI_HEADERS_DIR = ./ui/include
UI_SOURCES_DIR = ./ui/src

MOC_DIR = ./moc

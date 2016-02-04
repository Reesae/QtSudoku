#-------------------------------------------------
#
# Project created by QtCreator 2016-01-29T10:59:35
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtSudoku
TEMPLATE = app
CONFIG += c++14

INCLUDEPATH += C:/boost_1_59_0/
LIBS += "-LC:/boost_1_59_0/stage/lib/"

SOURCES += main.cpp\
        qtsudoku.cpp \
    sudokumodel.cpp \
    sudokuboardnode.cpp\
    testsudokuboardnode.cpp \
    testsudokumodel.cpp \
    sudokusquaremodel.cpp \
    testsudokusquaremodel.cpp \
    nodeview.cpp \
    sudokuview.cpp


HEADERS  += qtsudoku.h \
    sudokumodel.h \
    sudokuboardnode.h \
testsudokuboardnode.h \
    testsudokumodel.h \
    sudokusquaremodel.h \
    testsudokusquaremodel.h \
    nodeview.h \
    sudokuview.h


FORMS    += qtsudoku.ui

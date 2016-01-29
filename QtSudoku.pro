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

SOURCES += main.cpp\
        qtsudoku.cpp \
    sudokumodel.cpp \
    sudokuboardnode.cpp\
    testsudokuboardnode.cpp


HEADERS  += qtsudoku.h \
    sudokumodel.h \
    sudokuboardnode.h \
testsudokuboardnode.h


FORMS    += qtsudoku.ui

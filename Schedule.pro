#-------------------------------------------------
#
# Project created by QtCreator 2012-07-05T20:43:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Schedule
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    EditGroup.cpp \
    SubjectListEdit.cpp \
    EditSubject.cpp \
    SubjectSchedule.cpp \
    Group.cpp \
    Subject.cpp \
    SubjectDateModel.cpp

HEADERS  += MainWindow.hpp \
    EditGroup.hpp \
    SubjectListEdit.hpp \
    EditSubject.hpp \
    SubjectSchedule.hpp \
    Group.hpp \
    Subject.hpp \
    SubjectDateModel.hpp

FORMS    += MainWindow.ui \
    EditGroup.ui \
    SubjectListEdit.ui \
    EditSubject.ui \
    SubjectSchedule.ui

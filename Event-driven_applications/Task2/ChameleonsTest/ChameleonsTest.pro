QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test.cpp \
    chamealeondata.cpp \
    chameleonmodel.cpp

HEADERS += \
    chamealeondata.h \
    chameleonmodel.h

QT += core
QT -= gui

CONFIG += c++11

TARGET = Pong
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    game.cpp \
    mainmenu.cpp \
    visiblegameobject.cpp \
    playerpaddle.cpp \
    gameobjectmanager.cpp \
    gameball.cpp \
    aipaddle.cpp \
    brick.cpp \
    brickarray.cpp

HEADERS += \
    game.h \
    mainmenu.h \
    visiblegameobject.h \
    playerpaddle.h \
    gameobjectmanager.h \
    gameball.h \
    aipaddle.h \
    brick.h \
    brickarray.h

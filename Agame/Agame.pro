CONFIG -= qt
CONFIG += c++11

LIBS += -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-main

DEFINES += SFML_STATIC

SOURCES += main.cpp \
    tiles/tiledlevel.cpp \
    aabb.cpp \
    player.cpp \
    object/entitymanager.cpp

HEADERS += \
    tiles/tiledlevel.h \
    aabb.h \
    player.h \
    object/entitymanager.h

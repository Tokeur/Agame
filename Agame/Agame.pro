CONFIG -= qt
CONFIG += c++11

LIBS += -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-main

DEFINES += SFML_STATIC

SOURCES += main.cpp \
    tiles/tiledlevel.cpp \
    aabb.cpp \
    object/entitymanager.cpp \
    object/entity.cpp \
    object/playerentity.cpp \
    utility/logger.cpp

HEADERS += \
    tiles/tiledlevel.h \
    aabb.h \
    object/entitymanager.h \
    object/entity.h \
    object/playerentity.h \
    utility/logger.h

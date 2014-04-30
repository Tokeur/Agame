CONFIG -= qt
CONFIG += c++11

LIBS += -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-main

DEFINES += SFML_STATIC

SOURCES += main.cpp \
    tiles/tiledlevel.cpp \
    object/entitymanager.cpp \
    object/entity.cpp \
    object/playerentity.cpp \
    utility/logger.cpp \
    utility/aabb.cpp \
    scene/scenebase.cpp \
    common/gameoptions.cpp

HEADERS += \
    tiles/tiledlevel.h \
    object/entitymanager.h \
    object/entity.h \
    object/playerentity.h \
    utility/logger.h \
    utility/aabb.h \
    scene/scenebase.h \
    common/gameoptions.h

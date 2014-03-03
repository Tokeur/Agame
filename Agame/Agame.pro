CONFIG-=Qt
CONFIG+=C++11
LIBS+= -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-system-s-d -lsfml-main-d

DEFINES+= SFML_STATIC

SOURCES += \
    main.cpp \
    tiles/tiledlevel.cpp

HEADERS += \
    tiles/tiledlevel.h

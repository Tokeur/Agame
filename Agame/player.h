#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "aabb.h"

class Player
{
public:
    Player();

    void update();
    void draw();
protected:
    AABB _box;
    sf::Sprite _sprtPlayer;

};

#endif // PLAYER_H

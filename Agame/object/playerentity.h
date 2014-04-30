#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include <SFML/Graphics.hpp>

#include "entity.h"
#include "aabb.h"

class PlayerEntity : public Entity {
public:
	PlayerEntity();

//	void update();
//	void draw(sf::RenderWindow& window);
protected:
	AABB _box;
	sf::Sprite _sprPlayer;
};

#endif // PLAYERENTITY_H

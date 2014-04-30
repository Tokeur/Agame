#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
	enum ENTITY_TYPE {
		TYPE_ABSTRACT, // Entity
		TYPE_PLAYER // PlayerEntity
	};
public:
	Entity();
	virtual ~Entity();

	virtual void update();
	virtual void draw(sf::RenderWindow&);
private:
};

#endif // ENTITY_H

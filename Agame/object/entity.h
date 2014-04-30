#ifndef ENTITY_H
#define ENTITY_H

#include "entitymanager.h"

class Entity {
public:
	enum EntityType {
		TYPE_ABSTRACT, // Entity
		TYPE_PLAYER // PlayerEntity
	};
public:
	Entity(EntityType type);
	virtual ~Entity();

	virtual void update();
	virtual void draw(sf::RenderWindow&);

	EntityManager* manager();

	void destroy();
	EntityType entityType() const;
private:
	EntityManager* _manager;
	EntityType _type;

	friend void EntityManager::append(Entity* o);
};

#endif // ENTITY_H

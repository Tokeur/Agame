#include "entity.h"

Entity::Entity(EntityType type) { _type=type; _manager=0; }
Entity::~Entity() {}

void Entity::update() {}
void Entity::draw(sf::RenderWindow&) {}

EntityManager* Entity::manager() {
	return _manager;
}

void Entity::destroy() {
	_manager->destroy(this);
}

Entity::EntityType Entity::entityType() {
	return _type;
}

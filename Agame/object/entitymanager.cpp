#include "entitymanager.h"
#include "entity.h"

EntityManager::EntityManager() {
}

void EntityManager::append(Entity *o) {
	_obj.push_front(o);
}

void EntityManager::updateAll() {
	for (std::forward_list<Entity*>::iterator i=_obj.begin();i!=_obj.end();i++)
		(*i)->update();
}

void EntityManager::drawAll(sf::RenderWindow& window) {
	for (std::forward_list<Entity*>::iterator i=_obj.begin();i!=_obj.end();i++)
		(*i)->draw(window);
}

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <forward_list>
#include <SFML/Graphics.hpp>

class Entity;

class EntityManager {
public:
	EntityManager();

	void append(Entity* o);

	void updateAll();
	void drawAll(sf::RenderWindow& window);
private:
	std::forward_list<Entity*> _obj;
};

#endif // ENTITYMANAGER_H

#ifndef OBJMANAGER_H
#define OBJMANAGER_H

#include <forward_list>
#include <SFML/Graphics.hpp>

class Entity;

class EntityManager {
public:
	EntityManager();
	void updateAll();
	void drawAll(sf::RenderWindow& window);
private:
	std::forward_list<Entity*> _obj;
};

#endif // OBJMANAGER_H

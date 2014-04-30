#ifndef AABB_H
#define AABB_H

#include <SFML/System.hpp>

class AABB {
public:
    AABB();
	sf::Vector2f sfPos() const;
	sf::Vector2f sfSize() const;
    bool collision(AABB other) const;
public:
    int x, y, w, h;
};

#endif // AABB_H

#include "aabb.h"

AABB::AABB() {
    x=y=w=h=0;
}

sf::Vector2f AABB::sfPos() const {
	return sf::Vector2f((float)x, (float)y);
}

sf::Vector2f AABB::sfSize() const {
	return sf::Vector2f((float)w, (float)h);
}

bool AABB::collision(AABB other) const {
	return !((other.x>=x+w) ||
			(other.x+other.w<=x) ||
			(other.y>=y+h) ||
			(other.y+other.h<=y));
}

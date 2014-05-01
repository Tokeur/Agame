#include "scenegame.h"

SceneGame::SceneGame() {
	_level.reset(10, 10);
	_level.at(2, 4) = 1;
}

void SceneGame::draw(sf::RenderWindow& window) {
	window.draw(_level);
}

#ifndef SCENEGAME_H
#define SCENEGAME_H

#include "scenebase.h"
#include "tiles/tiledlevel.h"

class SceneGame : public SceneBase {
public:
	SceneGame();
	void draw(sf::RenderWindow& window);
private:
	TiledLevel _level;
};

#endif // SCENEGAME_H

#ifndef SCENEBASE_H
#define SCENEBASE_H

#include <SFML/Graphics.hpp>

class SceneBase {
public:
	SceneBase();
	virtual ~SceneBase();

	virtual void onEvent(sf::Event&);
	virtual void update(sf::Time);
	virtual void draw(sf::RenderWindow&);
	virtual SceneBase* getNextScene();
};

#endif // SCENEBASE_H

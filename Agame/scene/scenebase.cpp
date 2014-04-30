#include "scenebase.h"

SceneBase::SceneBase() {}
SceneBase::~SceneBase() {}

void SceneBase::onEvent(sf::Event&) {}

void SceneBase::update(sf::Time) {}
void SceneBase::draw(sf::RenderWindow&) {}

SceneBase* SceneBase::getNextScene() { return this; }

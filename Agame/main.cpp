#include <SFML/Graphics.hpp>
#include "common/gameoptions.h"
#include "scene/scenegame.h"

int main(int, char**) {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Game v(@Version)");

	sf::Clock tickingclock;
	bool winFocused=true;

	SceneBase* scene = new SceneGame;

	window.clear();

	while(window.isOpen()) {
		sf::Event ev;

		while(window.pollEvent(ev)) {
			if (ev.type==sf::Event::Closed)
				window.close();
			else if (ev.type==sf::Event::KeyReleased && ev.key.code==sf::Keyboard::Escape)
				window.close();
			else if (ev.type==sf::Event::LostFocus)
				winFocused=false;
			else if (ev.type==sf::Event::GainedFocus)
				winFocused=true;
			else
				scene->onEvent(ev);
		}

		if (winFocused || GameOptions::ignoreFocus) {
			window.clear();

			sf::Time time = tickingclock.getElapsedTime();
			tickingclock.restart();

			scene->update(time);
			scene->draw(window);

			SceneBase* nscene = scene->getNextScene();

			if (nscene!=scene) {
				delete scene;
				if (nscene==0)
					window.close();
				else
					scene = nscene;
			} //*/
		}

		window.display();
	}

	return EXIT_SUCCESS;
}

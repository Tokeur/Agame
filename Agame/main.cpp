#include <SFML/Graphics.hpp>

int main(int, char**) {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Game v(@Version)");
	bool winFocused=true;

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
//			else
//				scene.onEvent(ev);
		}

		window.clear();
		window.display();
	}

	return EXIT_SUCCESS;
}

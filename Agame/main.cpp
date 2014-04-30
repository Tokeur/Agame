#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int, char**)
{
    sf::RenderWindow window(sf::VideoMode(640,480), "AGame");

    while(window.isOpen())
    {
        sf::Event ev;
        while(window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::KeyPressed:
                switch (ev.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                }
                break;
             case sf::Event::Closed:
                window.close();
                break;
            }
        }

        window.clear();
        window.display();
    }

    return EXIT_SUCCESS;
}

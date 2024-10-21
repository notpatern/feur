#include "Game.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/Window.hpp"

void Game::init() {
    stateStack.push(new MenuState());
}

void Game::run() {
    sf::RenderWindow window{sf::VideoMode(1640, 900), "feur"};
    init();

    while (window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            stateStack.top()->Update(window);
        }
    }
}

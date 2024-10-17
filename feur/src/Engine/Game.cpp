#include "Game.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/Window.hpp"

void Game::init() {
    stateStack.push();
}

void Game::run() {
    sf::Window window{sf::VideoMode(1640, 900), "feur"};

    while (window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        stateStack.top().Update();
    }
}

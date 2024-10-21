#include "Game.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/Window.hpp"
#include <iostream>

Game::~Game() {
    delete window;
}

void Game::init() {
    window = new sf::RenderWindow(sf::VideoMode(1200, 720), "feur", sf::Style::Default);
    std::cout << "window created\n";
    stateStack.push(new MenuState());
    std::cout << "menustate created\n";
}

void Game::run() {
    init();

    while (window->isOpen()) {
        update();
        render();
    }
}

void Game::updateSfmlEvents() {
    if (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
}

void Game::update() {
    stateStack.top()->update();
}

void Game::render() {
    window->clear();

    stateStack.top()->render(*window);

    window->display();
}

#include "Game.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/Window.hpp"

Game::~Game() {
    delete window;
}

void Game::init() {
    window = new sf::RenderWindow(sf::VideoMode(1200, 720), "feur", sf::Style::Default);
    m_mousePosition = sf::Mouse::getPosition(*window);
    stateStack.push(new MenuState(m_mousePosition, stateStack));
}

void Game::run() {
    init();

    while (window->isOpen()) {
        update();
        updateSfmlEvents();
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
    m_mousePosition = sf::Mouse::getPosition(*window);
    stateStack.top()->update();
}

void Game::render() {
    window->clear();

    stateStack.top()->render(*window);

    window->display();
}

#include "MenuState.hpp"
#include "GameState.hpp"
#include "SFML/System/Vector2.hpp"

MenuState::MenuState(sf::Vector2i& mousePosition, std::stack<State*>& stateStack) : State(mousePosition, stateStack) {
    start();
}

void MenuState::start() {
    m_startImage->loadFromFile(".\\feur\\src\\Resources\\startButton.png");
    m_startHovered->loadFromFile(".\\feur\\src\\Resources\\startButtonHovered.png");
    m_startClicked->loadFromFile(".\\feur\\src\\Resources\\startButtonClicked.png");

    m_quitImage->loadFromFile(".\\feur\\src\\Resources\\quitButton.png");
    m_quitHovered->loadFromFile(".\\feur\\src\\Resources\\quitButtonHovered.png");
    m_quitClicked->loadFromFile(".\\feur\\src\\Resources\\quitButtonClicked.png");

    m_startButton = new Button(m_mousePosition, *(new sf::Vector2i{0, 0}), m_startImage, m_startHovered, m_startClicked, 4);
    m_quitButton = new Button(m_mousePosition, *(new sf::Vector2i{128, 0}), m_quitImage, m_quitHovered, m_quitClicked, 4);

    m_startButton->bindOnClick([this](){ m_stateStack.push(new GameState(m_mousePosition, m_stateStack)); });
    m_quitButton->bindOnClick([this](){ exit(); });
}

void MenuState::update() {
    m_startButton->update();
    m_quitButton->update();
}

void MenuState::render(sf::RenderTarget& target) {
    m_startButton->render(target);
    m_quitButton->render(target);
}

void MenuState::exit() {
    std::exit(0);
}

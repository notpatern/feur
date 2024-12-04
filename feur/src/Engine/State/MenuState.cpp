#include "MenuState.hpp"
#include "GameState.hpp"
#include "SFML/System/Vector2.hpp"

MenuState::MenuState(double& deltaTime, sf::Vector2i& mousePosition, std::stack<State*>& stateStack) : State(deltaTime, mousePosition, stateStack) {
    start();
}

void MenuState::start() {
    m_title->loadFromFile(".\\feur\\src\\Resources\\feur.png");
    m_titleTexture->loadFromImage(*m_title);
    m_titleSprite->setTexture(*m_titleTexture);
    m_titleSprite->setScale(4, 4);
    m_titleSprite->setPosition(344, 190);

    m_backGround->loadFromFile(".\\feur\\src\\Resources\\feurBg.png");
    m_backGroundTexture->loadFromImage(*m_backGround);
    m_backGroundSprite->setTexture(*m_backGroundTexture);
    m_backGroundSprite->setScale(10, 10);
    m_backGroundSprite->setPosition(0, 0);

    m_startImage->loadFromFile(".\\feur\\src\\Resources\\startButton.png");
    m_startHovered->loadFromFile(".\\feur\\src\\Resources\\startButtonHovered.png");
    m_startClicked->loadFromFile(".\\feur\\src\\Resources\\startButtonClicked.png");

    m_quitImage->loadFromFile(".\\feur\\src\\Resources\\quitButton.png");
    m_quitHovered->loadFromFile(".\\feur\\src\\Resources\\quitButtonHovered.png");
    m_quitClicked->loadFromFile(".\\feur\\src\\Resources\\quitButtonClicked.png");

    m_startButton = new Button(m_mousePosition, *(new sf::Vector2i{462, 350}), m_startImage, m_startHovered, m_startClicked, 4);
    m_quitButton = new Button(m_mousePosition, *(new sf::Vector2i{610, 350}), m_quitImage, m_quitHovered, m_quitClicked, 4);

    m_startButton->bindOnClick([this](){ m_stateStack.push(new GameState(m_dt, m_mousePosition, m_stateStack)); });
    m_quitButton->bindOnClick([this](){ exit(); });
}

void MenuState::update() {
    m_startButton->update();
    m_quitButton->update();
}

void MenuState::render(sf::RenderTarget& target) {
    target.draw(*m_backGroundSprite);
    m_startButton->render(target);
    m_quitButton->render(target);
    target.draw(*m_titleSprite);
}

void MenuState::exit() {
    std::exit(0);
}

#include "MenuState.hpp"
#include "GameState.hpp"
#include "SFML/System/Vector2.hpp"

MenuState::MenuState(sf::Vector2i& mousePosition, std::stack<State*>* stateStack) : State(mousePosition, stateStack) {
    start();
}

void MenuState::start() {
    testImage->loadFromFile(".\\feur\\src\\Resources\\0b501962f355f06eb7bb8b03976fc07b.jpg");
    test = new Button(m_mousePosition, position, testImage, testImage, testImage, true);
    test->bindOnClick([this](){ m_stateStack->push(new GameState(m_mousePosition, m_stateStack)); });
}

void MenuState::update() {
    test->update();
}

void MenuState::render(sf::RenderTarget& target) {
    test->render(target);
}

void MenuState::exit() {
    m_stateStack->pop();
}

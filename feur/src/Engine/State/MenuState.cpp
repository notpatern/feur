#include "MenuState.hpp"
#include "SFML/System/Vector2.hpp"
#include <iostream>

MenuState::MenuState(sf::Vector2i& mousePosition) : State(mousePosition) {
    start();
}

void MenuState::start() {
    testImage->loadFromFile("E:\\Github\\feur\\feur\\src\\Resources\\0b501962f355f06eb7bb8b03976fc07b.jpg");
    testImageHovered->loadFromFile("E:\\Github\\feur\\feur\\src\\Resources\\qr-code.png");
    test = new Button(m_mousePosition, position, testImage, testImageHovered, testImage, true);
    test->bindOnClick([](){ std::cout << "caca2\n"; });
}

void MenuState::update() {
    test->update();
}

void MenuState::render(sf::RenderTarget& target) {
    test->render(target);
}

void MenuState::exit() {

}

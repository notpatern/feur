#include "MenuState.hpp"
#include <iostream>

MenuState::MenuState() : State() {
    std::cout << "constructor menu state\n";
    start();
}

void MenuState::start() {
    testImage->loadFromFile("E:\\Github\\feur\\feur\\src\\Resources\\0b501962f355f06eb7bb8b03976fc07b.jpg");
    testImageHovered->loadFromFile("E:\\Github\\feur\\feur\\src\\Resources\\qr-code.png");
    std::cout << "image loaded\n";
    test = new Button({0, 0}, testImage, testImageHovered);
    std::cout << "button created\n";
    test->bindOnClick([](){ std::cout << "caca2\n";});
}

void MenuState::update() {
    test->update();
}

void MenuState::render(sf::RenderTarget& target) {
    test->render(target);
}

void MenuState::exit() {

}

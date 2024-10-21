#pragma once
#include "MenuState.hpp"

MenuState::MenuState() : State() {
    Start();
}

void MenuState::Start() {

}

void MenuState::Update(sf::RenderTarget& target) {
    test.update(target);
}

void MenuState::FixedUpdate() {

}

void MenuState::Exit() {

}

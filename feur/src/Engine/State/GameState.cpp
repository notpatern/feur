#include "GameState.hpp"
#include "SFML/System/Vector2.hpp"

GameState::GameState(double& deltaTime, sf::Vector2i& mousePosition, std::stack<State*>& stateStack) : State(deltaTime, mousePosition, stateStack) {
}

void GameState::start() {
}

void GameState::update() {
    m_anchorGen.update();
}

void GameState::render(sf::RenderTarget& target) {
    m_anchorGen.render(target);
}

void GameState::exit() {
    m_stateStack.pop();
}

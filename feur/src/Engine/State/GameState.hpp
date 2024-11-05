#pragma once

#include "State.hpp"

class GameState : public State {
private:

public:
    GameState(sf::Vector2i& mousePosition, std::stack<State*>& stateStack);
    ~GameState() = default;

    void start() override;
    void update() override;
    void render(sf::RenderTarget& target) override;
    void exit() override;

    void generateAnchor();
    void deleteAnchor();
};

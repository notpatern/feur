#pragma once

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include <stack>

class State {
protected:
    double m_dt;
    sf::Vector2i& m_mousePosition;
    std::stack<State*>& m_stateStack;

public:
    State(double& deltaTime, sf::Vector2i& mousePosition, std::stack<State*>& stateStack);
    ~State();

    virtual void start() = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderTarget& target) = 0;
    virtual void exit() =  0;
};

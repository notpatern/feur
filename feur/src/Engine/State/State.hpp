#pragma once

#include "SFML/Graphics/RenderTarget.hpp"
class State {
private:

public:
    State();
    ~State();

    virtual void start() = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderTarget& target) = 0;
    virtual void exit() =  0;
};

#pragma once

#include "SFML/Graphics/RenderTarget.hpp"
class State {
private:

public:
    State();
    ~State();

    virtual void Start() = 0;
    virtual void Update(sf::RenderTarget& target) = 0;
    virtual void FixedUpdate() = 0;
    virtual void Exit() =  0;
};

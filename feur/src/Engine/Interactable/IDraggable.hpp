#pragma once

#include "SFML/System/Vector2.hpp"
class IDraggable {
private:
    virtual void onDrag() = 0;

protected:
    sf::Vector2i m_dragMovementModifier;

public:
    IDraggable() = default;
    ~IDraggable() = default;
};

#pragma once

#include "SFML/System/Vector2.hpp"

class IClickable {
private:
    sf::Vector2i m_bounds;
    bool m_dirtyHoverState{false};
    bool m_dirtyMouseLeftState{false};

    void click();
    bool isHovered();
    void hover();

protected:
    sf::Vector2i& m_position;
    sf::Vector2i& m_mousePosition;
    sf::Vector2i m_dirtyMousePosition;
    bool m_mouseLeftState{false};
    bool m_isHovered{false};
    virtual void onHover() = 0;
    virtual void onLeave() = 0;
    virtual void onClick() = 0;
    void updateClickable();

public:
    IClickable(sf::Vector2i& position, sf::Vector2i bounds, sf::Vector2i& mousePosition);
    ~IClickable() = default;
};

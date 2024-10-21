#pragma once

#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"

class IClickable {
private:
    sf::Vector2i m_mousePosition;
    sf::Vector2i m_position;
    sf::Vector2i m_bounds;
    sf::Event m_event;
    bool m_isHovered{false};
    bool m_dirtyHoverState{false};
    bool m_mouseLeftState{false};
    bool m_dirtyMouseLeftState{false};

    void click();
    bool isHovered();
    void hover();

protected:
    virtual void onHover() = 0;
    virtual void onLeave() = 0;
    virtual void onClick() = 0;
    void updateClickable();

public:
    IClickable(sf::Vector2i position, sf::Vector2i bounds);
    ~IClickable() = default;
};

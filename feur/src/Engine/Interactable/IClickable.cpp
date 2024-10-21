#include "IClickable.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"

IClickable::IClickable(sf::Vector2i position, sf::Vector2i bounds) : m_position{std::move(position)}, m_bounds{std::move(bounds)} {}

void IClickable::updateClickable() {
    m_mousePosition = sf::Mouse::getPosition();
    hover();
    click();
}

void IClickable::click() {
    if (isHovered() && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        onClick();
    }
}

bool IClickable::isHovered() {
    return ((m_mousePosition.x >= m_position.x && m_mousePosition.x <= m_position.x + m_bounds.x)
        && (m_mousePosition.y >= m_position.y && m_mousePosition.y <= m_position.y + m_bounds.y));
}

void IClickable::hover() {
    m_dirtyHoverState = m_isHovered;
    m_isHovered = isHovered();

    if (m_dirtyHoverState && !m_isHovered) {
        onLeave();
        return;
    } else if (!m_dirtyHoverState && m_isHovered) {
        onHover();
        return;
    }
}

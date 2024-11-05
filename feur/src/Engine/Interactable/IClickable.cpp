#include "IClickable.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include <utility>

IClickable::IClickable(sf::Vector2i& position, sf::Vector2i bounds, sf::Vector2i& mousePosition, float scale)
: m_position{position}, m_bounds{std::move(bounds)}, m_mousePosition{mousePosition}, m_scale{scale} {}

void IClickable::updateClickable() {
    hover();
    click();
}

void IClickable::click() {
    m_mouseLeftState = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    if (isHovered() && (m_mouseLeftState && !m_dirtyMouseLeftState)) {
        onClick();
    }
    m_dirtyMouseLeftState = m_mouseLeftState;
}

bool IClickable::isHovered() {
    return ((m_mousePosition.x >= m_position.x && m_mousePosition.x <= m_position.x + m_bounds.x * m_scale)
        && (m_mousePosition.y >= m_position.y && m_mousePosition.y <= m_position.y + m_bounds.y * m_scale));
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

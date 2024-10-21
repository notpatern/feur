#include "Button.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include <iostream>

void Button::update(sf::RenderTarget& target) {
    updateClickable();
    render(target);
}

void Button::render(sf::RenderTarget& target) {
    target.draw(*m_currentSprite);
}

void Button::onClick() {
    std::cout << "caca\n";
    m_currentSprite = m_clickedSprite;
    m_clickDelegate();
}

void Button::onHover() {
    m_currentSprite = m_hoveredSprite;
}

void Button::onLeave() {
    m_currentSprite = m_idleSprite;
}

void Button::bindOnClick(std::function<void()> function) {
    m_clickDelegate = std::bind(function);
}

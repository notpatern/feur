#include "Button.hpp"
#include "IDraggable.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"

Button::Button(sf::Vector2i& mousePosition, sf::Vector2i& position, std::shared_ptr<sf::Image> idleImage,
               std::shared_ptr<sf::Image> hoveredImage,
               std::shared_ptr<sf::Image> clickedImage,
               bool isDraggable)
            : IClickable(position, static_cast<sf::Vector2i>(idleImage->getSize()), mousePosition), IDraggable(), m_isDraggable{isDraggable} {
    m_idleTexture->loadFromImage(*idleImage);
    if (hoveredImage == nullptr) {
        m_hoveredTexture->loadFromImage(*idleImage);
    } else {
        m_hoveredTexture->loadFromImage(*hoveredImage);
    }
    if (clickedImage == nullptr) {
        m_clickedTexture->loadFromImage(*idleImage);
    } else {
        m_clickedTexture->loadFromImage(*clickedImage);
    }
    m_idleSprite->setTexture(*m_idleTexture);
    m_hoveredSprite->setTexture(*m_hoveredTexture);
    m_clickedSprite->setTexture(*m_clickedTexture);
    m_currentSprite = m_idleSprite;
    m_dragMovementModifier = {0, 0};
}

Button::~Button() {}

void Button::update() {
    updateClickable();
    onDrag();
}

void Button::render(sf::RenderTarget &target) {
    m_currentSprite->setPosition(m_position.x, m_position.y);
    target.draw(*m_currentSprite);
}

void Button::onClick() {
    if (m_currentSprite != m_clickedSprite) {
        m_currentSprite = m_clickedSprite;
    }
    m_dirtyMousePosition = m_mousePosition;
    m_clickDelegate();
}

void Button::onHover() {
    if (m_currentSprite != m_hoveredSprite) {
        m_currentSprite = m_hoveredSprite;
    }
}

void Button::onLeave() {
    if (m_currentSprite != m_idleSprite) {
        m_currentSprite = m_idleSprite;
    }
}

void Button::onDrag() {
    if (!m_isDraggable) {
        return;
    }
    m_dragMovementModifier = {0, 0};
    if (m_mouseLeftState && m_isHovered) {
        m_dragMovementModifier = m_mousePosition - m_dirtyMousePosition;
        m_dirtyMousePosition = m_mousePosition;
        m_position += m_dragMovementModifier;
    }
}

void Button::bindOnClick(std::function<void()> function) {
    m_clickDelegate = std::bind(function);
}

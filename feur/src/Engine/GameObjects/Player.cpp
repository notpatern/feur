#include "Player.hpp"
#include "SFML/System/Vector2.hpp"

Player::Player(sf::Texture texture, sf::Vector2i& position, sf::Vector2i bounds, sf::Vector2i mousePosition, float scale)
: IClickable(position, bounds, mousePosition, scale) {
    m_playerSprite->setTexture(texture);
    m_playerSprite->setScale({scale, scale});
    m_playerSprite->setPosition(static_cast<sf::Vector2f>(position));
}

Player::~Player() {
    delete m_currentAnchor;
}

void Player::update(double deltaTime) {
    updatePhysics(deltaTime);
}

void Player::updatePhysics(double deltaTime) {
    applyFriction(deltaTime);
    applyGravity(deltaTime);
}

void Player::render(sf::RenderTarget& target) {
    target.draw(*m_playerSprite);
}

void Player::onDrag() {
    if (m_currentAnchor != nullptr) {
        return;
    }

    m_dragMovementModifier = {0, 0};
    if (m_mouseLeftState && m_isHovered) {
        m_dragMovementModifier = m_mousePosition - m_dirtyMousePosition;
        m_dirtyMousePosition = m_mousePosition;
        m_position += m_dragMovementModifier;
    }
}

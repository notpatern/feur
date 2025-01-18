#include "Anchor.hpp"

Anchor::Anchor(float rubberLength, sf::Vector2i position, std::shared_ptr<sf::Texture> texture, float scale)
: m_rubberLength{std::move(rubberLength)}, m_position{std::move(position)}, m_scale{std::move(scale)}, m_texture{texture}, m_bounds{static_cast<int>(texture->getSize().x * scale), static_cast<int>(texture->getSize().y * scale)}
{
    m_sprite->setTexture(*m_texture);
    m_sprite->setScale(m_scale, m_scale);
}

void Anchor::update() {
    m_sprite->setPosition(m_position.x, m_position.y);
}

void Anchor::render(sf::RenderTarget& target) {
    target.draw(*m_sprite);
}

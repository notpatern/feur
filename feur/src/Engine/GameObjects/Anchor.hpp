#pragma once

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"
#include <memory>

class Anchor {
private:
    const std::shared_ptr<sf::Texture> m_texture = std::make_shared<sf::Texture>();
    std::unique_ptr<sf::Sprite> m_sprite = std::make_unique<sf::Sprite>();

    sf::Vector2i m_position;
    const sf::Vector2i m_bounds;
    const float m_scale;
    const float m_rubberLength;

    bool m_isActive{false};

public:
    Anchor(float rubberLength, sf::Vector2i position, std::shared_ptr<sf::Texture> texture, float scale = 1);
    ~Anchor() = default;

    [[nodiscard]] inline bool getState() const { return m_isActive; }
    [[nodiscard]] inline bool getRubberLength() const { return m_rubberLength; }
    [[nodiscard]] inline sf::Vector2i getPosition() const { return m_position; }
    [[nodiscard]] inline sf::Vector2i getBounds() const { return m_bounds; }

    inline void switchState() { m_isActive = !m_isActive; }
    inline void setPosition(sf::Vector2i&& position) { m_position = position; }

    void update();
    void render(sf::RenderTarget& target);
};

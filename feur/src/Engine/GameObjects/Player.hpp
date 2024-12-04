#pragma once

#include "SFML/System/Vector2.hpp"
#include <SFML/Window.hpp>
#include <memory>

class Player {
private:
    sf::Vector2i m_position;
    sf::Vector2i m_bounds;
    sf::Vector2i m_velocity;

    bool m_onAnchor{false};

    std::shared_ptr<sf::Vector2i> playerSprite = std::make_shared<sf::Vector2i>();

public:
    Player();
    ~Player();

    [[nodiscard]] inline sf::Vector2i position() { return m_position; }
    [[nodiscard]] inline sf::Vector2i bounds() { return m_bounds; }
    void swapState();
};

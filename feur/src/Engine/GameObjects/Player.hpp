#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Window.hpp>
#include "../Physics/ForceBehavior.h"
#include "../Interactable/IClickable.hpp"
#include "../Interactable/IDraggable.hpp"
#include "Anchor.hpp"
#include <functional>
#include <memory>

class Player : public IClickable, public IDraggable {
private:
    sf::Vector2i m_velocity{0, 0};
    sf::Vector2i m_gravity{0, 1000};
    float m_friction{300};

    Anchor* m_currentAnchor{nullptr};

    bool m_useGravity{true};
    bool m_onAnchor{false};

    std::unique_ptr<sf::Sprite> m_playerSprite = std::make_unique<sf::Sprite>();

    inline void applyGravity(double deltaTime) {
        applyForce(m_gravity, Physics::Force::Behavior::None);
    }

    inline void applyFriction(double deltaTime) {
        if (m_velocity.x < 0) {
            m_velocity.x += m_friction * deltaTime;
            return;
        }

        m_velocity.x -= m_friction * deltaTime;
    }

    std::function<void()> m_clickDelegate;
    void onClick() override {}
    void onHover() override {}
    void onLeave() override {}
    void onDrag() override;

public:
    Player(sf::Texture texture, sf::Vector2i& position, sf::Vector2i bounds, sf::Vector2i mousePosition, float scale);
    ~Player();

    [[nodiscard]] inline sf::Vector2i position() { return m_position; }
    [[nodiscard]] inline sf::Vector2i bounds() { return m_bounds; }

    inline void swapState() {
        m_useGravity = !m_useGravity;
        m_onAnchor = !m_onAnchor;
    };

    inline void applyForce(sf::Vector2i force, Physics::Force::Behavior behavior) {
        switch(behavior) {
            case Physics::Force::Behavior::Reset:
            m_velocity = {0, 0};
            break;

            case Physics::Force::Behavior::None:
            break;

            default:
            break;
        }

        m_velocity += force;
    }

    void updatePhysics(double deltaTime);
    void update(double deltaTime);
    void render(sf::RenderTarget& target);
};

#pragma once

#include "IClickable.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"
#include <functional>

#include <memory>

class Button : public IClickable {
private:
    std::shared_ptr<sf::Sprite> m_currentSprite{};
    std::shared_ptr<sf::Sprite> m_idleSprite;
    std::shared_ptr<sf::Sprite> m_hoveredSprite;
    std::shared_ptr<sf::Sprite> m_clickedSprite;

    sf::Vector2i m_spritePosition;

    std::function<void()> m_clickDelegate;
    void render(sf::RenderTarget& target);

public:
    Button(sf::Vector2i position, std::shared_ptr<sf::Sprite> idleSprite, std::shared_ptr<sf::Sprite> hoveredSprite = nullptr, std::shared_ptr<sf::Sprite> clickedSprite = nullptr)
    : IClickable(position, static_cast<sf::Vector2i>(idleSprite->getLocalBounds().getSize())),
    m_spritePosition{position}, m_currentSprite{idleSprite}, m_idleSprite{idleSprite}, m_hoveredSprite{hoveredSprite}, m_clickedSprite{clickedSprite}
    {}
    ~Button() = default;

    void update(sf::RenderTarget& target);
    void onClick() override;
    void onHover() override;
    void onLeave() override;

    void bindOnClick(std::function<void()> function);
};

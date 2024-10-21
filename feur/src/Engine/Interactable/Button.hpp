#pragma once

#include "IClickable.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include <functional>

#include <memory>

class Button : public IClickable {
private:
    sf::Texture* m_idleTexture = new sf::Texture();
    sf::Texture* m_hoveredTexture = new sf::Texture();
    sf::Texture* m_clickedTexture = new sf::Texture();

    sf::Sprite* m_currentSprite = new sf::Sprite();
    sf::Sprite* m_idleSprite = new sf::Sprite();
    sf::Sprite* m_hoveredSprite = new sf::Sprite();
    sf::Sprite* m_clickedSprite = new sf::Sprite();

    sf::Vector2i m_spritePosition;

    std::function<void()> m_clickDelegate;

public:
    Button(sf::Vector2i position, std::shared_ptr<sf::Image> idleImage, std::shared_ptr<sf::Image> hoveredImage = nullptr, std::shared_ptr<sf::Image> clickedImage = nullptr);
    ~Button();

    void update();
    void render(sf::RenderTarget& target);
    void onClick() override;
    void onHover() override;
    void onLeave() override;

    void bindOnClick(std::function<void()> function);
};

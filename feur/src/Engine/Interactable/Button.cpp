#include "Button.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include <iostream>

Button::Button(sf::Vector2i position, std::shared_ptr<sf::Image> idleImage, std::shared_ptr<sf::Image> hoveredImage, std::shared_ptr<sf::Image> clickedImage)
    : IClickable(position, static_cast<sf::Vector2i>(idleImage->getSize()))
{
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
    std::cout << "textures and sprites loaded\n";
}

Button::~Button() {
    delete m_clickedTexture;
    delete m_hoveredTexture;
    delete m_idleTexture;
}

void Button::update() {
    updateClickable();
}

void Button::render(sf::RenderTarget& target) {
    target.draw(*m_currentSprite);
}

void Button::onClick() {
    if (m_currentSprite != m_clickedSprite) {
        std::cout << "ouais c'est bien different la team\n";
        m_currentSprite = m_clickedSprite;
    }
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

void Button::bindOnClick(std::function<void()> function) {
    m_clickDelegate = std::bind(function);
}

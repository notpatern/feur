#pragma once
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include "State.hpp"
#include "../Interactable/Button.hpp"
#include <memory>

class MenuState : public State {
private:
    std::shared_ptr<sf::Image> testImage = std::make_shared<sf::Image>();
    std::shared_ptr<sf::Image> testImageHovered = std::make_shared<sf::Image>();
    Button* test;

public:
    MenuState(sf::Vector2i& mousePosition);
    ~MenuState() = default;

    void start() override;
    void update() override;
    void render(sf::RenderTarget& target) override;
    void exit() override;
};

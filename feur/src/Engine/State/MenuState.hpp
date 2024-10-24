#pragma once
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include "State.hpp"
#include "../Interactable/Button.hpp"
#include <memory>
#include <stack>

class MenuState : public State {
private:
    std::shared_ptr<sf::Image> testImage = std::make_shared<sf::Image>();
    std::shared_ptr<sf::Image> testImageHovered = std::make_shared<sf::Image>();
    Button* test;
    sf::Vector2i position{0, 0};

public:
    MenuState(sf::Vector2i& mousePosition, std::stack<State*>* stateStack);
    ~MenuState() = default;

    void start() override;
    void update() override;
    void render(sf::RenderTarget& target) override;
    void exit() override;
};

#pragma once
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include "State.hpp"
#include "../Interactable/Button.hpp"
#include <memory>
#include <stack>

class MenuState : public State {
private:
    std::shared_ptr<sf::Image> m_startImage = std::make_shared<sf::Image>();
    std::shared_ptr<sf::Image> m_startHovered = std::make_shared<sf::Image>();
    std::shared_ptr<sf::Image> m_startClicked = std::make_shared<sf::Image>();

    std::shared_ptr<sf::Image> m_quitImage = std::make_shared<sf::Image>();
    std::shared_ptr<sf::Image> m_quitHovered = std::make_shared<sf::Image>();
    std::shared_ptr<sf::Image> m_quitClicked = std::make_shared<sf::Image>();

    Button* m_startButton;
    Button* m_quitButton;

public:
    MenuState(sf::Vector2i& mousePosition, std::stack<State*>& stateStack);
    ~MenuState() = default;

    void start() override;
    void update() override;
    void render(sf::RenderTarget& target) override;
    void exit() override;
};

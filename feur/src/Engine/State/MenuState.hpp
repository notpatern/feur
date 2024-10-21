#pragma once
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include "State.hpp"
#include "../Interactable/Button.hpp"

class MenuState : public State {
private:
    sf::Sprite caca{new Texture()};
    Button test{sf::Vector2i{0,0}, std::make_shared<sf::Sprite>()};

public:
    MenuState();
    ~MenuState() = default;

    void Start() override;
    void Update(sf::RenderTarget& target) override;
    void FixedUpdate() override;
    void Exit() override;
};

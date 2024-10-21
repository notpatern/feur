#pragma once
#include <stack>
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "State/State.hpp"
#include "State/MenuState.hpp"

class Game {
private:
    sf::Vector2i m_mousePosition;
    std::stack<State*> stateStack{};
    sf::Event event{};
    sf::RenderWindow* window;

    void init();
    void updateSfmlEvents();
    void update();
    void render();

public:
    Game() = default;
     ~Game();

    void run();
};

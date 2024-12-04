#pragma once
#include <stack>
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "State/State.hpp"

class Game {
private:
    double m_dt{};
    sf::Clock m_dtClock{};
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

#pragma once
#include <stack>
#include "State/State.hpp"

class Game {
private:
    std::stack<State> stateStack{};

public:
    Game() = default;
     ~Game() = default;

    void init();
    void run();
};

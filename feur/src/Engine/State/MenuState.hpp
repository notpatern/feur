#pragma once
#include "State.hpp"

class MenuState : State {
private:

public:
    MenuState();
    ~MenuState();

    void Start() override;
    void Update() override;
    void Exit() override;

};

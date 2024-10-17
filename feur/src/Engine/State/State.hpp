#pragma once

class State {
private:

public:
    State();
    ~State();

    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Exit() =  0;
};

#include "State.hpp"
#include <stack>

State::State(double& deltaTime, sf::Vector2i& mousePosition, std::stack<State*>& stateStack) : m_dt{deltaTime}, m_mousePosition{mousePosition}, m_stateStack{stateStack} {

}

State::~State() {

}

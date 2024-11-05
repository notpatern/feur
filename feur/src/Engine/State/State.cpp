#include "State.hpp"
#include <stack>

State::State(sf::Vector2i& mousePosition, std::stack<State*>& stateStack) : m_mousePosition{mousePosition}, m_stateStack{stateStack} {

}

State::~State() {

}

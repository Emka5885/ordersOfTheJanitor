#include "StateMachine.h"

void StateMachine::AddState(StateRef newState)
{
	this->_newState = std::move(newState);
	this->_states.push(std::move(this->_newState));
}

void StateMachine::RemoveState()
{
	if (!this->_states.empty())
	{
		this->_states.pop();
	}
}
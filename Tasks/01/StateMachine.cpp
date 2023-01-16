#include "StateMachine.h"

void StateMachine::AddState(StateRef newState)
{
	this->_states.push(std::move(newState));
}

void StateMachine::RemoveState()
{
	if (!this->_states.empty())
	{
		this->_states.pop();
	}
}
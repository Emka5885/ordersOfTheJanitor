#include "StateMachine.h"

void StateMachine::AddState(StateRef newState)
{
	this->states.push(std::move(newState));
}

void StateMachine::RemoveState()
{
	if (!this->states.empty())
	{
		this->states.pop();
	}
}
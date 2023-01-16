#pragma once
#include <memory>
#include <stack>
#include "State.h"

typedef std::unique_ptr<State> StateRef;

class StateMachine
{
public:
	StateMachine() {}
	~StateMachine() {}

	void AddState(StateRef newState);
	void RemoveState();


private:
	std::stack<StateRef> states;
};
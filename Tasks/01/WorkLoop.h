#pragma once
#include "StateMachine.h"

class WorkLoop
{
public:
	WorkLoop();
	void Run(bool& quitt, std::vector<room>& building, std::array<std::string, NUMBER_OF_ROOMS>& rooms);

private:
	StateMachine _data;
};
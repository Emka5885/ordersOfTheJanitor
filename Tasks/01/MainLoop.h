#pragma once
#include "StateMachine.h"

class MainLoop
{
public:
	MainLoop();
	void Run(std::vector<room>& building, std::array<std::string, NUMBER_OF_ROOMS>& rooms);

private:
	StateMachine _data;
	bool quitt;
};
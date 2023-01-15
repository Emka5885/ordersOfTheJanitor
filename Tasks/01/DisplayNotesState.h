#pragma once
#include "State.h"
#include "DisplayNotes.h"
#include "HelperFunctions.h"

class DisplayNotesState :public State
{
public:
	DisplayNotesState(std::vector<room>& building, std::array<std::string, NUMBER_OF_ROOMS>& rooms);

	void Run();

private:
	std::vector<room>& _building;
	std::array<std::string, NUMBER_OF_ROOMS>& _rooms;
};
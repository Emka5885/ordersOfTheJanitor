#pragma once
#include "State.h"
#include "AddNote.h"
#include "HelperFunctions.h"

class AddNoteState :public State
{
public:
	AddNoteState(std::vector<room>& building, std::array<std::string, NUMBER_OF_ROOMS>& rooms);

	void Run();

private:
	std::vector<room>& _building;
	std::array<std::string, NUMBER_OF_ROOMS>& _rooms;
};
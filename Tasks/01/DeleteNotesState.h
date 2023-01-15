#pragma once
#include "State.h"
#include "DeleteNotes.h"

class DeleteNotesState :public State
{
public:
	DeleteNotesState(std::vector<room>& building, std::array<std::string, NUMBER_OF_ROOMS>& rooms);

	void Run();

private:
	std::vector<room>& _building;
	std::array<std::string, NUMBER_OF_ROOMS>& _rooms;
};
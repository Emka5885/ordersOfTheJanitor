#include "MainLoop.h"
#include "AddNoteState.h"
#include "DeleteNotesState.h"
#include "DisplayNotesState.h"

MainLoop::MainLoop()
{
	quitt = false;
}

void MainLoop::Run(std::vector<room>& building, std::array<std::string, NUMBER_OF_ROOMS>& rooms)
{
	while (!quitt)
	{
		int choice;
		std::cout << "What do you want to do?\n";
		std::cout << "1 - Add new notes\n2 - Delete notes\n3 - View notes\n4 - Quitt\n";
		checkUserInputBetweenMinMax(choice, 1, 4);

		switch (choice)
		{
		case 1:
			_data.AddState(StateRef(new AddNoteState(building, rooms)));
			break;

		case 2:
			_data.AddState(StateRef(new DeleteNotesState(building, rooms)));
			break;

		case 3:
			_data.AddState(StateRef(new DisplayNotesState(building, rooms)));
			break;

		case 4:
			quitt = true;
			std::cout << "See you tomorrow!\n";
			break;
		}

		_data.RemoveState();
	}
}

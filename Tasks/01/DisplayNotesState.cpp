#include "DisplayNotesState.h"

DisplayNotesState::DisplayNotesState(std::vector<room>& building, std::array<std::string, NUMBER_OF_ROOMS>& rooms) : building(building), rooms(rooms)
{
    Run();
}

void DisplayNotesState::Run()
{
    int viewChoice;
        std::cout << "What do you want to do now?\n";
        std::cout << "1 - View all notes\n2 - View notes from one room\n";
        checkUserInputOneOrTwo(viewChoice);

        if (viewChoice == 1)
        {
            viewAllNotes(building);
        }
        else
        {
            int roomChoice;
            std::cout << "From which room you want to display the notes?\n";
            for (int i = 0; i < NUMBER_OF_ROOMS; i++)
            {
                std::cout << i + 1 << " - " << rooms[i] << "\n";
            }
            checkUserInputBetweenMinMax(roomChoice, 1, NUMBER_OF_ROOMS);

            viewAllNotesFromOneRoom(building, rooms[roomChoice - 1]);
        }
}
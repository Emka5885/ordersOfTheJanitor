#include "AddNoteState.h"

AddNoteState::AddNoteState(std::vector<room>& building, std::array<std::string, NUMBER_OF_ROOMS>& rooms) : _building(building), _rooms(rooms)
{
    Run();
}

void AddNoteState::Run()
{
    int howManyNotes;
    std::cout << "How many notes you want to add?\n";
    checkUserInputBetweenMinMax(howManyNotes, 1, 9);

    //we can add several notes at once
    for (int i = 0; i < howManyNotes; i++)
    {
        int roomChoice = 0;
        std::cout << "To which room you want to add a note?\n";

        for (int i = 0; i < NUMBER_OF_ROOMS; i++)
        {
            std::cout << i + 1 << " - " << _rooms[i] << "\n";
        }
        checkUserInputBetweenMinMax(roomChoice, 1, NUMBER_OF_ROOMS);

        std::cout << "Enter the content of the note:\n";
        std::string note;
        std::cin.clear();
        std::cin.ignore();
        std::getline(std::cin, note);
        std::cout << "\n";

        if (!note.empty())
        {
            addNote(_building, _rooms[roomChoice - 1], note);
        }
    }
}
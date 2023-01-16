#include "DeleteNotesState.h"

DeleteNotesState::DeleteNotesState(std::vector<room>& building, std::array<std::string, NUMBER_OF_ROOMS>& rooms) : building(building), rooms(rooms)
{
    Run();
}

void DeleteNotesState::Run()
{
    int deleteAllNotesFromBuilding;
        std::cout << "Whether you want to delete all the notes?\n";
        std::cout << "1 - Yes\n2 - No\n";
        checkUserInputOneOrTwo(deleteAllNotesFromBuilding);

        if (deleteAllNotesFromBuilding == 1)
        {
            //remove all notes from the building
            deleteAllNotes(building);
        }
        else
        {
            int roomChoice;
            std::cout << "From which room you want to remove the note?\n";

            for (int i = 0; i < NUMBER_OF_ROOMS; i++)
            {
                std::cout << i + 1 << " - " << rooms[i] << "\n";
            }
            checkUserInputBetweenMinMax(roomChoice, 1, NUMBER_OF_ROOMS);

            if (building[roomChoice - 1].dailyTasks.empty())
            {
                //if we don't have any notes in the room
                std::cout << "Empty, you can't delete anything!\n";
            }
            else
            {
                int deleteAll;
                std::cout << "Whether you want to remove all notes from the room?\n";
                std::cout << "1 - Yes\n2 - No\n";
                checkUserInputOneOrTwo(deleteAll);

                if (deleteAll == 1)
                {
                    //remove all notes from the specific room
                    deleteAllNotesFromOneRoom(building, roomChoice);
                }
                else
                {
                    std::cout << "Which note you want to delete?\n";

                    //remove a specific note from the room
                    deleteNote(building, roomChoice);
                }
            }
        }
}
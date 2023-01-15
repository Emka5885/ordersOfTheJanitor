#include "DeleteNotes.h"

void deleteNote(std::vector<room>& building, int roomChoice)
{
    int noteToRemove;
    for (int i = 0; i < building[roomChoice - 1].dailyTasks.back().num; i++)
    {
        std::cout << i + 1 << " - " << building[roomChoice - 1].dailyTasks[i].note << "\n";
    }
    checkUserInputBetweenMinMax(noteToRemove, 1, building[roomChoice - 1].dailyTasks.back().num);

    //remove note
    building[roomChoice - 1].dailyTasks.erase(building[roomChoice - 1].dailyTasks.begin() + noteToRemove - 1, building[roomChoice - 1].dailyTasks.begin() + noteToRemove);

    //make sure the notes are numbered in the correct order
    for (int i = 0; i < building[roomChoice - 1].dailyTasks.size(); i++)
    {
        building[roomChoice - 1].dailyTasks[i].num = i + 1;
    }
}

void deleteAllNotesFromOneRoom(std::vector<room>& building, int roomChoice)
{
    building[roomChoice - 1].dailyTasks.clear();
}

void deleteAllNotes(std::vector<room>& building)
{
    for (int i = 0; i < NUMBER_OF_ROOMS; i++)
    {
        building[i].dailyTasks.clear();
    }
}
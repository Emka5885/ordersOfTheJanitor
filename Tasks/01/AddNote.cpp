#include "AddNote.h"

void addNote(std::vector<room>& building, std::string roomName, std::string note)
{
    for (int i = 0; i < NUMBER_OF_ROOMS; i++)
    {
        if (building[i].name == roomName)
        {
            building[i].dailyTasks.push_back(task());
            if (building[i].dailyTasks.size() == 1)
            {
                //if we don't have any notes yet
                building[i].dailyTasks.back().num = 1;
                building[i].dailyTasks.back().note = note;
            }
            else
            {
                building[i].dailyTasks.back().num = building[i].dailyTasks[building[i].dailyTasks.size() - 2].num + 1;
                building[i].dailyTasks.back().note = note;
            }
        }
    }
}
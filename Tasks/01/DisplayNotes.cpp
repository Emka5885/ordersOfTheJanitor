#include "DisplayNotes.h"

void displayActualTasks(std::vector<room>& building, int i)
{
    for (int j = 0; j < building[i].dailyTasks.back().num; j++)
    {
        std::cout << building[i].dailyTasks[j].num << " - " << building[i].dailyTasks[j].note << "\n";
    }
}

void viewAllNotesFromOneRoom(std::vector<room>& building, std::string roomName)
{
    std::cout << "------------------------------\n";
    std::cout << roomName << ": \n";
    bool isEmpty = true;
    for (int i = 0; i < NUMBER_OF_ROOMS; i++)
    {
        if (building[i].name == roomName)
        {
            if (!building[i].dailyTasks.empty())
            {
                displayActualTasks(building, i);
                isEmpty = false;
            }
        }
    }
    if (isEmpty)
    {
        std::cout << "Empty\n";
    }
    std::cout << "------------------------------\n";
    std::cout << "\n";
}

void viewAllNotes(std::vector<room>& building)
{
    std::cout << "------------------------------\n";
    int counter = 0;
    for (int i = 0; i < NUMBER_OF_ROOMS; i++)
    {
        if (!building[i].dailyTasks.empty())
        {
            std::cout << building[i].name << ":\n";
            displayActualTasks(building, i);
        }
        else
        {
            counter++;
        }
    }
    if (counter == NUMBER_OF_ROOMS)
    {
        std::cout << "Empty\n";
    }
    std::cout << "------------------------------\n";
    std::cout << "\n";
}
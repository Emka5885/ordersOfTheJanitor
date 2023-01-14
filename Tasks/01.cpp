/*
Sprint I

Jako wo�ny musz� ogarnia� wszystkie pomieszczenia w miejscu gdzie pracuj�: naprawy, serwisy, przenie�� co�, pod��czy�, zrobi� elektryk�, cokolwiek.
Potrzebuj� aplikacji kt�ra pomog�aby mi nie zagubi� si� w rzeczach kt�re ludzie do mnie zg�aszaj�. W budynku jest 10 pomieszcze�:
Lobby, Biuro 1, Biuro 2, Serwerownia 1, Serwerownia 2, Kuchnia, �azienka, Sala Konferencyjna, Magazyn i moja kanciapa.
Kiedy dostan� informacj�, �e np w Serwerowni 2 u�ama�a si� noga od jakiego� krzes�a, to chcia�bym m�c w programie przypisa� do tego pomieszczenia swoj� notatk�,
gdzie wpisz� o tym informacj�. Takich informacji w ci�gu dnia dostaj� wiele, dlatego potrzebuj� tego programu. Fizyczne karteczki mi si� gubi�.
�eby nie zapomnie�, w ka�dej chwili chcia�bym m�c na rz�danie wy�wietli� list� notatek, tak �ebym wiedzia� w jakim pokoju co jest do wykonania.
Kiedy ju� wykonam dane zadanie, chc� w �atwy spos�b m�c usun�� notatk� z tym zadaniem. Nigdy nie pozwalam sobie na to, �eby wyj�� z pracy przed uko�czeniem wszystkich zada�,
wi�c ja sobie spokojnie rano program w��cz�, b�d� go u�ywa� w ci�gu dnia, wykonam wszystkie zadania, na koniec dnia go wy��cz�, i nast�pnego dnia odpal� go od zera, gotowy na nowe notatki.
Je�li chodzi o to jak ma wygl�da�, to jest mi to totalnie oboj�tne. Urodzi�em si� w 1973 roku, nie dbam o jakie� millenialskie wymys�y typu UX/UI,
chce mie� po prostu dzia�aj�cy program. Mog� obs�ugiwa� go klawiatur�, mog� obs�ugiwa� go myszk�. Mo�e by� czarno bia�y, mo�e by� kolorowy, nie jest to istotne.
*/


#include <iostream>
#include <vector>
#include <array>
#include <string>

//"Magic Number" :D
const int NUMBER_OF_ROOMS = 10;
const int ZERO_IN_ASCII = 48;

//all rooms
std::array<std::string, NUMBER_OF_ROOMS> rooms({ "Lobby", "Biuro 1", "Biuro 2", "Serwerownia 1", "Serwerownia 2", "Kuchnia", "Lazienka", "Sala Konferencyjna", "Magazyn", "Kanciapa" });

struct task
{
    int num;
    std::string note;
};

struct room
{
    std::string name;
    std::vector<task> dailyTasks;
};

//takes one character from the input
int getNumber()
{
    std::string helperNumber;
    std::cout << "Number: ";
    std::cin >> helperNumber;
    return helperNumber[0] - ZERO_IN_ASCII;
}

//add one note to a specific room
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

//display all notes from specific room (helper function)
void displayTasks(std::vector<room>& building, int i)
{
    for (int j = 0; j < building[i].dailyTasks.back().num; j++)
    {
        std::cout << building[i].dailyTasks[j].num << " - " << building[i].dailyTasks[j].note << "\n";
    }
}

//display all notes from specific room
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
                displayTasks(building, i);
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

//display all notes from building
void viewAllNotes(std::vector<room>& building)
{
    std::cout << "------------------------------\n";
    int counter = 0;
    for (int i = 0; i < NUMBER_OF_ROOMS; i++)
    {
        if (!building[i].dailyTasks.empty())
        {
            std::cout << building[i].name << ":\n";
            displayTasks(building, i);
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

//delete one note from specific room
void deleteNote(std::vector<room>& building, int roomChoice)
{
    int noteToRemove;
    for (int i = 0; i < building[roomChoice - 1].dailyTasks.back().num; i++)
    {
        std::cout << i + 1 << " - " << building[roomChoice - 1].dailyTasks[i].note << "\n";
    }
    while (true)
    {
        noteToRemove = getNumber();
        if (noteToRemove >= 1 && noteToRemove <= building[roomChoice - 1].dailyTasks.back().num)
        {
            break;
        }
        else
        {
            std::cout << "Try again\n";
            std::cin.clear();
            std::cin.ignore();
        }
    }
    std::cout << "\n";

    //remove note
    building[roomChoice - 1].dailyTasks.erase(building[roomChoice - 1].dailyTasks.begin() + noteToRemove - 1, building[roomChoice - 1].dailyTasks.begin() + noteToRemove);

    //make sure the notes are numbered in the correct order
    for (int i = 0; i < building[roomChoice - 1].dailyTasks.size(); i++)
    {
        building[roomChoice - 1].dailyTasks[i].num = i + 1;
    }
}

//delete all notes from specific room
void deleteAllNotesFromOneRoom(std::vector<room>& building, int roomChoice)
{
    building[roomChoice - 1].dailyTasks.clear();
}

//delete all notes from building
void deleteAllNotes(std::vector<room>& building)
{
    for (int i = 0; i < NUMBER_OF_ROOMS; i++)
    {
        building[i].dailyTasks.clear();
    }
}

int main()
{
    std::vector<room> building;
    for (int i = 0; i < 10; i++)
    {
        building.push_back(room());
        building.back().name = rooms[i];
    }

    bool quitt = false;

    while (!quitt)
    {
        int choice;
        std::cout << "What do you want to do?\n";
        std::cout << "1 - Add new notes\n2 - Delete notes\n3 - View notes\n4 - Quitt\n";
        while (true)
        {
            choice = getNumber();
            if (choice >= 1 && choice <= 4)
            {
                break;
            }
            else
            {
                std::cout << "Try again\n";
                std::cin.clear();
                std::cin.ignore();
            }
        }
        std::cout << "\n";
        switch (choice)
        {
            //if we want to add new notes
        case 1:
            int howManyNotes;
            std::cout << "How many notes you want to add?\n";
            while (true)
            {
                howManyNotes = getNumber();
                if (howManyNotes >= 1 && howManyNotes <= 9)
                {
                    break;
                }
                else
                {
                    std::cout << "Try again\n";
                    std::cin.clear();
                    std::cin.ignore();
                }
            }
            std::cout << "\n";

            //we can add several notes at once
            for (int i = 0; i < howManyNotes; i++)
            {
                int roomChoice = 0;
                std::cout << "To which room you want to add a note?\n";

                for (int i = 0; i < NUMBER_OF_ROOMS; i++)
                {
                    std::cout << i + 1 << " - " << rooms[i] << "\n";
                }
                while (true)
                {
                    roomChoice = getNumber();
                    if (roomChoice >= 1 && roomChoice <= NUMBER_OF_ROOMS)
                    {
                        break;
                    }
                    else
                    {
                        std::cout << "Try again\n";
                        std::cin.clear();
                        std::cin.ignore();
                    }
                }
                std::cout << "\nEnter the content of the note:\n";
                std::string note;
                std::cin.clear();
                std::cin.ignore();
                std::getline(std::cin, note);
                std::cout << "\n";

                if (!note.empty())
                {
                    addNote(building, rooms[roomChoice - 1], note);
                }
            }

            break;

            //if we want to delete notes
        case 2:
            int deleteAllNotesFromBuilding;
            std::cout << "Whether you want to delete all the notes?\n";
            std::cout << "1 - Yes\n2 - No\n";
            while (true)
            {
                deleteAllNotesFromBuilding = getNumber();
                if (deleteAllNotesFromBuilding == 1 || deleteAllNotesFromBuilding == 2)
                {
                    break;
                }
                else
                {
                    std::cout << "Try again\n";
                    std::cin.clear();
                    std::cin.ignore();
                }
            }
            std::cout << "\n";
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
                while (true)
                {
                    roomChoice = getNumber();
                    if (roomChoice >= 1 && roomChoice <= NUMBER_OF_ROOMS)
                    {
                        break;
                    }
                    else
                    {
                        std::cout << "Try again\n";
                        std::cin.clear();
                        std::cin.ignore();
                    }
                }
                std::cout << "\n";

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
                    while (true)
                    {
                        deleteAll = getNumber();
                        if (deleteAll == 1 || deleteAll == 2)
                        {
                            break;
                        }
                        else
                        {
                            std::cout << "Try again\n";
                            std::cin.clear();
                            std::cin.ignore();
                        }
                    }
                    std::cout << "\n";
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

            break;

            //if we want to display the notes
        case 3:
            int viewChoice;
            std::cout << "What do you want to do now?\n";
            std::cout << "1 - View all notes\n2 - View notes from one room\n";
            while (true)
            {
                viewChoice = getNumber();
                if (viewChoice == 1 || viewChoice == 2)
                {
                    break;
                }
                else
                {
                    std::cout << "Try again\n";
                    std::cin.clear();
                    std::cin.ignore();
                }
            }
            std::cout << "\n";

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
                while (true)
                {
                    roomChoice = getNumber();
                    if (roomChoice >= 1 && roomChoice <= NUMBER_OF_ROOMS)
                    {
                        break;
                    }
                    else
                    {
                        std::cout << "Try again\n";
                        std::cin.clear();
                        std::cin.ignore();
                    }
                }
                std::cout << "\n";

                viewAllNotesFromOneRoom(building, rooms[roomChoice - 1]);
            }

            break;

            //if we want to quit
        case 4:
            quitt = true;
            std::cout << "See you tomorrow!\n";
            break;
        }
    }
}

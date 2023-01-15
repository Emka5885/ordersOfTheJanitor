/*
Sprint I

Jako woŸny muszê ogarniaæ wszystkie pomieszczenia w miejscu gdzie pracujê: naprawy, serwisy, przenieœæ coœ, pod³¹czyæ, zrobiæ elektrykê, cokolwiek.
Potrzebujê aplikacji która pomog³aby mi nie zagubiæ siê w rzeczach które ludzie do mnie zg³aszaj¹. W budynku jest 10 pomieszczeñ:
Lobby, Biuro 1, Biuro 2, Serwerownia 1, Serwerownia 2, Kuchnia, £azienka, Sala Konferencyjna, Magazyn i moja kanciapa.
Kiedy dostanê informacjê, ¿e np w Serwerowni 2 u³ama³a siê noga od jakiegoœ krzes³a, to chcia³bym móc w programie przypisaæ do tego pomieszczenia swoj¹ notatkê,
gdzie wpiszê o tym informacjê. Takich informacji w ci¹gu dnia dostajê wiele, dlatego potrzebujê tego programu. Fizyczne karteczki mi siê gubi¹.
¯eby nie zapomnieæ, w ka¿dej chwili chcia³bym móc na rz¹danie wyœwietliæ listê notatek, tak ¿ebym wiedzia³ w jakim pokoju co jest do wykonania.
Kiedy ju¿ wykonam dane zadanie, chcê w ³atwy sposób móc usun¹æ notatkê z tym zadaniem. Nigdy nie pozwalam sobie na to, ¿eby wyjœæ z pracy przed ukoñczeniem wszystkich zadañ,
wiêc ja sobie spokojnie rano program w³¹czê, bêdê go u¿ywa³ w ci¹gu dnia, wykonam wszystkie zadania, na koniec dnia go wy³¹czê, i nastêpnego dnia odpalê go od zera, gotowy na nowe notatki.
Jeœli chodzi o to jak ma wygl¹daæ, to jest mi to totalnie obojêtne. Urodzi³em siê w 1973 roku, nie dbam o jakieœ millenialskie wymys³y typu UX/UI,
chce mieæ po prostu dzia³aj¹cy program. Mogê obs³ugiwaæ go klawiatur¹, mogê obs³ugiwaæ go myszk¹. Mo¿e byæ czarno bia³y, mo¿e byæ kolorowy, nie jest to istotne.
*/


#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "Room.h"
#include "HelperFunctions.h"
#include "AddNote.h"
#include "DisplayNotes.h"
#include "DeleteNotes.h"

//all rooms
std::array<std::string, NUMBER_OF_ROOMS> rooms({ "Lobby", "Biuro 1", "Biuro 2", "Serwerownia 1", "Serwerownia 2", "Kuchnia", "Lazienka", "Sala Konferencyjna", "Magazyn", "Kanciapa" });

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
        checkUserInputBetweenMinMax(choice, 1, 4);
        switch (choice)
        {
            //if we want to add new notes
        case 1:
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
                    std::cout << i + 1 << " - " << rooms[i] << "\n";
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
                    addNote(building, rooms[roomChoice - 1], note);
                }
            }

            break;

            //if we want to delete notes
        case 2:
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

            break;

            //if we want to display the notes
        case 3:
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

            break;

        case 4:
            quitt = true;
            std::cout << "See you tomorrow!\n";
            break;
        }
    }
}

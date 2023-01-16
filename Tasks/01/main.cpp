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

#include "MainLoop.h"

std::array<std::string, NUMBER_OF_ROOMS> rooms({ "Lobby", "Biuro 1", "Biuro 2", "Serwerownia 1", "Serwerownia 2", "Kuchnia", "Lazienka", "Sala Konferencyjna", "Magazyn", "Kanciapa" });

int main()
{
    std::vector<room> building;
    for (int i = 0; i < 10; i++)
    {
        building.push_back(room());
        building.back().name = rooms[i];
    }


    MainLoop main;
    main.Run(building, rooms);

    return 0;
}

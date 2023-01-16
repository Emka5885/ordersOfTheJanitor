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

#include "HelperFunctions.h"

int promptUserForNumber()
{
    std::string helperNumber;
    std::cout << "Number: ";
    std::cin >> helperNumber;
    return helperNumber[0] - ZERO_IN_ASCII;
}

void checkUserInputBetweenMinMax(int& variable, int min, int max)
{
    while (true)
    {
        variable = promptUserForNumber();
        if (variable >= min && variable <= max)
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
}

void checkUserInputOneOrTwo(int& variable)
{
    while (true)
    {
        variable = promptUserForNumber();
        if (variable == 1 || variable == 2)
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
}
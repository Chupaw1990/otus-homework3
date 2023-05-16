#include <iostream>
#include "guess.h"
#include "file_managment.h"
#include "random_value.h"

bool guess_func(int number){

    int player_number;
    std::cout << "Please enter number:" << std::endl;
    std::cin >> player_number;
    
    if (number < player_number)
    {
        std::cout << "Less than " << player_number << std::endl;
        return !false;
    }

    if (number > player_number)
    {
        std::cout << "Greate than " << player_number << std::endl;
        return !false;
    }

    if (number == player_number)
    {
        std::cout << "You win!!! ";
        return !true;
    }
}

void play_game(int max_number)
{
      std::string player_name;
        int attempt = 1;
        bool guess = false;
        int number = random_value(max_number);

        std::cout << "Please enter your name:" << std::endl;
        std::cin >> player_name;

        while (guess_func(number)) attempt++;
        std::cout << "attempts = " << attempt << std::endl;
        std::cout << std::endl;

        write_score(player_name, attempt);
        read_score();
}
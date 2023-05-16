#include <ctime>
#include <iostream>
#include "random_value.h"

int random_value(int max_number){
    
    std::srand(std::time(nullptr));
    const int max_value = max_number;
    const int random_value = std::rand() % max_value;

    return random_value;
};
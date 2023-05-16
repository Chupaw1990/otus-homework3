#include <iostream>
#include <string>
#include "random_value.h"
#include "guess.h"
#include "file_managment.h"

#define DEFAUTL_MAX_NUMBER 100
#define DIFICUILT_LEVEL_ONE 10
#define DIFICUILT_LEVEL_TWO 50

int main(int argc, char* argv[]) {
    if (argc < 2){
        play_game(DEFAUTL_MAX_NUMBER);
    }else{
        std::string arg_value = argv[1];
        if (arg_value == "-max"){
            if(argc < 3)
            {
                std::cout << "No match arguments for \"-max\"" << std::endl;
                return 1;
            }else{
                play_game(std::stoi(argv[2]));
            }
            
        }
        if (arg_value == "-table"){
            read_score();
        }
        if (arg_value == "-level"){
            if(argc < 3)
            {
                std::cout << "No match arguments for \"-level\"" << std::endl;
                return 1;
            }else{
            
                switch (std::stoi(argv[2]))
                {
                case 1:
                    play_game(DIFICUILT_LEVEL_ONE);
                    break;
                case 2:
                    play_game(DIFICUILT_LEVEL_TWO);
                    break;
                case 3:
                    play_game(DEFAUTL_MAX_NUMBER);
                default:
                    play_game(DEFAUTL_MAX_NUMBER);
                    break;
                }
            }
        }
    }
    return 0;
}

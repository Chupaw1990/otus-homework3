#include "file_managment.h"


void write_score(std::string& player_name, int& attempts) {

    std::map <std::string, int> map_score;
    map_score = read_score_in_map();
    
    std::fstream file ("score.txt", std::ios_base::out | std::fstream::trunc);

    if (!file.is_open()){
        std::cout << "Error: File was not open";
        return;
    }

    std::map<std::string, int>::iterator it = map_score.find(player_name);

    if(map_score.count(player_name)){
        std::map<std::string, int>::iterator it = map_score.find(player_name);
        if(it->second > attempts){
            it->second = attempts;
        }
    }else{
        map_score.insert(make_pair(player_name, attempts));
    }

    it = map_score.begin();
    while (it != map_score.end()) 
    {
        file << it->first << ' ' << it->second << std::endl;
        ++it;
    }
    
    file.close();
}

void read_score()
{
    std::fstream file ("score.txt", std::ios_base::in);
    if (!file.is_open()){
        std::cout << "Error: File was not open";
        return;
    }

    std::string line;
    while (getline(file, line)) std::cout << line << std::endl;
    file.close();
}

std::map<std::string,int> read_score_in_map(){
    std::map <std::string, int> map_score;
    std::fstream file ("score.txt", std::ios_base::in);

    if (!file.is_open()){
        std::cout << "Error: File was not open";
        return map_score;
    }

    std::string username;
    int attempts;

    while (true){
        file >> username;
        file >> attempts;
        file.ignore();

        map_score.insert(make_pair(username, attempts));

        if (file.fail()) {
            break;
        }
    }
    file.close();

    return map_score;
}
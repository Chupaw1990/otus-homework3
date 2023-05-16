#pragma once

#include <iostream>
#include <fstream>
#include <map>

void write_score(std::string& player_name, int& attempts);
void read_score();
std::map<std::string,int> read_score_in_map();
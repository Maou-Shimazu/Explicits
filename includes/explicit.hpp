#pragma once

#include <iostream>
#include <map>
#include <random>
#include <vector>
#include <string>
#include <array>

template<class T>
void print(T out){
    std::cout << out << "\n";
}
auto endline = [] { std::cout << std::endl; };

// map of player values
std::map<std::string, std::string> player = {
    {"Name", ""},
    {"Health", "100"},
    {"Attack", "16"},
    {"Heal", "16"},
}; // name, health, attack, heal, 

// map of monster values
std::map<std::string, std::string> monster = {
    {"Name", "Marx"},
    {"Health", "100"},
    {"Attack", "16"},
    {"Heal", "16"},
}; // name, health, attack, heal,

std::vector<std::string> monster_names = {
    "Marx",
    "Bambino",
    "Kale"
}; // list of monster names that will be used for monsters per level.

struct Player {
    int health = stoi(player["Health"]);;
    int attack = stoi(player["Attack"]);
    int heal = stoi(player["Heal"]);
};
Player p; // struct to interface with player value easier

struct Monster{
    int health = stoi(monster["Health"]);;
    int attack = stoi(monster["Attack"]);
    int heal = stoi(monster["Heal"]);
};
Monster m;

std::vector<uint8_t> levels;

void player_stats(){
    //std::map<std::string, std::string>::reverse_iterator i;
    for(auto i = player.rbegin(); i != player.rend(); ++i){
        std::cout << i->first << ": " << i->second << ", ";
    }
}

void monster_stats(){
    for(auto i = monster.rbegin(); i != monster.rend(); ++i){
        std::cout << i->first << ": " << i->second << ", ";
    }
}

void player_attack(){

}

void monster_attack(){

}

const char* player_options =
R"(
[1] Attack
[2] Heal
[3] Player stats)"; 
    //todo: main menu for start of game
    //todo: add leveling system for user and monster
    //todo: add powerups with random damage and cool catchphrases.
    //todo: stat system

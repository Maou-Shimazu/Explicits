#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <array>
#include <random>

typedef std::mt19937 RNG; // RNG is a type that references the mersenne random number generator of c++11
RNG rng; // generator object

template<class T>
void print(T out){
    std::cout << out << "\n";
}

/**
 * Lambda declarations.
 * */

auto endline = [] { std::cout << std::endl; };
auto decor = [] { std::cout << "==================>" << "\n"; };

// map of player values
std::map<std::string, std::string> player = {
    {"Name", ""},
    {"Health", "100"},
    {"Attack", "16~20"},
    {"Heal", "10"},
}; // name, health, attack, heal, 

// map of monster values
std::map<std::string, std::string> monster = {
    {"Name", "Marx"},
    {"Health", "100"},
    {"Attack", "18"},
}; // name, health, attack

std::vector<std::string> monster_names = {
    "Marx",
    "Bambino",
    "Kale"
}; // list of monster names that will be used for monsters per level.

// struct to interface with player value easier
struct Player {
    int health = stoi(player["Health"]);;
    int attack = stoi(player["Attack"]);
    int heal = stoi(player["Heal"]);
};
Player p; // player struct object

// struct to interface with monster value easier
struct Monster{
    int health = stoi(monster["Health"]);;
    int attack = stoi(monster["Attack"]);
};
Monster m; // monster struct object

std::vector<uint8_t> levels;

// Iterate through the player hashmap in reverse order
void player_stats(){
    for(auto i = player.rbegin(); i != player.rend(); ++i){
        std::cout << i->first << ": " << i->second << "\n";
    }
}

// Iterate through the monster hashmap in reverse order
void monster_stats(){
    for(auto i = monster.rbegin(); i != monster.rend(); ++i){
        std::cout << i->first << ": " << i->second << "\n";
    }
}

void player_attack(){
    std::uniform_int_distribution<uint32_t> range(16,20);
    m.health = m.health - range(rng); //remove rand
    monster["health"] = std::to_string(m.health);
}

void monster_attack(){
    p.health = p.health - 18; // remove rand
    player["health"] = std::to_string(p.health);
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

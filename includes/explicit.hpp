#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <array>
#include <random>
#include <algorithm>
#include <tuple>

typedef std::mt19937 RNG; // RNG is a type that references the mersenne random number generator of c++11
RNG rng; // generator variable
typedef std::uniform_int_distribution<uint32_t> Range; // Uniform int distribution type definition.
typedef std::default_random_engine drg;

template<class T>
void print(T out){
    std::cout << out << "\n";
}

/**
 * Lambda declarations.
 * */

auto endline = [] { std::cout << std::endl; };
// the decoration lambda
auto decor = [] { std::cout << "==================>" << "\n"; };

// map of player values
std::map<std::string, std::string> player = {
    {"Name", ""},
    {"Health", "100"},
    {"Attack", "16~20"},
    {"Heal", "16~20"},
}; // name, health, attack, heal, 

// map of monster values
std::map<std::string, std::string> monster = {
    {"Monster", ""},
    {"Health", "100"},
    {"Attack", "18"},
}; // name, health, attack

std::vector<std::string> monster_names = {
    "Marx",
    "Bambino",
    "Kale"
}; // list of monster names that will be used for monsters per level.


std::vector<std::string> monster_death_message = {
    "The monster was eradicated by the galliant hero.",
    "A strong attack and a fatal blow, The monster is dead!",
    "Your special attack "
};


// struct to interface with player value easier
struct Player {
    int health = stoi(player["Health"]);
    int attack = stoi(player["Attack"]);
    int heal = stoi(player["Heal"]);
};
Player p; // player struct object

// struct to interface with monster value easier

struct Monster{    
    int health = stoi(monster["Health"]);
    int attack = stoi(monster["Attack"]);
};
Monster m; // monster struct object

std::vector<uint8_t> levels;

// Iterate through the player hashmap in reverse order
const void player_stats() {
    for(auto i = player.rbegin(); i != player.rend(); ++i){
        std::cout << i->first << ": " << i->second << "\n";
    }
}

// Player stats overload for different output look.
const void player_stats(int game){
    for(auto i = player.rbegin(); i != player.rend(); ++i){
        std::cout << i->first << ": " << i->second << ", ";
    }
}

// Iterate through the monster hashmap in reverse order
const void monster_stats(){
    for(auto i = monster.rbegin(); i != monster.rend(); ++i){
        std::cout << i->first << ": " << i->second << "\n";
    }
}
// Player attack function
void player_attack(){
    Range monster_attack_range(16,20);
    m.health = m.health - monster_attack_range(rng);
    monster["health"] = std::to_string(m.health);
}

// Monster attack function
void monster_attack(){
    p.health = p.health - 18;
    player["health"] = std::to_string(p.health);
}

// Player heal lambda
auto player_heal = [] { 
    Range player_heal_range(16, 20); 
    p.health += player_heal_range(rng); 
};

// Main options menu
const char* player_options =
R"(
[1] Attack
[2] Heal
[3] Player stats)";
    //todo: add leveling system for user and monster
    //todo: add powerups with random damage and cool catchphrases.
    //todo: stat system

#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <array>
#include <random>
#include <algorithm>
#include <tuple>
#include <ctime>
#include <stdio.h>
#include "drawille.hpp"
// #include "random.hpp"
// using Random = effolkronium::random_static; // available for those who dont want to use cpp_gen(); documentation examples are listed here: https://github.com/effolkronium/random#five-minute-tutorial
// todo: add random.hpp to repo

/**
 * ---
 * Info: The general idea.
 * Store player/monster frequently updated configurations in either structs or classes.
 * Store other information like powers and landscape with values that are only changed after certain events.
 * ---
 */

std::random_device rd; // random device variable
std::mt19937 mt{rd()}; // random number generator
typedef std::uniform_int_distribution<> Range; // Uniform int distribution type definition.

/**
 * Lambda declarations.
 * */

auto endline = [] { std::cout << std::endl; };
// the decoration lambda
auto decor = [] { std::cout << "=================>" << "\n"; };

// C++11 random number genertor;
uint32_t cpp_gen (int min, int max) {
    Range range(min, max);
    return range(rd);
};

// C random number generator
int random_gen (int size) {
    srand(time(NULL));
    return rand() % size;
};

std::map<std::string, uint16_t> player_powers = {
    {"Freeze", 6},
    {"Lava", 8},
};

std::vector<std::string> monster_names = {
    "Marx",
    "Bambino",
    "Kale"
}; // list of monster names that will be used for monsters per level.

std::vector<std::string> monster_death_message = {
    "The monster was eradicated by the galliant hero.",
    "A strong attack and a fatal blow, The monster is dead!",
    "Your special attack has abolished the vile villain!"
};

// Player config
struct Player {
    std::string name;
    int health = 100;
    int attack;
    int heal;
};
Player p; // player struct object

// Monster config
struct Monster{
    std::string name;
    int health = 100;
    int attack = 18;
};
Monster m; // monster struct object

std::vector<uint8_t> levels;

// Player attack function
void player_attack(){ m.health -= cpp_gen(16,20); }

// Monster attack function
void monster_attack(){ p.health -= 18; }

// Player heal function
void player_heal() { p.health += cpp_gen(16, 20); };

// Iterate through player power's
void ppowers(){ for (auto i : player_powers)  std::cout << i.first + ", "; }

// Player stats function
void player_stats(std::string n = "") { 
    std::cout << "Name: " << p.name << n
    << "Health: " << p.health << n
    << "Attack: " << p.attack << n
    << "Heal: " << p.heal << n
    << "Powers: "; ppowers();
    std::cout 
    << "\nMap: "
    << "\n";
}

// Monster stats function
void monster_stats(std::string n = "") { 
    std::cout << "Name: " << m.name << n
    << "Health: "<< m.health << n 
    << "Attack: "<< m.attack
    << "\n";
}

// Main options menu
const char* player_options =
R"(
[1] Attack
[2] Heal
[3] Player stats
[4] Power Up)";
    ///---
    //todo: add leveling system for user and monster
    //todo: add powerups with random damage and cool catchphrases.
    //todo: stat system ✅️

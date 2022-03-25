#pragma once

#include <iostream>
#include <map>
#include <random>
#include <vector>
#include <string>

std::map<std::string, std::string> player = {
    {"name", ""},
    {"health", "100"},
    {"attack", "16"},
    {"heal", "16"},
}; // name, health, attack, heal, 

std::map<std::string, std::string> monster = {
    {"name", "Marx"},
    {"health", "100"},
    {"attack", "16"},
    {"heal", "16"},
}; // name, health, attack, heal,

std::vector<std::string> monster_names = {
    "Marx",
    "Bambino",
    "Kale"
}; // list of monster names that will be used for monsters per level.

struct Player {
    int health = stoi(player["health"]);;
    int attack = stoi(player["attack"]);
    int heal = stoi(player["heal"]);
};
Player p; // struct to interface with player value easier

std::vector<uint8_t> levels;

const char* player_options =
R"(

)"; //todo: main menu for start of game
    //todo: add leveling system for user and monster
    //todo: add powerups with random damage and cool catchphrases.

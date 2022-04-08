#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <tuple>
#include <ctime>
#include <stdio.h>
#include <thread>
#include <iomanip>

#include "random.hpp" // todo: add random.hpp to repo ✅
using Random = effolkronium::random_static; // Documentation examples are listed here: https://github.com/effolkronium/random#five-minute-tutorial


/**
 * ---
 * Info: The general idea.
 * Store player/monster frequently updated configurations in either structs or classes.
 * Store other information like powers and landscape with values that are only changed after certain events.
 * ---
 */


//--- Global Definitions
// Lambdas
auto endline = [] { std::cout << std::endl; };
auto decor = [] { std::cout << "=================>" << "\n"; };

/**
 * @brief  Progress Bar function.
 * @param  time: time till completion, default set to `100`
 * @param  symbol: character to be used, default set to `=`
 * @retval void
 */
void progress_bar(int time = 100, char symbol = '='){
    std::string progress_bar = ">";
    static const double progress_level = 1.42f;
    std::cout << std::setw(81) << "]";
    for (double percentage = 0; percentage <= 100; percentage += progress_level){
        progress_bar.insert(0, 1, symbol);
        std::cout << "\r[" << std::ceil(percentage) << '%' << "] " << "[" << progress_bar;
        std::this_thread::sleep_for(std::chrono::milliseconds(time));       
    }
    std::cout << "\n";
}

// C random number generator
int random_gen (int size) {
    srand(time(NULL));
    return rand() % size;
};

std::vector<uint8_t> levels;

//--- Player Class
class Player {
protected:
    std::string name;
    int32_t health_value = 100;
    int32_t attack_value = Random::get<int32_t>(16, 20);
    int32_t heal_value;
    std::map<std::string, uint16_t> powers = {
        {"Freeze", 6},
        {"Lava", 8},
    };
    std::vector<std::string> power_names = {
        "Freeze", "Lava",
    };
public:
// set:
    void set_name(std::string name){ this->name = name; }
    void set_attack(int32_t attack_value){ this->attack_value = attack_value; }
    void set_health(int32_t health_value){ this->health_value = health_value; }
    void set_heal(int32_t heal_value){ this->heal_value = heal_value; }
    void add_power(std::string key, uint16_t value){ powers[key] = value; }
// get:
    std::string get_name(){ return name; }
    int32_t get_health(){ return health_value; }
    int32_t get_attack(){ return attack_value; }
    int32_t get_heal(){ return heal_value; }
    std::map<std::string, uint16_t> get_powers(){ return powers; }
    std::vector<std::string> get_power_names(){ return power_names; };
    

    // Iterate through player power's
    void power_iterator(){ for (auto i : powers)  std::cout << i.first + ", "; }
    void power_up();
    // Player attack prototype
    void attack(); // function prototype implimented below monster class creation because it wont be found in this scope.
    
    // Player heal function
    void heal() { health_value += Random::get<uint32_t>(16, 20); };
    // Player stats function
    void stats(std::string n = "") { 
        std::cout << "Name: " << name << n
        << "Health: " << health_value << n
        << "Attack: " << attack_value << n
        << "Heal: " << heal_value << n
        << "Powers: "; power_iterator();
        std::cout 
        << "\nMap: "
        << "\n";
    }
};
Player player;

//--- Monster Class
class Monster : public Player {
protected:
    std::string name;
    int32_t health_value = 100;
    int32_t attack_value = Random::get<int32_t>(16, 20);
    std::vector<std::string> names_list = {
        "Marx",
        "Bambino",
        "Kale"
    }; // list of monster names that will be used for monsters per level. 
    std::vector<std::string> death_message = {
        "The monster was eradicated by the galliant hero.",
        "A strong attack and a fatal blow, The monster is dead!",
        "Your special attack has abolished the vile villain!"
    };
public:
// set
    void set_name(std::string name){ this->name = name; }
    void set_attack(int32_t attack_value){ this->attack_value = attack_value; }
    void set_health(int32_t health_value){ this->health_value = health_value; }
// get
    std::string get_name(){ return name; }
    int get_health(){ return this->health_value; }
    int get_attack(){ return this->attack_value; }
    std::vector<std::string> get_names_list(){ return names_list; }
    std::vector<std::string> get_death_message() { return death_message; }

    // Monster attack prototype
    void attack();

    // Monster stats function
    void stats(std::string n = "") { 
        std::cout << "Name: " << this->name << n
        << "Health: "<< this->health_value << n 
        << "Attack: "<< this->attack_value
        << "\n";
    }
};
Monster monster;

//--- Prototype Definitions
void Player::attack(){ monster.set_health(monster.get_health() - attack_value); }

void Player::power_up(){
  std::string p = power_names[random_gen(power_names.size())];  // power
  monster.set_health(monster.get_health() - powers[p]);
  std::cout << "You activated: " << p << "! You dealt " << powers[p] << " damage to the monster!\n";
}

void Monster::attack(){ player.set_health(player.get_health() - attack_value); }

//--- TUI OPS
const char* player_options =
R"(
[1] Attack
[2] Heal
[3] Player stats
[4] Power Up)";
    //todo: add leveling system for user and monster
    //todo: add powerups with random damage and cool catchphrases. ✅
    //todo: create implimentation of getch();
    //todo: dehardcode values and add them to a public class scope 
    //warning: player's and monsters only die in option 1 of the switch, impliment a global check. 🛑
    //todo: stat system ✅️

void load_menu(){
    std::cout <<
R"(
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
+                                                                                       +
+                                                                                       +
+                                                                                       +
+                                                                                       +
+                                                                                       +
+                                                                                       +
+                                                                                       +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++)"
    << std::endl;
};

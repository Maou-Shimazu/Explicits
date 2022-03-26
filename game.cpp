#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <map>
#include <ctime>
/**
 /// * Fmt is the C++ formatting library. For more information checkout https://github.com/fmtlib/fmt
* */
#include "includes/explicit.hpp"
/**
 /// * Explicit is where all definitions should go, impliment everything in the header file like a distingushed individual.
**/
//     for (int x = 1; x <= 10; x++)
//     {
//         std::string animal_name;
//         std::cout << "Enter an animal name (" << x << ")";
//         std::cin >> animal_name;

//         std::map <std::string, int>::iterator it;

//         for (it = animals.begin(); it != animals.end(); it++)
//         {
//             if (it->first == animal_name)
//             {
//                 it->second++;
//             }
//         }

//     }

/**
 * * Trash comments: Put useless/useful code here
 * player["health"] = std::to_string(player_health);
   std::cout << "New Player health: " << player["health"] << std::endl;
 * 
 *  int player_health = stoi(player["health"]);
    int player_attack = stoi(player["attack"]);
    int player_heal = stoi(player["heal"]);
 *    
 *  std::cout << "Enter new health: ";
    std::cin >> p.health;
 * 
 * std::map <std::string, std::string>::iterator it;
   for(it = player.begin(); it != player.end(); ++it){
       std::cout << it->first << ": " << it->second << ", ";
   }
 * * Lambda is either:
    auto variable = [] (new variable) { //body }
 *  auto variable = [new variable] { //body }
 * 
 *  int n = 0;
 *  auto variable_name = [&, n] (int new_variable) { do stuff with n and new_variable }  
 */

int main(){
    bool game_is_running = true; // boolean for main game loop.

    srand(0);
    uint16_t random = rand() + 1 % 10; // uint stands for unsigned int, this can also be written as `unsigned short random`.
    
    while(game_is_running != false){
        std::cout << "Enter Player Name: ";
        std::cin >> player["Name"];
        
        endline();
        player_stats();
        endline();
        monster_stats();
        endline();
        bool round = true;
        while (round != false) {

            print(player_options);
            std::cout << "====> ";
            uint16_t ans; std::cin >> ans;
            switch(ans){
                case 1: player_attack(); break;
                case 2: break;
                case 3: player_stats();
                case 505: round = false; break;
            }
            monster_attack();
        }
        game_is_running = false;
    }

    return 0;
}
// i am so lost... -huei
//bing bong gonna fuck your life up 
//lol
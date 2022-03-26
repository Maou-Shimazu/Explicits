#define _GLIBCXX_USE_CXX11_ABI 0
#include "includes/explicit.hpp"
/**
 /// * Explicit is where all definitions should go, impliment everything in the header file like a distingushed individual.
**/

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

        decor();
        player_stats();
        decor();
        monster_stats();
        decor();
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
            print(p.health);
            print(m.health);
        }
        game_is_running = false;
    }

    return 0;
}
// i am so lost... -huei
//bing bong gonna fuck your life up 
//lol
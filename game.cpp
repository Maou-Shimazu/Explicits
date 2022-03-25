#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <map>
/**
 /// * Fmt is the C++ formatting library. For more information checkout https://github.com/fmtlib/fmt
* */
#include "includes/explicit.hpp"
/**
 /// * Explicit is where all definitions should go, impliment everything in the header file like a distingushed individual.
**/
//     std::map<std::string, int> animals = { {"fox", 0},{"sheep",0},{"turtle",0} };
//     std::cout << "Hello user. You will be prompted ten(10) times to enter the name of an animal." << std::endl;
//     std::cout << "You are only allowed to enter animals from the list [fox, sheep, turtle]. Thank you." << std::endl;

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

//     std::cout << "fox    --> " << animals["fox"] << std::endl;
//     std::cout << "sheep  --> " << animals["sheep"] << std::endl;
//     std::cout << "turtle --> " << animals["turtle"] << std::endl;

int main(){
    bool game_is_running = true;
    player.insert(std::pair<std::string, std::string>("attack", "16"));
    player.insert(std::pair<std::string, std::string>("health", "100"));
    int player_health = stoi(player["health"]);
    int player_attack = stoi(player["attack"]);
    while(game_is_running != false){
        std::cout << "Enter Player Name: ";
        std::cin >> player["name"];
        std::cout <<"Player name: "<< player["name"] << std::endl;
        // std::cout << stoi(player["health"]);
        std::cout << "Health: " << player_health << std::endl;
        std::cout << "Attack: " << player_attack << std::endl;
        
        game_is_running = false;
        
    }

    return 0;
}
// i am so lost... -huei
//bing bong gonna fuck your life up 
//lol
#define _GLIBCXX_USE_CXX11_ABI 0
#include "includes/explicit.hpp"
/**
 /// * Explicit is where all definitions should go, impliment everything in the header file like a distingushed individual.
**/

int main(){
	load_menu();
    std::cout << "\nLoading game configurations: " << std::endl;
    progress_bar(10);
	std::cout << "\nPress Enter to Play ";
	std::cin.ignore();
	
    bool game_is_running = true; // boolean for main game loop.
    
    
    while(game_is_running != false){
        std::cout << "Enter Player Name: ";
        std::string p_name; std::cin >> p_name; player.set_name(p_name); // storing playe's name inside the map 

        std::vector<std::string> m_n_l = monster.get_names_list(); // monster names list
        std::string m_name = m_n_l[random_gen(m_n_l.size())]; // assigning the monster a random name.
        monster.set_name(m_name);

        decor();
        player.stats(",\n");
        decor();
        monster.stats(",\n");
        decor();
        bool round = true; uint16_t counter = 0;
        while (round != false) {

            std::cout << player_options << std::endl;
            std::cout << "====> ";
            uint16_t ans; std::cin >> ans; // uint stands for unsigned int, this can also be written as `unsigned short random`.
            switch(ans){
                case 1:
                    player.attack();
                    monster.attack();
                    if(monster.get_health() <= 0){
                        std::vector<std::string> m_d_m = monster.get_death_message(); // monster death message
                        std::cout << m_d_m[random_gen(m_d_m.size())] <<std::endl;
                        round = false;
                    }
                    else if(player.get_health() <= 0){
                        std::cout << "You died!\n";
                        round = false;
                    }
                break;

                case 2: player.heal(); monster.attack(); 
                break;

                case 3: player.stats(", "); 
                break;

                case 505: round = false; 
                break;

                case 4: player.power_up();
                break;
            }
            std::cout << "\n" << player.get_name() << " Health: " << player.get_health() << "\n";
            std::cout << monster.get_name() << " Health: " << monster.get_health() << "\n";
        }
        counter++;
        game_is_running = false;
    }
    fflush(stdin);
    getchar();
    return 0;
}
// i am so lost... -huei
//lol
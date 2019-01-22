#include <iostream>

#include "store.hpp"
#include "player.hpp"

int main(int argc, char **argv) {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1024/*DEFAULT_SCREEN_WIDTH*/, 600/*DEFAULT_SCREEN_HEIGHT*/), "Store");
    std::shared_ptr<sf::RenderWindow> win_ptr(window);
    Player* player = new Player;
    std::shared_ptr<Player> player_ptr(player);
    
    Store store(win_ptr, player_ptr);

    store.display();

    std::cout << "Soldiers: " << std::endl;
    std::vector<Soldier> check = player->get_soldiers();
    for (int i = 0; i < check.size(); i++) {
        std::cout << check[i].get_name().toAnsiString() << std::endl;
    }        

    return 0;
}

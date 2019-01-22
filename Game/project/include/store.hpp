#ifndef NEW_STRATEGY_1_PROJECT_INCLUDE_STORE_HPP
#define NEW_STRATEGY_1_PROJECT_INCLUDE_STORE_HPP

#include "definitions.hpp"
#include "store_definitions.hpp"
#include "tab.hpp"
#include "player.hpp"

class Store {
 private:
    // store
    std::shared_ptr<sf::RenderWindow> window_;
    std::shared_ptr<Player> player_;
    sf::Font font_;
    sf::RectangleShape border_;
    sf::Vector2f position_;
    sf::Vector2f size_;
    Button back_;
    // tabs
    int active_tab_;
    std::array<std::string, NUM_OF_TABS> tabnames_;
    std::array<sf::Text, NUM_OF_TABS> tabnames_sf_;
    std::array<sf::Vector2f, NUM_OF_TABS> tabheaderpositions_;
    std::array<sf::Vector2f, NUM_OF_TABS> tabheadersizes_;
    std::array<Tab, NUM_OF_TABS> tabs_;
 public:
    Store(std::shared_ptr<sf::RenderWindow>& window, std::shared_ptr<Player>& player);
    void display();
};

#endif  // NEW_STRATEGY_1_PROJECT_INCLUDE_STORE_HPP

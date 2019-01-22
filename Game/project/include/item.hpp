#ifndef NEW_STRATEGY_1_PROJECT_INCLUDE_ITEM_HPP
#define NEW_STRATEGY_1_PROJECT_INCLUDE_ITEM_HPP

#include "object.hpp"
#include "misting.hpp"
#include "mistborn.hpp"
#include "soldier.hpp"
#include "metal.hpp"

#include "button.hpp"

#include "store_definitions.hpp"
#include "definitions.hpp"

class Item {
 private:
    int deep_type_;        // soldier, mistborn, misting or metall
    int num_;
    int num_of_parent_; 
    int type_;            // metall or hero
    std::array<sf::Text, NUM_OF_PROPERTIES_BEINGS> properties_beings_names_;
    std::array<sf::Text, NUM_OF_PROPERTIES_BEINGS> properties_beings_;
    std::array<sf::Text, NUM_OF_PROPERTIES_METALS> properties_metals_names_;
    std::array<sf::Text, NUM_OF_PROPERTIES_METALS> properties_metals_;
    std::shared_ptr<sf::RenderWindow> window_;
    sf::Font font_;
    sf::Text name_;
    sf::RectangleShape main_part_;
    sf::RectangleShape image_;
    sf::Sprite sprite_;
    sf::Vector2f image_size_;
    sf::Vector2f position_;
    sf::Vector2f size_;
    Object* object_;
    Button buy_;
 public:
    Item();
    
    void setNums(int num, int num_of_parent);
    void setPositionByParent(sf::Vector2f parent_position);
    void setSizeByParent(sf::Vector2f parent_size);
    void setType(int type);
    void setWindow(std::shared_ptr<sf::RenderWindow>& window);
    
    Button* getButtonBuyPointer();
    std::pair<Object*, int> getObjectAndType();

    sf::Text getName() const;

    void findName(); //TODO: recreate
    void createObject();    // TODO: recreate
    
    void display();
    
    bool operator< (const Item& item);
    ~Item();
};

#endif  // NEW_STRATEGY_1_PROJECT_INCLUDE_ITEM_HPP

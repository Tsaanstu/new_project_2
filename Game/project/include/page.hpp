#ifndef NEW_STRATEGY_1_PROJECT_INCLUDE_PAGE_HPP
#define NEW_STRATEGY_1_PROJECT_INCLUDE_PAGE_HPP

#include "item.hpp"
#include "definitions.hpp"

class Page {
 private:
    // Page
    int num_;
    int num_of_parent_;
    std::shared_ptr<sf::RenderWindow> window_;
    sf::Font font_;
    sf::Text footer_text_;
    sf::Vector2f position_;
    sf::Vector2f size_;
    sf::Vector2f footer_position_;
    sf::Vector2f footer_size_;
    sf::RectangleShape main_part_;
    Button footer_;
    // Items
    int active_item_;
    std::array<Item, NUM_OF_ITEMS> items_;
 public:
    Page();
    
    void setFooterPosition(sf::Vector2f footer_position);
    void setFooterSize();
    void setNums(int num, int num_of_parent);
    void setParametersOfItems(bool init = false);
    void setPositionByParent(sf::Vector2f parent_position);
    void setSizeByParent(sf::Vector2f parent_size);
    void setWindow(std::shared_ptr<sf::RenderWindow>& window);
   
    sf::Vector2f getPosition() const; 
    sf::Vector2f getSize() const; 
    sf::Vector2f getFooterPosition() const; 
    sf::Vector2f getFooterSize() const; 

    std::pair<Button*, int> getFooterPointer();
    std::vector<Button*> getVisibleBuyButtons(std::vector<std::pair<Object*, int> >* objects );
    
    void sortItemsByName();
    
    void display();
    void displayFooter();
};

#endif  // NEW_STRATEGY_1_PROJECT_INCLUDE_PAGE_HPP

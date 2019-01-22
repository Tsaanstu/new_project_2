#ifndef NEW_STRATEGY_1_PROJECT_INCLUDE_TAB_HPP
#define NEW_STRATEGY_1_PROJECT_INCLUDE_TAB_HPP

#include "definitions.hpp"
#include "page.hpp"
#include "button.hpp"

class Tab {
 private:
    // Tab
    int num_;
    std::shared_ptr<sf::RenderWindow> window_;
    sf::RectangleShape main_part_;
    sf::Vector2f position_;
    sf::Vector2f size_;
    Button header_;
    // Pages
    int active_page_;
    std::vector<Page> pages_;
 public:
    Tab();

    void setActivePage(int active_page);
    void setHeaderPosition(sf::Vector2f header_position);
    void setHeaderSize(sf::Vector2f header_size);
    void setName(sf::Text name);
    void setNum(int num);
    void setParametersOfPages();
    void setPositionByParent(sf::Vector2f parent_position);
    void setSizeByParent(sf::Vector2f parent_size);
    void setWindow(std::shared_ptr<sf::RenderWindow>& window);

    std::vector<Button*> getVisibleBuyButtons(std::vector<std::pair<Object*, int> >* objects );
    std::vector<std::pair<Button*, int> > getVisiblePageButtons();
    
    Button* getHeaderPointer();
    sf::Vector2f getHeaderPosition() const;
    sf::Vector2f getHeaderSize() const;

    void display_header();
    void display();
};

#endif  // NEW_STRATEGY_1_PROJECT_INCLUDE_TAB_HPP

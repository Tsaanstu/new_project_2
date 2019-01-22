#include "store.hpp"
#include "button.hpp"

Store::Store(std::shared_ptr<sf::RenderWindow>& window, std::shared_ptr<Player>& player) {
    // font loading
    if (!font_.loadFromFile(STORE_FONT)) {
        std::cerr << "Error while loading font" << std::endl;
    }

    // store parameters 
    window_ = window;
    player_ = player;
    active_tab_ = 0;

    float width = (float) window_->getSize().x;
    float height = (float) window_->getSize().y;

    size_ = sf::Vector2f(width, height);
    position_ = sf::Vector2f(0, 0);
        
    border_.setSize(size_);
    border_.setPosition(position_);
    border_.setOutlineColor(sf::Color::White);
    border_.setOutlineThickness(1.f);
    border_.setFillColor(sf::Color::Black);

    // tabs headers parameters
    for (int i = 0; i < NUM_OF_TABS; i++) {
        tabnames_sf_[i].setString(TABNAMES[i]);
        tabnames_sf_[i].setFont(font_);
        tabnames_sf_[i].setCharacterSize(SIZE_OF_TEXT);
        tabs_[i].setWindow(window_);
        tabs_[i].setNum(i);
        tabs_[i].setName(tabnames_sf_[i]);
        tabs_[i].setHeaderSize(sf::Vector2f(tabnames_sf_[i].getLocalBounds().width, SIZE_OF_TEXT + 10.f));
    }

    sf::Vector2f tab_header_position;
    for (int i = 0; i < NUM_OF_TABS; i++) {
        tab_header_position.x = position_.x + GAP;
        for (int j = 0; j < i; j++) {
            tab_header_position.x = tab_header_position.x + tabs_[j].getHeaderSize().x + GAP;
        }
        tab_header_position.y = position_.y + GAP;
        tabs_[i].setHeaderPosition(tab_header_position);
    }

    // tabs main_parts and pages parameters
    for (int i = 0; i < NUM_OF_TABS; i++) {
        tabs_[i].setSizeByParent(size_);
        tabs_[i].setPositionByParent(position_);
        tabs_[i].setParametersOfPages();
    }

    // back button parameters
    sf::Text back_text;
    back_text.setString(BUTTON_BACK_STRING);
    back_text.setFont(font_);
    back_text.setCharacterSize(SIZE_OF_TEXT);

    back_.setName(back_text);
    back_.setWindow(window_);
    back_.setSize(sf::Vector2f(back_text.getLocalBounds().width, SIZE_OF_TEXT + 10.f));
    back_.setPosition(sf::Vector2f(position_.x + size_.x - back_.getSize().x - GAP, GAP));
}

void Store::display() {
    while (window_->isOpen()) {
        /* managing events */
        sf::Event event;

        // if we try to close window
        while (window_->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window_->close();
            }
        }

        // if we hover or click on the headers of tabs buttons
        for (int i = 0; i < NUM_OF_TABS; i++) {
            tabs_[i].getHeaderPointer()->setActive(false);
        }
        tabs_[active_tab_].getHeaderPointer()->setActive(true);

        for (int i = 0; i < NUM_OF_TABS; i++) {
            if (tabs_[i].getHeaderPointer()->isMouseOn(sf::Mouse::getPosition(*window_))) {
                tabs_[i].getHeaderPointer()->mouseOver();
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    active_tab_ = i;
                }    
            } else {
                tabs_[i].getHeaderPointer()->mouseLeave();                
            }    
        }

        // if we hover or click on back button
        if (back_.isMouseOn(sf::Mouse::getPosition(*window_))) {
            back_.mouseOver();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                player_->update_hp();
                return;
            }
        } else {
            back_.mouseLeave();
        }    

        // if we hover or click on page_nums buttons
        std::vector<std::pair<Button*, int> > page_nums = tabs_[active_tab_].getVisiblePageButtons();
    for (int i = 0; i < page_nums.size(); i++ ) {
            if (page_nums[i].first->isMouseOn(sf::Mouse::getPosition(*window_))) {
                page_nums[i].first->mouseOver();
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    tabs_[active_tab_].setActivePage(page_nums[i].second);
                }
            } else {
                page_nums[i].first->mouseLeave();
            }
        }

        // if we hover of click on buy buttons
        std::vector<std::pair<Object*, int> > objects;
        std::vector<Button*> buy = tabs_[active_tab_].getVisibleBuyButtons(&objects);
        for (int i = 0; i < buy.size(); i++) {
            if (buy[i]->isMouseOn(sf::Mouse::getPosition(*window_))) {
                buy[i]->mouseOver();
                int j = 0;
                while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (j == 0) {
                        if (player_->get_money() >= objects[i].first->get_cost()) {
                            player_->set_money(player_->get_money() - objects[i].first->get_cost());
                            std::cout << "You bought something!" << std::endl;
                            std::cout << objects[i].first->get_name().toAnsiString() << std::endl;
                            switch(objects[i].second) {
                                case TYPE_METAL :
                                    player_->add_metal(*((Metal*)(objects[i].first)));
                                    break;
                                case TYPE_SOLDIER :
                                    player_->add_soldier(*((Soldier*)(objects[i].first)));
                                    break;
                                case TYPE_MISTING :
                                    player_->add_misting(*((Misting*)(objects[i].first)));
                                    break;
                                case TYPE_MISTBORN :
                                    player_->add_mistborn(*((Mistborn*)(objects[i].first)));
                                    break;
                            }
                        } else {
                            std::cout << "You can't buy it, you haven`t enough money!" << std::endl;
                        }                            
                        std::cout << "Your balance is " << player_->get_money() << std::endl;
                    }
                    j++;
                }    
            } else {
                buy[i]->mouseLeave();                
            }    
        }

        /* draw all the stuff */    
        window_->clear();
        
        window_->draw(border_);
        for (int i = 0; i < NUM_OF_TABS; i++) {
            tabs_[i].display_header();
        }
        tabs_[active_tab_].display();    
        back_.display();

        window_->display();
    }

}

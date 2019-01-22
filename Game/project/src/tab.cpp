#include "tab.hpp"

Tab::Tab() {
    active_page_ = 0;
    
    main_part_.setOutlineThickness(1.f);
    main_part_.setFillColor(sf::Color::Black);
    main_part_.setOutlineColor(sf::Color::White);
}

void Tab::setActivePage(int active_page) {
    active_page_ = active_page;
    for (int i = 0; i < pages_.size(); i++) { 
        pages_[i].getFooterPointer().first->setActive(false);    
    }
    pages_[active_page_].getFooterPointer().first->setActive(true);    
}

void Tab::setHeaderPosition(sf::Vector2f header_position) {
    header_.setPosition(header_position);
}

void Tab::setHeaderSize(sf::Vector2f header_size) {
    header_.setSize(header_size);
}

void Tab::setName(sf::Text name) {
    header_.setName(name);
}

void Tab::setNum(int num) {
    num_ = num;
   
    // relatives 
    if (num_ == 0) { // so type == beings
        int additional = (NUM_OF_ITEMS_BEINGS % NUM_OF_ITEMS != 0) ? 1 : 0;
        pages_.resize(NUM_OF_ITEMS_BEINGS / NUM_OF_ITEMS + additional);
    } else { // so type == metals    
        int additional = (NUM_OF_METALS % NUM_OF_ITEMS != 0) ? 1 : 0;
        pages_.resize(NUM_OF_METALS / NUM_OF_ITEMS + additional);
    }
    std::cout << "#" << num_ << ": " << pages_.size() << std::endl;
}

void Tab::setParametersOfPages() {
    for (int i = 0; i < pages_.size(); i++) {
        pages_[i].setNums(i, num_);
        pages_[i].setWindow(window_);
        pages_[i].setSizeByParent(size_);
        pages_[i].setPositionByParent(position_);
        pages_[i].setParametersOfItems(true);
        if (i == 0) {    
            pages_[i].setFooterPosition(pages_[i].getPosition() + sf::Vector2f(0, pages_[i].getSize().y + GAP));
        } else { 
            pages_[i].setFooterPosition(pages_[i - 1].getFooterPosition() + sf::Vector2f(GAP + pages_[i - 1].getFooterSize().x, 0));
        }    
        pages_[i].setFooterSize();
    }
    pages_[active_page_].getFooterPointer().first->setActive(true);    
}

void Tab::setPositionByParent(sf::Vector2f parent_position) {
    position_ = parent_position + sf::Vector2f(GAP, 2 * GAP + getHeaderSize().y);
   
    //relatives
    main_part_.setPosition(position_);
}

void Tab::setSizeByParent(sf::Vector2f parent_size) {
    size_ = sf::Vector2f(parent_size.x - 2 * GAP, parent_size.y - getHeaderSize().y - 3 * GAP);
    
    // relatives
    main_part_.setSize(size_);
}

void Tab::setWindow(std::shared_ptr<sf::RenderWindow>& window) {
    window_ = window;
    
    // relatives
    header_.setWindow(window_);    
}

std::vector<std::pair<Button*, int> > Tab::getVisiblePageButtons() {
    std::vector<std::pair<Button*, int> > buttons;
    for (int i = 0; i < pages_.size(); i++) {
        buttons.push_back(pages_[i].getFooterPointer());
    }
    return buttons;
}

std::vector<Button*> Tab::getVisibleBuyButtons(std::vector<std::pair<Object*, int> >* objects ) {
    return pages_[active_page_].getVisibleBuyButtons(objects);    
}
    
Button* Tab::getHeaderPointer() { 
    return &header_;
}

sf::Vector2f Tab::getHeaderPosition() const {
    return header_.getPosition();
}

sf::Vector2f Tab::getHeaderSize() const {
    return header_.getSize();
}

void Tab::display_header() {
    header_.display();
}

void Tab::display() {
    window_->draw(main_part_);

    pages_[active_page_].display();

    for (int i = 0; i < pages_.size(); i++) { 
        pages_[i].displayFooter();
    }
}

#include "page.hpp"

Page::Page() {
    active_item_ = NO_ACTIVE_ITEMS;
    main_part_.setOutlineColor(sf::Color::White);
    main_part_.setOutlineThickness(1.f);
    main_part_.setFillColor(sf::Color::Black);
    
    // footer button parameters
    if (!font_.loadFromFile(STORE_FONT)) {
        std::cerr << "Error while loading font" << std::endl;
    }
   
    footer_text_.setFont(font_); 
    footer_text_.setCharacterSize(SIZE_OF_TEXT);
}

void Page::setFooterPosition(sf::Vector2f footer_position) {
    footer_position_ = footer_position;
    footer_.setPosition(footer_position_);
}

void Page::setFooterSize() {
    footer_size_ = sf::Vector2f(footer_text_.getLocalBounds().width, SIZE_OF_TEXT + 10.f);
    footer_.setSize(footer_size_);
}

void Page::setNums(int num, int num_of_parent) {
    num_ = num;
    num_of_parent_ = num_of_parent;

    // relatives
    footer_text_.setString(" " + std::to_string(num_ + 1) + " ");
    footer_.setName(footer_text_);
}

void Page::setParametersOfItems(bool init) {
    for (int i = 0; i < NUM_OF_ITEMS; i++) {
        items_[i].setNums(i, num_);
        items_[i].setType(num_of_parent_);
        items_[i].setWindow(window_);
        items_[i].setSizeByParent(size_);
        items_[i].setPositionByParent(position_);
        if (init) {
            items_[i].findName();
            items_[i].createObject();
        }
    }
}

void Page::setPositionByParent(sf::Vector2f parent_position) {
    position_ = parent_position + sf::Vector2f(GAP, GAP);

    // relatives
    main_part_.setPosition(position_);
}

void Page::setSizeByParent(sf::Vector2f parent_size) {
    size_ = sf::Vector2f(parent_size.x - 2 * GAP, parent_size.y - 3 * GAP - SIZE_OF_TEXT - 10.f);

    // relatives
    main_part_.setSize(size_);
}

void Page::setWindow(std::shared_ptr<sf::RenderWindow>& window) {
    window_ = window;

    // relatives
    footer_.setWindow(window_);
}

sf::Vector2f Page::getPosition() const {
    return position_;
}

sf::Vector2f Page::getSize() const { 
    return size_;
}

sf::Vector2f Page::getFooterPosition() const {
    return footer_position_;
}

sf::Vector2f Page::getFooterSize() const { 
    return footer_size_;
}

std::pair<Button*, int> Page::getFooterPointer() {
    return std::make_pair(&footer_, num_);
}

std::vector<Button*> Page::getVisibleBuyButtons(std::vector<std::pair<Object*, int> >* objects ) {
    std::vector<Button*> buttons;
    Button* current_button = NULL;
    std::pair<Object*, int> current_object;

    for (int i = 0; i < NUM_OF_ITEMS; i++) {
        current_button = items_[i].getButtonBuyPointer();
          current_object = items_[i].getObjectAndType();
        if (current_button != NULL) {
            buttons.push_back(current_button);
            objects->push_back(current_object);
        }
    }

    return buttons;
}

void Page::sortItemsByName() {
//    std::sort(items_.begin(), items_.end());
}

void Page::display() {
    window_->draw(main_part_);

    for (int i = 0; i < NUM_OF_ITEMS; i++) {
        items_[i].display();
    }
}

void Page::displayFooter() {
    footer_.display();
}

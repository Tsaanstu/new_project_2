#include "item.hpp"

Item::Item() {
    object_ = NULL;

    if (!font_.loadFromFile(STORE_FONT)) {
        std::cerr << "Error while loading font" << std::endl;
    }
    
    name_.setFont(font_);
    name_.setCharacterSize(SIZE_OF_TEXT);
    name_.setColor(sf::Color::Red);

    for (int i = 0; i < NUM_OF_PROPERTIES_BEINGS; i++) {
        properties_beings_names_[i].setFont(font_);
        properties_beings_names_[i].setCharacterSize(SIZE_OF_TEXT);
        properties_beings_names_[i].setColor(sf::Color::White);
        properties_beings_names_[i].setString(ALL_PROPERTIES_BEINGS[i]);
        properties_beings_[i].setFont(font_);
        properties_beings_[i].setCharacterSize(SIZE_OF_TEXT);
        properties_beings_[i].setColor(sf::Color::White);
    }    

    for (int i = 0; i < NUM_OF_PROPERTIES_METALS; i++) {
        properties_metals_names_[i].setFont(font_);
        properties_metals_names_[i].setCharacterSize(SIZE_OF_TEXT);
        properties_metals_names_[i].setColor(sf::Color::White);
        properties_metals_names_[i].setString(ALL_PROPERTIES_METALS[i]);
        properties_metals_[i].setFont(font_);
        properties_metals_[i].setCharacterSize(SIZE_OF_TEXT);
        properties_metals_[i].setColor(sf::Color::White);
    }    

    main_part_.setOutlineThickness(1.f);
    main_part_.setFillColor(sf::Color::Black);
    main_part_.setOutlineColor(sf::Color::White);

    image_.setOutlineThickness(1.f);
    image_.setFillColor(sf::Color::Black);
    image_.setOutlineColor(sf::Color::White);
    
    sf::Text buy_text;
    buy_text.setString(BUTTON_BUY_STRING);
    buy_text.setFont(font_);
    buy_text.setCharacterSize(SIZE_OF_TEXT);

    buy_.setName(buy_text);
    buy_.setSize(sf::Vector2f(buy_text.getLocalBounds().width, SIZE_OF_TEXT + 10.f));
}

void Item::setNums(int num, int num_of_parent) {
    num_ = num;
    num_of_parent_ = num_of_parent;
}

void Item::setPositionByParent(sf::Vector2f parent_position) {
    float displacement = GAP + num_ * (size_.y + GAP);
    position_ = parent_position + sf::Vector2f(GAP, displacement);
    
    // relatives
    main_part_.setPosition(position_);
    image_.setPosition(position_.x + GAP, position_.y + GAP);

    sf::Vector2f current_text_position(position_.x + image_size_.x + 2 * GAP, position_.y + GAP);
    name_.setPosition(current_text_position);
    
    if (type_ == TYPE_BEING) {    
        for (int i = 0; i < NUM_OF_PROPERTIES_BEINGS; i++) {
            if (i % 2 == 0) {
                current_text_position += sf::Vector2f(0, GAP + SIZE_OF_TEXT);
                properties_beings_names_[i].setPosition(current_text_position);
                properties_beings_[i].setPosition(current_text_position + sf::Vector2f(200, 0)); // !!!
            } else {
                properties_beings_names_[i].setPosition(current_text_position + sf::Vector2f(LONG_GAP, 0));
                properties_beings_[i].setPosition(current_text_position + sf::Vector2f(LONG_GAP + 200, 0));
            }
        }
    } else if (type_ == TYPE_METAL) {
        for (int i = 0; i < NUM_OF_PROPERTIES_METALS; i++) {
            if (i % 2 == 0) {
                current_text_position += sf::Vector2f(0, GAP + SIZE_OF_TEXT);
                properties_metals_names_[i].setPosition(current_text_position);
                properties_metals_[i].setPosition(current_text_position + sf::Vector2f(200, 0)); // !!!
            } else {
                properties_metals_names_[i].setPosition(current_text_position + sf::Vector2f(LONG_GAP, 0));
                properties_metals_[i].setPosition(current_text_position + sf::Vector2f(LONG_GAP + 200, 0));
            }
        }
    }

    buy_.setPosition(sf::Vector2f(position_.x + size_.x - buy_.getSize().x - GAP, position_.y + GAP));
}

void Item::setSizeByParent(sf::Vector2f parent_size) {
    size_ = sf::Vector2f(parent_size.x - 2 * GAP, (parent_size.y - (NUM_OF_ITEMS + 1) * GAP) / 3);

    // relatives
    main_part_.setSize(size_);
    image_size_ = sf::Vector2f(size_.y - 2 * GAP, size_.y - 2 * GAP);
    image_.setSize(image_size_);
}

void Item::setType(int type) {
    if (type > NUM_OF_TYPES - 1 || type < 0) {
        type = 0;
    }
    type_ = type;
}

void Item::setWindow(std::shared_ptr<sf::RenderWindow>& window) {
    window_ = window;
    
    // relatives
    buy_.setWindow(window_);
}

Button* Item::getButtonBuyPointer() {
    if (object_ != NULL) {
        return &buy_;
    } else {
        return NULL;
    }
}

std::pair<Object*, int> Item::getObjectAndType() {
    return std::make_pair(object_, deep_type_);
}

sf::Text Item::getName() const {
    return name_;
}

void Item::findName() {
    int real_num = num_ + num_of_parent_ * NUM_OF_ITEMS;
    if (type_ == TYPE_METAL) {
        if (real_num < NUM_OF_METALS) {
            name_.setString(ALL_METALS[num_]);
            deep_type_ = TYPE_METAL;
        } else {
            name_.setString("");  // and what to do with that?
        }
    } else if ( type_ == TYPE_BEING) {
        if (real_num < NUM_OF_SOLDIERS) {
            name_.setString(ALL_SOLDIERS[real_num]);
            deep_type_ = TYPE_SOLDIER;
        } else if (real_num < NUM_OF_SOLDIERS + NUM_OF_MISTINGS) {
            name_.setString(ALL_MISTINGS[real_num - NUM_OF_SOLDIERS]);
            deep_type_ = TYPE_MISTING;
        } else if (real_num < NUM_OF_SOLDIERS + NUM_OF_MISTINGS + NUM_OF_MISTBORNS) {
            name_.setString(ALL_MISTBORNS[real_num - NUM_OF_SOLDIERS - NUM_OF_MISTINGS]);
            deep_type_ = TYPE_MISTBORN;
        } else {
            name_.setString("");  // and what to do with that?
        }
    }
}

void Item::createObject() {
    Soldier* soldier_p;
    Misting* misting_p;
    Mistborn* mistborn_p;
    Metal* metal_p;

    sf::String name = name_.getString();
    switch (deep_type_) {
        case TYPE_SOLDIER :
            object_ = new Soldier(name, name);
            break;
        case TYPE_MISTING :
            object_ = new Misting(name, name);
            break;
        case TYPE_MISTBORN :
            object_ = new Mistborn(name, name);
            break;
        case TYPE_METAL :  // TODO(gleensande): remove L
            object_ = new Metal(name, name);
            break;
    }

    if (name_.getString() != "") {
        //object_->set_name(name_.getString());
        object_->read_data_from_file(name_.getString());
        
        int hp = 0, time = 0, force = 0, distant_force = 0, accuracy = 0, distance = 0, cost = 0;    
        cost = object_->get_cost();
        if (type_ == TYPE_BEING) {
            switch (deep_type_) {
                case TYPE_SOLDIER :
                    soldier_p = (Soldier*) object_;
                    hp = soldier_p->get_hp();
                    force = soldier_p->get_force();
                    distant_force = soldier_p->get_distant_force();
                    accuracy = soldier_p->get_accuracy_of_shooting();
                    distance = soldier_p->get_distance_of_walk();
                    break;
                case TYPE_MISTING :
                    misting_p = (Misting*) object_;
                    hp = misting_p->get_hp();
                    force = misting_p->get_force();
                    distant_force = misting_p->get_distant_force();
                    accuracy = misting_p->get_accuracy_of_shooting();
                    distance = misting_p->get_distance_of_walk();
                    break;
                case TYPE_MISTBORN :
                    mistborn_p = (Mistborn*) object_;
                    hp = mistborn_p->get_hp();
                    force = mistborn_p->get_force();
                    distant_force = mistborn_p->get_distant_force();
                    accuracy = mistborn_p->get_accuracy_of_shooting();
                    distance = mistborn_p->get_distance_of_walk();
                    break;
            }    

            properties_beings_[0].setString(std::to_string(hp));
            properties_beings_[1].setString(std::to_string(force));
            properties_beings_[2].setString(std::to_string(distant_force));
            properties_beings_[3].setString(std::to_string(accuracy));
            properties_beings_[4].setString(std::to_string(distance));
            properties_beings_[5].setString(std::to_string(cost));
        } else if (type_ == TYPE_METAL) {
            metal_p = (Metal*) object_;
            time = metal_p->get_action_time();
            Allomantic_power power = metal_p->get_allomantic_power();
            force = power.get_force();
            distant_force = power.get_distant_force();
            accuracy = power.get_accuracy_of_shooting();
            distance = power.get_distance_of_walk();

            properties_metals_[0].setString(std::to_string(time));
            properties_metals_[1].setString(std::to_string(force));
            properties_metals_[2].setString(std::to_string(distant_force));
            properties_metals_[3].setString(std::to_string(accuracy));
            properties_metals_[4].setString(std::to_string(distance));
            properties_metals_[5].setString(std::to_string(cost));
        
        }
    
        // relatives
        sprite_ = object_->get_sprite();
        sprite_.setScale(image_size_.x/(object_->get_image().getSize().x), image_size_.y/(object_->get_image().getSize().y));
        sprite_.setPosition(position_ + sf::Vector2f(GAP, GAP));
    }
}

void Item::display() {
    if (name_.getString() != "") {
        window_->draw(main_part_);
        window_->draw(image_);
        window_->draw(name_);
        window_->draw(sprite_);    
        if (type_ == TYPE_BEING) {
            for (int i = 0; i < NUM_OF_PROPERTIES_BEINGS; i++) {
                window_->draw(properties_beings_names_[i]);
                window_->draw(properties_beings_[i]);
            }
        } else if (type_ == TYPE_METAL) {
            for (int i = 0; i < NUM_OF_PROPERTIES_METALS; i++) {
                window_->draw(properties_metals_names_[i]);
                window_->draw(properties_metals_[i]);
            }
        }
        buy_.display();
    }
}

bool Item::operator< (const Item& item) {
    if (name_.getString() < item.getName().getString() && name_.getString() != "") {
        return true;
    } else {
        return false;
    }
}

Item::~Item () {
    if (object_ != NULL) {
       delete object_;
    }
}


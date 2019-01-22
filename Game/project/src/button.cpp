#include "button.hpp"

void Button::invertColors() {
    if (mouse_on_) {
        sf::Color swp = fill_color_;
        fill_color_ = text_color_;
        text_color_ = swp;
    } else {
        if (active_) {
            fill_color_ = sf::Color::White;
            text_color_ = sf::Color::Red;
        } else {
            fill_color_ = sf::Color::Black;
            text_color_ = sf::Color::White;
        }
    }
        
    return;
}

Button::Button() {
    outline_color_ = sf::Color::White;
    fill_color_ = sf::Color::Black;
    text_color_ = sf::Color::White;
    thickness_ = 1.f;
    mouse_on_ = false; 
    form_.setOutlineThickness(thickness_);
    active_ = false;
}

void Button::setActive(bool active) {
    active_ = active;
    if (active_) {
        fill_color_ = sf::Color::White;
        text_color_ = sf::Color::Red;
    } else {
        fill_color_ = sf::Color::Black;
        text_color_ = sf::Color::White;
    }
}

void Button::setName(sf::Text name) {
    name_ = name;
}

void Button::setPosition(sf::Vector2f position) {
    position_ = position;
    form_.setPosition(position_);
    name_.setPosition(position_);
}

void Button::setSize(sf::Vector2f size) {
    size_ = size;
    form_.setSize(size_);
}

void Button::setWindow(std::shared_ptr<sf::RenderWindow>& window) {
    window_ = window;
}

sf::Vector2f Button::getSize() const {
    return size_;
}

sf::Vector2f Button::getPosition() const { 
    return position_;
}

bool Button::isMouseOn(sf::Vector2i mouse) {
    if ((mouse.x >= position_.x && mouse.x <= (position_.x + size_.x)) &&
        (mouse.y >= position_.y && mouse.y <= (position_.y + size_.y))) {
        mouse_on_ = true;
    } else {
        mouse_on_ = false;
    }
    return mouse_on_;
}

void Button::mouseOver() {
    invertColors();
}

void Button::mouseLeave() {
    invertColors();
}

void Button::display() {
    // in case that color changes by hovering
    form_.setOutlineColor(outline_color_);
    form_.setFillColor(fill_color_);
    name_.setColor(text_color_);
   
    window_->draw(form_);
    window_->draw(name_);

}

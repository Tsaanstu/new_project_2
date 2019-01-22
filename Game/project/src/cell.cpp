#include "cell.hpp"

void Cell::delete_being() {
    if (being_) {
        being_ = nullptr;
    }
}

void Cell::update_being_hp(short int _hp) {
    being_->set_hp(_hp);
}

void Cell::set_type(bool _type) {
    type_ = _type;
}

void Cell::set_y_coord(double _y) {
    y_ = _y;
    sprite_.setPosition(x_, y_);
    set_being_coord(x_, y_);
}

void Cell::set_x_coord(double _x) {
    x_ = _x;
    sprite_.setPosition(x_, y_);
    set_being_coord(x_, y_);
}

void Cell::set_coord(double _x, double _y) {
    x_ = _x;
    y_ = _y;
    sprite_.setPosition(x_, y_);
    set_being_coord(x_, y_);
}

void Cell::set_being_coord(double _x, double _y) {
    being_->set_coordinates(std::pair<float, float> (_x, _y));
}

void Cell::set_size(double _width, double _height) {
    width_ = _width;
    height_ = _height;
}

void Cell::set_Being(std::shared_ptr<Being> being) {
    being_ = being;
}

void Cell::set_belonding(unsigned short int bl) {
    belonging_ = bl;
}

bool Cell::if_free() {
    if (being_) {
        return false;
    }
    return true;
}

Cell::Cell(double _x, double _y, double _width, double _height, bool _type, sf::String _file_name) {
    x_ = _x;
    y_ = _y;
    width_ = _width;
    height_ = _height;
    type_ = _type;
    belonging_ = 0;
    file_name_ = _file_name;
    texture_.loadFromFile(PATH_TO_PICTURES + file_name_ + PICTURES_FORMAT);
    sprite_.setTexture(texture_);
    sprite_.setTextureRect(sf::IntRect(0, 0, width_, height_));
    sprite_.setPosition(x_, y_);
    being_ = nullptr;
}

Cell::Cell(const Cell &object) {
    x_ = object.x_;
    y_ = object.y_;
    width_ = object.width_;
    height_ = object.height_;
    type_ = object.type_;
    belonging_ = object.belonging_;
    file_name_ = object.file_name_;
    being_ = object.being_;
    texture_.loadFromFile(PATH_TO_PICTURES + file_name_ + PICTURES_FORMAT);
    sprite_.setTexture(texture_);
    sprite_.setTextureRect(sf::IntRect(0, 0, width_, height_));
    sprite_.setPosition(x_, y_);
}

bool Cell::if_active(sf::Vector2i cursor_position) {
    if (cursor_position.x > x_ && cursor_position.x < x_ + width_ &&
        cursor_position.y > y_ && cursor_position.y < y_ + height_) {
        return true;
    }
    return false;
}

double Cell::get_x() const {
    return x_;
}

double Cell::get_y() const {
    return y_;
}

double Cell::get_width() const {
    return width_;
}

double Cell::get_height() const {
    return height_;
}

bool Cell::get_type() const {
    return type_;
}

sf::Sprite Cell::get_sprite() {
    if (type_) {
        // TODO: если стоит юнит, затемнить клетку
        if (belonging_ != 0) {
            sprite_.setTextureRect(sf::IntRect(width_ * 0, 0, width_, height_));
        } else {
            sprite_.setTextureRect(sf::IntRect(0, 0, width_, height_));
        }
    } else {
        if (((int)get_x() % 2 != 0) && ((int)get_y() % 2 == 0)) {
            sprite_.setTextureRect(sf::IntRect(width_ * 1, 0, width_, height_));
        } else {
            sprite_.setTextureRect(sf::IntRect(width_ * 2, 0, width_, height_));
        }
    }
    return sprite_;
}

std::shared_ptr<Being> Cell::get_Being() const {
    return being_;
}

unsigned short int Cell::get_belonding() const {
    return belonging_;
}

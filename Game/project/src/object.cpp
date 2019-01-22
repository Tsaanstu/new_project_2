#include "object.hpp"

Object::Object(int c, sf::String file_name, sf::String name) {
    this->cost_ = c;
    this->image_file_name_ = file_name;
    this->name_ = name;
    image_.loadFromFile(PATH_TO_PICTURES + image_file_name_ + PICTURES_FORMAT);
    texture_.loadFromImage(image_);
    sprite_.setTexture(texture_);
}

Object::Object(const Object &o) {
    this->cost_ = o.get_cost();
    this->image_file_name_ = o.get_file_name();
    this->name_ = o.get_name();
    image_.loadFromFile(PATH_TO_PICTURES + o.get_file_name() + PICTURES_FORMAT);
    texture_.loadFromImage(image_);
    sprite_.setTexture(texture_);
    sprite_.setTextureRect(o.get_sprite().getTextureRect());
    sprite_.setPosition(o.get_sprite().getPosition().x, o.get_sprite().getPosition().y);
}

void Object::set_base_texture_rect(sf::IntRect rect) {
    sprite_.setTextureRect(rect);
}

//  get
int Object::get_cost() const {
    return cost_;
}

sf::String Object::get_file_name() const {
    return image_file_name_;
}

sf::String Object::get_name() const {
    return name_;

}
sf::Image Object::get_image() const {
    return image_;
}

sf::Texture Object::get_texture() const {
    return texture_;
}

sf::Sprite Object::get_sprite() const {
    return sprite_;
}

//  set
void Object::set_cost(int cost) {
    this->cost_ = cost;
}

void Object::set_file_name(sf::String file_name) {
    this->image_file_name_ = file_name;
}

void Object::set_name(sf::String name) {
    this->name_ = name;
}

void Object::set_image(sf::Image image) {
    this->image_ = image;
    texture_.loadFromImage(image);
    sprite_.setTexture(texture_);
}

void Object::set_base_position(std::pair<float, float> coordinate) {
    sprite_.setPosition(coordinate.first, coordinate.second);
}

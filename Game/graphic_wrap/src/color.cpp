#include "color.hpp"

Color::Color (uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
    color = sf::Color(red, green, blue, alpha);
}

Color::Color (uint32_t _color) {
    color = sf::Color(_color);
}

uint32_t Color::toInteger () const {
    return color.toInteger();
}

sf::Color Color::get_Color() const {
    return color;
}

void Color::set_Color(sf::Color _color) {
    color = _color;
}
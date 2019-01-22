#ifndef NEW_STRATEGY_1_COLOR_HPP
#define NEW_STRATEGY_1_COLOR_HPP

#include <SFML/Graphics.hpp>
#include <stdint.h>

class Color {
 public:
    Color() = default;
    Color (uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);
    Color (uint32_t color);
    ~Color() = default;
    uint32_t toInteger () const;
    //  get
    sf::Color get_Color() const;
    //  set
    void set_Color(sf::Color _color);
 private:
    sf::Color color;
};

#endif //NEW_STRATEGY_1_COLOR_HPP
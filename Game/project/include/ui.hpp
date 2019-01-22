//
// Created by Kirill Smetankin on 01/12/2018.
//

#ifndef NEW_STRATEGY_1_UI_HPP
#define NEW_STRATEGY_1_UI_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "definitions.hpp"
#include "player.hpp"
#include <being.hpp>

const float LOG_BOX_WIDTH = 0.6;  // проценты
const float LOG_BOX_HEIGHT = 50;  // реальный размер, тк высота шрифта

const float BOX_WIDTH = 0.19;
const float BOX_HEIGHT = 0.3;
const float BOX_PADDING = 0.005;

class Log {
 public:
    Log(unsigned int character_size, sf::Color color, int x, int y, sf::RenderWindow *window);
    ~Log() = default;

    std::pair<sf::Text, sf::RectangleShape> get_drawable();
    void set_text(std::string &log_to_show);
 private:
    std::string log_;
    sf::Text sfml_log_;
    sf::RectangleShape log_box_;
    sf::Font Font_;
};

class Player_units {
 public:
    Player_units(float x, float y, Player *p, sf::RenderWindow *window);
    void draw(sf::RenderWindow *window);

 private:
    Player *player;
    sf::Text player_name;
    sf::Font font_;
    sf::RectangleShape box;
    std::vector<std::any> units;
    sf::Text buffer;
    sf::Text positon;
    sf::Text hp;
    float pos_x;
    float pos_y;
};

#endif //NEW_STRATEGY_1_UI_HPP

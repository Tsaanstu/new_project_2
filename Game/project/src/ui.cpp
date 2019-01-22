//
// Created by Kirill Smetankin on 01/12/2018.
//

#include <ui.hpp>

#include "ui.hpp"

Log::Log(const unsigned int character_size, const sf::Color color, const int x, const int y, sf::RenderWindow *window) {
    Font_.loadFromFile(PLAYER_FONT);

    sfml_log_.setFont(Font_);
    sfml_log_.setCharacterSize(character_size);
    sfml_log_.setFillColor(color);
    sfml_log_.setPosition(x + 5, y);

    log_box_.setSize(sf::Vector2f(LOG_BOX_WIDTH * window->getSize().x, LOG_BOX_HEIGHT));
    log_box_.setOutlineColor(sf::Color(65, 91, 118));
    log_box_.setOutlineThickness(2);
//    log_box_.setFillColor(sf::Color::Transparent);
    log_box_.setFillColor(sf::Color(30, 45, 72));

    log_box_.setPosition(sfml_log_.getPosition().x - 5, sfml_log_.getPosition().y - 10);

}

void Log::set_text(std::string &log_to_show) {
    log_ = log_to_show;
    sfml_log_.setString(sf::String::fromUtf8(log_.begin(), log_.end()));
}

std::pair<sf::Text, sf::RectangleShape> Log::get_drawable() {
    return std::pair<sf::Text, sf::RectangleShape>(sfml_log_, log_box_);
}

//////////////////////////

Player_units::Player_units(float x, float y, Player *p, sf::RenderWindow *window) : pos_x(x), pos_y(y) {
    font_.loadFromFile(PLAYER_FONT);
    player = p;
    player_name = player->get_player_name();
    player_name.setPosition(x + 5, y + 5);
    player_name.setFillColor(sf::Color(238, 244, 242));
    player_name.setFont(font_);
    player_name.setCharacterSize(30);

    buffer.setFont(font_);
    buffer.setCharacterSize(20);
    buffer.setFillColor(sf::Color(205, 214, 213));

    positon.setFont(font_);
    positon.setCharacterSize(20);
    positon.setFillColor(sf::Color::White);

    hp.setFont(font_);
    hp.setCharacterSize(20);
    hp.setFillColor(sf::Color(144, 145, 156));

    box.setSize(sf::Vector2f(BOX_WIDTH * window->getSize().x, BOX_HEIGHT * window->getSize().y));
    box.setOutlineColor(sf::Color(65, 91, 118));
    box.setOutlineThickness(2);
    box.setPosition(x, y);
    box.setFillColor(sf::Color(30, 45, 72));

}
void Player_units::draw(sf::RenderWindow *window) {
    units.clear();
    for (auto &i : player->get_soldiers()) {
        units.emplace_back(i);
    }
    for (auto &i : player->get_mistborns()) {
        units.emplace_back(i);
    }
    for (auto &i : player->get_mistings()) {
        units.emplace_back(i);
    }

    box.setSize(sf::Vector2f(BOX_WIDTH * window->getSize().x, units.size() * 30 + 90));
    window->draw(box);
    window->draw(player_name);

    int tmp_x = box.getPosition().x + 10;
    int tmp_y = box.getPosition().y + 40;

    for (auto &i : units) {
        tmp_y += 30;

        if (i.type().name() == std::string("7Soldier")) {
            buffer.setString(std::any_cast<Soldier>(i).get_name());

            buffer.setPosition(tmp_x, tmp_y);
            window->draw(buffer);

            hp.setPosition(tmp_x + 180, tmp_y);
            hp.setString("hp: " + std::to_string(static_cast<int>(std::any_cast<Soldier>(i).get_hp())));
            window->draw(hp);

//            positon.setPosition(tmp_x + 180, tmp_y);
//            positon.setString("x: " + std::to_string(static_cast<int>(std::any_cast<Soldier>(i).get_coordinates().first)));
//            window->draw(positon);
//
//            positon.setPosition(tmp_x + 220, tmp_y);
//            positon.setString("y: " + std::to_string(static_cast<int>(std::any_cast<Soldier>(i).get_coordinates().second)));
//            window->draw(positon);

        } else if (i.type().name() == std::string("7Misting")) {
            buffer.setString(std::any_cast<Misting>(i).get_name());

            buffer.setPosition(tmp_x, tmp_y);
            window->draw(buffer);

            hp.setPosition(tmp_x + 180, tmp_y);
            hp.setString("hp: " + std::to_string(static_cast<int>(std::any_cast<Misting>(i).get_hp())));
            window->draw(hp);

//            positon.setPosition(tmp_x + 180, tmp_y);
//            positon.setString("x: " + std::to_string(static_cast<int>(std::any_cast<Misting>(i).get_coordinates().first)));
//            window->draw(positon);
//
//            positon.setPosition(tmp_x + 220, tmp_y);
//            positon.setString("y: " + std::to_string(static_cast<int>(std::any_cast<Misting>(i).get_coordinates().second)));
//            window->draw(positon);

        } else if (i.type().name() == std::string("8Mistborn")) {
            buffer.setString(std::any_cast<Mistborn>(i).get_name());

            buffer.setPosition(tmp_x, tmp_y);
            window->draw(buffer);

            hp.setPosition(tmp_x + 180, tmp_y);
            hp.setString("hp: " + std::to_string(static_cast<int>(std::any_cast<Mistborn>(i).get_hp())));
            window->draw(hp);

//            positon.setPosition(tmp_x + 180, tmp_y);
//            positon.setString("x: " + std::to_string(static_cast<int>(std::any_cast<Mistborn>(i).get_coordinates().first)));
//            window->draw(positon);
//
//            positon.setPosition(tmp_x + 220, tmp_y);
//            positon.setString("y: " + std::to_string(static_cast<int>(std::any_cast<Mistborn>(i).get_coordinates().second)));
//            window->draw(positon);
        }
    }
}

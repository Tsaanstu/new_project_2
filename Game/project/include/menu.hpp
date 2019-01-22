#ifndef PROJECT_INCLUDE_MENU_HPP
#define PROJECT_INCLUDE_MENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <fstream>
#include <map>
#include <any>
#include "definitions.hpp"
#include <game.hpp>

#define CODE_UP 2
#define CODE_DOWN 1
#define CODE_NOTHING 0

#define CODE_PLAY 1
#define CODE_STORE 2


class Menu {
 public:
    Menu();
    ~Menu() = default;
    void show();
    int select_level(sf::String level);  // выбрать подуровень

 private:
    sf::Font Font_;
    sf::Text Title_;
    sf::RenderWindow Window_;
    std::map<std::string, std::vector<std::pair<sf::Text, sf::IntRect>>> all_menu;
    std::vector<std::pair<std::string, sf::String>> levels;  // уровни меню

    std::vector<std::pair<sf::Text, sf::IntRect>> vector_show;  // тмп, что отображать

    std::vector<sf::RectangleShape> vector_lines;  // вектор с линиями
    sf::ConvexShape convex;  // конвекс под текстурку героя
    std::string user_level;
    std::string prev_user_level;

    int current_frame;  // номер текущего фрейма дракона

    sf::Image phoenix_img;
    sf::Texture phoenix_texture;
    sf::Sprite phoenix_sprite;

    sf::Music music_;

    bool animate;
    bool backstack;

    int event_handler();
    void call_game_module(int module_num);
    int config_reader(std::string file_path);
    void set_text_to_normal_size();  // возвращает размер текста то стандарта
    void set_text_bigger();  // увеличивает размер при наведении

    std::vector<sf::Text> get_text_module(std::string &level);  // геттер для тестов
    std::vector<std::pair<sf::Text, sf::IntRect>> get_all_vals(std::string &level);
    sf::Text get_title();
    std::string get_user_level();
    std::string get_prev_user_level();
    void animate_phoenix();

    Game game;
};

#endif // PROJECT_INCLUDE_MENU_HPP

#include <cstring>
#include <menu.hpp>
#include <game.hpp>
#include <store.hpp>
#include <ui.hpp>

#include "menu.hpp"

#define CLOSE_WINDOW 1

Menu::Menu() : game() {
    if (!Font_.loadFromFile(MENU_FONT)) {
        std::cerr << "\033[0;31m" << "--ФОНТЫ НЕ ЗАГРУЗИЛИСЬ" << "\033[0m\n";;
    }

    music_.openFromFile(PATH_TO_GAME_DATA + "sounds/bg_music.wav");  // TODO: (nmerk) add path to definitions
    music_.setVolume(50.f);

    // окно + переменные для работы с уровнями
    Window_.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "new_game");
    user_level = "main";
    prev_user_level = "main";

    std::cout << "x: " << Window_.getSize().x << " y: " << Window_.getSize().y << std::endl;

    // чтение конфига
    if (config_reader(CONFIG_PATH) != 0) {
        return;
    }

    // титульник
    Title_.setString(PROJECT_NAME);
    Title_.setFont(Font_);
    Title_.setFillColor(sf::Color::White);
    Title_.setPosition(TITLE_POSITION_X, TITLE_POSITION_Y);
    Title_.setCharacterSize(TITLE_SIZE);

    // базовая разметка меню
    sf::RectangleShape tmp(sf::Vector2f(Window_.getSize().x, 3.f));  // top line
    tmp.setPosition(0, 120);
    vector_lines.push_back(tmp);

    tmp.setSize(sf::Vector2f(Window_.getSize().x, 3.f));  // bot line
    tmp.setPosition(0, Window_.getSize().y - 120);
    vector_lines.push_back(tmp);

    tmp.setSize(sf::Vector2f((Window_.getSize().y - 240) / std::cos(15 * M_PI / 180), 3.f));  // right line
    tmp.rotate(75.f);
    tmp.setPosition(Window_.getSize().x * 0.6, 120);
    vector_lines.push_back(tmp);

    convex.setPointCount(4);  // right convex
    convex.setPoint(0, sf::Vector2f(Window_.getSize().x, 126.f));
    convex.setPoint(1, sf::Vector2f(Window_.getSize().x * 0.6 + 5, 126.f));
    float tmp_s = Window_.getSize().x * 0.6 + 5
        + (Window_.getSize().y - 250) / std::cos(15 * M_PI / 180) * std::sin(15 * M_PI / 180);
    convex.setPoint(2, sf::Vector2f(tmp_s, Window_.getSize().y - 123));
    convex.setPoint(3, sf::Vector2f(Window_.getSize().x, Window_.getSize().y - 123));
    convex.setFillColor(sf::Color::Cyan);

    // анимация феникса + переменные для нее
    phoenix_img.loadFromFile(PATH_PHOENIX);
    phoenix_texture.loadFromImage(phoenix_img);
    phoenix_sprite.setTexture(phoenix_texture);
    phoenix_sprite.setTextureRect(sf::IntRect(0, 0, 250, 250));
    phoenix_sprite.scale(2.5f, 2.5f);
    phoenix_sprite.setPosition(Window_.getSize().x * 0.6, Window_.getSize().y * 0.1);
    animate = false;
    backstack = false;

    current_frame = 0;

    game.set_window(&Window_);
}

int Menu::config_reader(std::string file_path) {
    std::ifstream fout(file_path, std::ios::in);
    if (!fout) {
        std::cerr << "Cannot open config file: \033[0;31m" << std::strerror(errno) << "\033[0m\n";
        return OPEN_FILE_ERROR;
    }

    std::string buf;  // пукт подменю
    std::string buf_name;  // название подменю
    int buf_x, buf_y;  // расположение пунктов меню
    std::pair<sf::Text, sf::IntRect> buf_pair;  // пара текст и его обертка
    sf::Text buf_text;  // текст пункта меню

    buf_text.setFont(Font_);
    buf_text.setCharacterSize(FONT_SIZE_MENU_BUTTON_sm);
    buf_text.setFillColor(sf::Color::White);

    while (!fout.eof()) {
        fout >> buf;
        if (buf.back() == ':') {
            buf_name = buf;
            buf_name.pop_back();

            all_menu.emplace(buf_name, std::vector<std::pair<sf::Text, sf::IntRect>>());  // добавление подуровня в мапу

            levels.emplace_back(  // добавление соответствия в "словарь"
                buf_name,
                sf::String::fromUtf8(buf_name.begin(), buf_name.end())
            );
        } else {
            fout >> buf_x >> buf_y;

            std::cout << buf_y << std::endl;
            std::cout << static_cast<float>(buf_y / 1920.0 * Window_.getSize().y) << std::endl;

            // блок о нас
            if (buf == "about") {
                buf_text.setString(L"ЧУВАК, \nЭТА ВЕЧЕРИНКА ОТСТОЙ.\nЯ НЕНАВИЖУ ЭТИХ ЛЮДЕЙ.");
                buf_text.setPosition(static_cast<float>(buf_x * (Window_.getSize().x / 1920.0)),
                                     static_cast<float>(buf_y * (Window_.getSize().y / 1080.0)));
                buf_pair = std::pair<sf::Text, sf::IntRect>(buf_text, sf::IntRect());
                all_menu.find(buf_name)->second.push_back(buf_pair);
                continue;
            }

            buf_text.setString(sf::String::fromUtf8(buf.begin(), buf.end()));

            buf_text.setPosition(static_cast<float>(buf_x * (Window_.getSize().x / 1920.0)),
                                 static_cast<float>(buf_y * (Window_.getSize().y / 1080.0)));

            buf_pair = std::pair<sf::Text, sf::IntRect>(
                buf_text,
                sf::IntRect(
                    static_cast<int>(buf_text.getGlobalBounds().left),
                    static_cast<int>(buf_text.getGlobalBounds().top),
                    static_cast<int>(buf_text.getGlobalBounds().width),
                    static_cast<int>(buf_text.getGlobalBounds().height)
                )
            );

            all_menu.find(buf_name)->second.push_back(buf_pair);
        }
    }

    fout.close();

    return 0;
}

void Menu::set_text_to_normal_size() {
    for (auto &text : vector_show) {
        text.first.setCharacterSize(FONT_SIZE_MENU_BUTTON_sm);
    }
}

void Menu::set_text_bigger() {
    for (auto &text : vector_show) {
        if (text.second.contains(sf::Mouse::getPosition(Window_))) {
            text.first.setCharacterSize(FONT_SIZE_MENU_BUTTON_bg);
            break;
        }
    }
}

int Menu::select_level(sf::String level) {
    if (level == sf::String(L"Назад")) {
        user_level = prev_user_level;
        vector_show = all_menu.find(user_level)->second;

        animate = true;
        backstack = true;
//        std::cout << "animate true\n";

        // current_frame = 0;

        return 0;
    } else if (level == sf::String(L"Store")) {
        std::cout << "store\n";
        call_game_module(CODE_STORE);

        return 0;
    } else if (level == sf::String(L"Play")) {
        std::cout << "play\n";
        call_game_module(CODE_PLAY);

        return 0;
    } else {
        for (auto &word : levels) {
            if (word.second == level) {
                prev_user_level = user_level;
                user_level = word.first;
                vector_show = all_menu.find(user_level)->second;

                animate = true;
//                std::cout << "animate true\n";

                current_frame = 4;

                return 0;
            }
        }
    }

    std::cout << "undefined level to jump\n";
    return 1;
}

int Menu::event_handler() {
    sf::Event event;
    while (Window_.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                Window_.close();
                return CLOSE_WINDOW;


            case sf::Event::MouseButtonPressed:
                for (auto &text : vector_show) {
                    if (text.second.contains(sf::Mouse::getPosition(Window_))) {
                        select_level(text.first.getString());
                    }
                }

                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    user_level = prev_user_level;
                    vector_show = all_menu.find(user_level)->second;
                    animate = true;
//                    std::cout << "animate true\n";
                    backstack = true;

                    break;
                }

            case sf::Event::Resized:
                std::cout << "window resized\n";
                std::cout << "width = " << event.size.width << ", height = " << event.size.height << std::endl;
                std::cout << "width = " << Window_.getSize().x << ", height = " << Window_.getSize().y << std::endl;

                all_menu.clear();

                if (config_reader(CONFIG_PATH) != 0) {
                    return 0;
                }
//                for (auto &i : all_menu) {
//                     for (auto &x : i.second) {
//                         x.second = sf::IntRect(
//                             static_cast<int>(x.first.getGlobalBounds().left),
//                             static_cast<int>(x.first.getGlobalBounds().top),
//                             static_cast<int>(x.first.getGlobalBounds().width),
//                             static_cast<int>(x.first.getGlobalBounds().height)
//                         );
//                     }
//                }
                vector_show = all_menu.find(user_level)->second;
                break;

            default:
                // std::cout << "an event that is not handled\n";
                break;

        }
    }
    return 0;
}

void Menu::show() {
    float cur_time = 0;  // текущее время работы окна
    sf::Clock clock;

    music_.setLoop(true);
    music_.play();

    // test
//    Log log(Font_, 30, sf::Color::White, 500, 300);
//    std::string LOG = "тестики подъехали";
//    log.set_text(LOG);
    /////
    vector_show = all_menu.find(user_level)->second;

    while (Window_.isOpen()) {
        cur_time = clock.getElapsedTime().asMicroseconds();
        cur_time = cur_time / 800;

        if (cur_time > 100.0) {
            // std::cout << "current_frame = " << current_frame << ", animate = " << animate << ", backstack = " << backstack << std::endl;

            clock.restart();
            animate_phoenix();
        }

        set_text_to_normal_size();  // возвращает все подменюшки к 32 размеру
        set_text_bigger();  // увеливает при наведении до 36 размера

        event_handler();  // хэндлер ивентов

        Window_.clear();

        // test
//        Window_.draw(log.get_drawable().second);
//        Window_.draw(log.get_drawable().first);
        /////

        Window_.draw(Title_);
        Window_.draw(convex);

        Window_.draw(phoenix_sprite);

//        for (auto &line : vector_lines) {
//            Window_.draw(line);
//        }
        for (auto it = vector_lines.begin(); it != vector_lines.end(); ++it) {
            Window_.draw(*it);
        }

//        for (auto &text : vector_show) {
//            Window_.draw(text.first);
//        }
        for (auto it = vector_show.begin(); it != vector_show.end(); ++it) {
            Window_.draw(it->first);
        }

        Window_.display();
    }

    return;
}

std::vector<sf::Text> Menu::get_text_module(std::string &level) {
    std::vector<sf::Text> tmp;
    std::vector<std::pair<sf::Text, sf::IntRect>> vector_show = all_menu.find(level)->second;
    for (auto x : vector_show) {
        tmp.push_back(x.first);
    }

    return tmp;
}

std::vector<std::pair<sf::Text, sf::IntRect>> Menu::get_all_vals(std::string &level) {
    return all_menu.find(level)->second;
}

sf::Text Menu::get_title() {
    return Title_;
}

std::string Menu::get_user_level() {
    return user_level;
}

std::string Menu::get_prev_user_level() {
    return prev_user_level;
}

void Menu::animate_phoenix() {
    if (backstack) {
        current_frame--;
    } else {
        current_frame++;
    }

    if (animate) {
        if (current_frame >= 9 && !backstack) {  // так надо, если > 11 фреймов, то будет плохая анимашка
            // animate = false;
            current_frame = 10;
        } else if (current_frame < 3 && backstack) {
            animate = false;
            backstack = false;
            current_frame = 0;
        }
    } else {
        if (current_frame > 3) {
            current_frame = 0;
        }
    }
    
    phoenix_sprite.setTextureRect(sf::IntRect(current_frame * 250, 0, 250, 250));
}

void Menu::call_game_module(int module_num) {
    switch (module_num) {
        case CODE_PLAY: {
            std::cout << "calling play\n";
//            Game game(&Window_);
//            game.run();
            music_.pause();
            game.run();
            music_.play();
            return;
        }
        case CODE_STORE: {
            // берем плееров через соответствующие геттеры_птр и запихиваем в магаз

            std::cout << "calling store\n";
            std::shared_ptr<Player> player_ptr(game.get_left_player_ptr());
            std::shared_ptr<sf::RenderWindow> window_ptr(&Window_);
            Store store(window_ptr, player_ptr);
            store.display();

            return;
        }
        default: {
            std::cout << "unknown num_model\n";
            return;
        }
    }
}

#include <ui.hpp>
#include <iostream>
#include <fstream>
#include <game.hpp>

#include "game.hpp"

Game::Game(sf::RenderWindow *window) : window_pointer_(window) {
    //  TEST
    Mistborn mistborn(sf::String("mistborn"), sf::String("mistborn"), 130, 30, 0, 0, 7, 300);
    Soldier soldier(sf::String("soldier"), sf::String("soldier"), 100, 10, 0, 0, 5, 50);
    Misting misting_hunter(sf::String("misting_hunter"), sf::String("misting_hunter"), 100, 20, 0, 0, 10, 150);
    Misting misting_trasher(sf::String("misting_trasher"), sf::String("misting_trasher"), 70, 40, 0, 0, 3, 150);
    Misting misting_lightener(sf::String("misting_lightener"), sf::String("misting_lightener"), 90, 30, 0, 0, 5, 150);

//    Mistborn test4(100, 10, 9, 8, 3, 600, sf::String("test_mistborn_1"), sf::String("test_mistborn_1"));
//    Soldier test5(100, 200, 9, 8, 2, 600, sf::String("test_soldier_1"), sf::String("test_soldier_1"));
//    Misting test6(100, 50, 9, 8, 100, 600, sf::String("test_misting_1"), sf::String("test_misting_1"));

    //  Рука левого игрока
    left_player_.add_mistborn(mistborn);
    left_player_.add_soldier(soldier);
    left_player_.add_misting(misting_hunter);
    left_player_.add_misting(misting_trasher);
    left_player_.add_misting(misting_lightener);

    left_player_.update_hp();

    //  Рука правого игрока
    // right_player_.add_mistborn(test4);
    right_player_.add_soldier(soldier);
    // right_player_.add_misting(test6);

    right_player_.update_hp();

    Field new_field(*window, left_player_, right_player_);
    set_field(new_field);

    player_move = 0;
}

void Game::run() {
    while (window_pointer_->isOpen()) {
        while (!rules_were_shown_) {
            call_rules_module();
        }

        handle_events();
        render();
        update();

        if (has_finished_) {
            while (!scores_were_shown_) {
                call_scores_module();
            }
            return;
        }
    }
}

void Game::handle_events() {
    sf::Event event;
    while (window_pointer_->pollEvent(event)) {

        field_.catch_cursor(*window_pointer_, event, static_cast<short unsigned int> (player_move));
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
            player_move = (player_move + 1) % 2;
            std::cout << "player move : " << player_move << std::endl;
//            field_.output_field_with_belonging();
            if (player_move == 0) {
                field_.reload();
            }
        }
        if (event.type == sf::Event::Closed) {
            window_pointer_->close();
            return;
        }
    }
}

void Game::update() {
  left_player_.set_hp(field_.get_player(0).get_hp());
  right_player_.set_hp(field_.get_player(1).get_hp());

  update_has_finished();
  if (has_finished_) {
      return;
  }
}

void Game::update_has_finished() {
    has_finished_ = (left_player_.get_hp() <= 0 || right_player_.get_hp() <= 0);
}

void Game::render() {
    // TODO(): нормально это запихнуть
    Log log(20, sf::Color(184, 185, 196), ((1 - LOG_BOX_WIDTH)  * window_pointer_->getSize().x) / 2, window_pointer_->getSize().y - LOG_BOX_HEIGHT - 15, window_pointer_);
    std::string LOG = "логи работают, проверяй?";
    log.set_text(LOG);
    ////////////////////////////////////
    Player_units p_u(BOX_PADDING * window_pointer_->getSize().x, 0.3 * window_pointer_->getSize().y, &left_player_, window_pointer_);
    Player_units p_u2((1 - BOX_WIDTH - BOX_PADDING) * window_pointer_->getSize().x, 0.3  * window_pointer_->getSize().y, &right_player_, window_pointer_);
    ////////////////////////////////////
    window_pointer_->clear();

    field_.draw(*window_pointer_);

    left_player_.set_avatar_sprite(1);
    left_player_.set_avatar_position(AVATAR_HOR_INDENT, AVATAR_VERT_INDENT);
    window_pointer_->draw(left_player_.get_avatar_sprite());

    sf::String left_player_name = "Player 1";
    left_player_.set_player_name(left_player_name, left_player_.get_avatar_sprite().getTexture()->getSize().x * 1.15f, AVATAR_VERT_INDENT + AVATAR_HEIGHT + PLAYER_NAME_VERT_INDENT);  // TODO(nmerk): move magic digits to definitions.hpp
    window_pointer_->draw(left_player_.get_player_name());

    // right player
    right_player_.set_avatar_sprite(2);
    right_player_.set_avatar_position(window_pointer_->getSize().x - AVATAR_HOR_INDENT - AVATAR_WIDTH, AVATAR_VERT_INDENT);
    window_pointer_->draw(right_player_.get_avatar_sprite());

    sf::String right_player_name = "Player 2";
    right_player_.set_player_name(right_player_name, right_player_.get_avatar_sprite().getTexture()->getSize().x * 12.55f, AVATAR_VERT_INDENT + AVATAR_HEIGHT + PLAYER_NAME_VERT_INDENT);
    window_pointer_->draw(right_player_.get_player_name());

    // new
    window_pointer_->draw(log.get_drawable().second);
    window_pointer_->draw(log.get_drawable().first);
    p_u.draw(window_pointer_);
    p_u2.draw(window_pointer_);
    ///////////////////////

    window_pointer_->display();
}

sf::RenderWindow *Game::get_window() const {
    return window_pointer_;
}

void Game::set_window(sf::RenderWindow *window) {
    window_pointer_ = window;

    // TODO(): delete test
    // TEST
    Mistborn mistborn(sf::String("mistborn"), sf::String("mistborn"), 130, 30, 0, 0, 7, 300);
    Soldier soldier(sf::String("soldier"), sf::String("soldier"), 100, 10, 0, 0, 5, 50);
    Misting misting_hunter(sf::String("misting_hunter"), sf::String("misting_hunter"), 100, 20, 0, 0, 10, 150);
    Misting misting_trasher(sf::String("misting_trasher"), sf::String("misting_trasher"), 70, 40, 0, 0, 3, 150);
    Misting misting_lightener(sf::String("misting_lightener"), sf::String("misting_lightener"), 90, 30, 0, 0, 5, 150);

//    Mistborn test4(100, 10, 9, 8, 3, 600, sf::String("test_mistborn_1"), sf::String("test_mistborn_1"));
//    Soldier test5(100, 200, 9, 8, 2, 600, sf::String("test_soldier_1"), sf::String("test_soldier_1"));
//    Misting test6(100, 50, 9, 8, 100, 600, sf::String("test_misting_1"), sf::String("test_misting_1"));

    //  Рука левого игрока
    left_player_.add_mistborn(mistborn);
    left_player_.add_soldier(soldier);
    left_player_.add_misting(misting_hunter);
    left_player_.add_misting(misting_trasher);
    left_player_.add_misting(misting_lightener);

    left_player_.update_hp();

    //  Рука правого игрока
    // right_player_.add_mistborn(test4);
    right_player_.add_soldier(soldier);
    // right_player_.add_misting(test6);

    right_player_.update_hp();
    // END TEST

    Field new_field(*window, left_player_, right_player_);
    set_field(new_field);

    player_move = 0;
}

Player Game::get_left_player() const {
    return left_player_;
}
Player Game::get_right_player() const {
    return right_player_;
}

Player *Game::get_left_player_ptr() {
    return &left_player_;
}

Player *Game::get_right_player_ptr() {
    return &right_player_;
}

void Game::set_left_player(const Player &player) {
    left_player_ = player;
}
void Game::set_right_player(const Player &player) {
    right_player_ = player;
}

Field Game::get_field() const {
    return field_;
}

void Game::set_field(Field &field) {
    field_ = field;
}

void Game::call_rules_module() {
    window_pointer_->clear(sf::Color::Black);

    sf::Texture background;
    background.loadFromFile(PATH_TO_PICTURES + "rules_bg.png");
    sf::Sprite background_sprite;
    background_sprite.setTexture(background);
    background_sprite.setPosition(-150, 0);

    window_pointer_->draw(background_sprite);

    sf::Texture scroll;
    scroll.loadFromFile(PATH_TO_PICTURES + "rules.png");
    sf::Sprite scroll_sprite;
    scroll_sprite.setTexture(scroll);
    scroll_sprite.setPosition(window_pointer_->getSize().x / 2 - window_pointer_->getSize().x / 4,
                                  window_pointer_->getSize().y * 0.05);
    window_pointer_->draw(scroll_sprite);

    sf::Font font;
    font.loadFromFile(PLAYER_FONT);

    sf::Text header;
    header.setString("GAME RULES");
    header.setFont(font);
    header.setFillColor(sf::Color::Black);
    header.setCharacterSize(header.getCharacterSize() * 1.5);
    unsigned int header_x = (unsigned int)((window_pointer_->getSize().x - header.getLocalBounds().width) / 2),
                 header_y = (unsigned int)(window_pointer_->getSize().y * 0.15);
    header.setPosition(header_x, header_y);

    window_pointer_->draw(header);

    std::vector<std::string> rules;

    std::ifstream stream(PATH_TO_GAME_DATA + "rules.txt");  // TODO: add path to definitions.hpp

    std::string temp;
    while (!stream.eof()) {
        std::getline(stream, temp);
        rules.push_back(temp);
    }

    for (int i = 0; i < rules.size(); ++i) {
        sf::Text rules_text;
        rules_text.setString(rules[i]);
        rules_text.setFont(font);
        rules_text.setFillColor(sf::Color::Black);
        rules_text.setPosition((window_pointer_->getSize().x - rules_text.getLocalBounds().width) / 2,
                               header_y + 100 + i * (rules_text.getCharacterSize() * 1.5));

        window_pointer_->draw(rules_text);
    }

    std::pair<sf::Text, sf::IntRect> button;

    button.first.setFont(font);
    button.first.setFillColor(sf::Color::Black);
    button.first.setString("OK");
    unsigned int button_x = (window_pointer_->getSize().x - button.first.getLocalBounds().width) / 2,
                 button_y = (unsigned int)(window_pointer_->getSize().y * 0.75);

    button.first.setPosition(button_x, button_y);

    unsigned int button_width = 30, button_height = 30;
    sf::IntRect button_rect(button_x, button_y, button_width, button_height);
    button.second = button_rect;

    sf::Vector2f button_shape_size(button_width + 30, button_height + 20);
    sf::RectangleShape button_shape(button_shape_size);
    button_shape.setFillColor(sf::Color(224, 224, 224));
    button_shape.setPosition(button_x - 7, button_y - 7);

    if (button_rect.contains(sf::Mouse::getPosition(*window_pointer_))) {
        button.first.setCharacterSize(button.first.getCharacterSize() * 1.5);
        button_shape.setSize(sf::Vector2f((button_width + 30) * 1.5, (button_height + 30) * 1.5));
        button_shape.setPosition(button_x - 12, button_y - 14);
    }

    window_pointer_->draw(button_shape);
    window_pointer_->draw(button.first);

    window_pointer_->display();

    sf::Event event;

    while (window_pointer_->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window_pointer_->close();
                rules_were_shown_ = true;
                return;
            }

            case sf::Event::MouseButtonPressed: {
                if (button_rect.contains(sf::Mouse::getPosition(*window_pointer_))) {
                    rules_were_shown_ = true;
                    return;
                }
            }
        }
    }
}

void Game::call_scores_module() {

    window_pointer_->clear();

    sf::Texture background;
    background.loadFromFile(PATH_TO_PICTURES + "rules_bg.png");
    sf::Sprite background_sprite;
    background_sprite.setTexture(background);
    background_sprite.setPosition(-150, 0);

    window_pointer_->draw(background_sprite);

    sf::Texture scroll;
    scroll.loadFromFile(PATH_TO_PICTURES + "rules.png");
    sf::Sprite scroll_sprite;
    scroll_sprite.setTexture(scroll);
    scroll_sprite.setPosition(window_pointer_->getSize().x / 2 - window_pointer_->getSize().x / 4,
                              window_pointer_->getSize().y * 0.05);
    window_pointer_->draw(scroll_sprite);

    sf::Font font;
    font.loadFromFile(PLAYER_FONT);

    sf::Text header;
    header.setString("GAME SCORES");
    header.setFont(font);
    header.setFillColor(sf::Color::Black);
    header.setCharacterSize(header.getCharacterSize() * 1.5);
    unsigned int header_x = (unsigned int)((window_pointer_->getSize().x - header.getLocalBounds().width) / 2),
                 header_y = (unsigned int)(window_pointer_->getSize().y * 0.15);
    header.setPosition(header_x, header_y);

    window_pointer_->draw(header);

    sf::Text score_text;
    score_text.setFont(font);
    score_text.setFillColor(sf::Color::Black);

    if (left_player_.get_hp() <= 0) {
        score_text.setString("Player 2 has won!\n");\
    } else if (right_player_.get_hp() <= 0) {
        score_text.setString("Player 1 has won!\n");
    } else {
        score_text.setString("Wow, it's a draw!\n");
    }

    score_text.setPosition((window_pointer_->getSize().x - score_text.getLocalBounds().width) / 2,
                           header_y + (score_text.getCharacterSize() * 3));

    window_pointer_->draw(score_text);

    std::pair<sf::Text, sf::IntRect> button;

    button.first.setFont(font);
    button.first.setFillColor(sf::Color::Black);
    button.first.setString("OK");
    unsigned int button_x = (unsigned int)((window_pointer_->getSize().x - button.first.getLocalBounds().width) / 2),
                 button_y = (unsigned int)(window_pointer_->getSize().y * 0.75);

    button.first.setPosition(button_x, button_y);

    unsigned int button_width = 30, button_height = 30;
    sf::IntRect button_rect(button_x, button_y, button_width, button_height);
    button.second = button_rect;

    sf::Vector2f button_shape_size(button_width + 30, button_height + 20);
    sf::RectangleShape button_shape(button_shape_size);
    button_shape.setFillColor(sf::Color(224, 224, 224));
    button_shape.setPosition(button_x - 7, button_y - 7);

    if (button_rect.contains(sf::Mouse::getPosition(*window_pointer_))) {
        button.first.setCharacterSize(button.first.getCharacterSize() * 1.5);
        button_shape.setSize(sf::Vector2f((button_width + 30) * 1.5, (button_height + 30) * 1.5));
        button_shape.setPosition(button_x - 12, button_y - 14);
    }

    window_pointer_->draw(button_shape);
    window_pointer_->draw(button.first);

    window_pointer_->display();

    sf::Event event;

    while (window_pointer_->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window_pointer_->close();
                scores_were_shown_ = true;
                return;
            }

            case sf::Event::MouseButtonPressed: {
                if (button_rect.contains(sf::Mouse::getPosition(*window_pointer_))) {
                    scores_were_shown_ = true;
                    return;
                }
            }
        }
    }
}

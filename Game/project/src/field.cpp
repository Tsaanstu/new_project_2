#include "field.hpp"

#include <stdio.h>

void Field::reload() {
    for (auto it : departed_) {
        battle_field_[it.first][it.second].set_belonding(get_battle_field()[it.first][it.second].get_belonding() - 2);
    }
    departed_.clear();
}

void Field::set_Being_in_Cell(std::shared_ptr<Being> being, size_t i, size_t j) {
    if (battle_field_[i][j].if_free()) {
        being->set_coordinates(std::pair<float, float>(battle_field_[i][j].get_x(), battle_field_[i][j].get_y()));
        being->set_base_position(std::pair<float, float>(battle_field_[i][j].get_x(), battle_field_[i][j].get_y()));
        being->set_base_texture_rect(sf::IntRect(0, 0, BEING_WIDTH, BEING_HEIGHT));
        battle_field_[i][j].set_Being(being);
    }
}

short unsigned int Field::melee_combat(size_t f_i, size_t f_j, size_t s_i, size_t s_j) {
    short int first_hp = get_battle_field()[f_i][f_j].get_Being()->get_hp();
    short int first_force = get_battle_field()[f_i][f_j].get_Being()->get_force();
    short int second_hp = get_battle_field()[s_i][s_j].get_Being()->get_hp();
    short int second_force = get_battle_field()[s_i][s_j].get_Being()->get_force();
    second_hp -= first_force;
    if (second_hp <= 0) {
        battle_field_[s_i][s_j].update_being_hp(second_hp);
        renew_hp();
        return ENEMY_KILLED;
    } else {
        battle_field_[s_i][s_j].update_being_hp(second_hp);
        first_hp -= second_force;
        if (first_hp <= 0) {
            battle_field_[f_i][f_j].update_being_hp(first_hp);
            renew_hp();
            return FRIEND_KILLED;
        }
    }
    battle_field_[f_i][f_j].update_being_hp(first_hp);
    renew_hp();
    return DRAW;
}

unsigned short int Field::make_a_move(sf::RenderWindow &window, size_t i, size_t j, unsigned short int mode) {
    unsigned short int end_of_move = NORMAL_MOVE;
    std::shared_ptr<Being> temp = get_battle_field()[i][j].get_Being();
    switch (mode) {
        case 0:  //  up
            if (i == 0) {
                break;
            }
            if (!get_battle_field()[i - 1][j].get_type()) {
                break;
            }
            if (!get_battle_field()[i - 1][j].if_free()) {
                std::cout << get_battle_field()[i - 1][j].get_type() << get_battle_field()[i][j].get_type() << std::endl;
                if (get_battle_field()[i - 1][j].get_type() > 0 &&
                    get_battle_field()[i - 1][j].get_belonding() != get_battle_field()[i][j].get_belonding()) {
                    unsigned short int result = melee_combat(i, j, i - 1, j);
                    switch (result) {
                        case ENEMY_KILLED:
                            battle_field_[i - 1][j].delete_being();
                            end_of_move = STOP_MOVE;
                            break;
                        case FRIEND_KILLED:
                            battle_field_[i][j].delete_being();
                            return STOP_MOVE;
                        default:
                            return STOP_MOVE;
                    }
                } else {
                    break;
                }
            }

            set_Being_in_Cell(temp, i - 1, j);
            battle_field_[i - 1][j].set_belonding(get_battle_field()[i][j].get_belonding());
            battle_field_[i][j].set_belonding(0);
            battle_field_[i][j].delete_being();
            battle_field_[i - 1][j].set_y_coord(battle_field_[i - 1][j].get_y());
            return end_of_move;
        case 1:  //  right
            if (j + 1 > BATTLEFIELD_WIDTH - 1) {
                break;
            }
            if (!get_battle_field()[i][j + 1].get_type()) {
                break;
            }
            if (!get_battle_field()[i][j + 1].if_free()) {
                std::cout << get_battle_field()[i][j + 1].get_type() << get_battle_field()[i][j].get_type() << std::endl;
                if (get_battle_field()[i][j + 1].get_type() > 0 &&
                    get_battle_field()[i][j + 1].get_belonding() != get_battle_field()[i][j].get_belonding()) {
                    unsigned short int result = melee_combat(i, j, i, j + 1);
                    switch (result) {
                        case ENEMY_KILLED:
                            battle_field_[i][j + 1].delete_being();
                            end_of_move = STOP_MOVE;
                            break;
                        case FRIEND_KILLED:
                            battle_field_[i][j].delete_being();
                            return STOP_MOVE;
                        default:
                            return STOP_MOVE;
                    }
                } else {
                    break;
                }
            }

            set_Being_in_Cell(temp, i, j + 1);
            battle_field_[i][j + 1].set_belonding(get_battle_field()[i][j].get_belonding());
            battle_field_[i][j].set_belonding(0);
            battle_field_[i][j].delete_being();
            battle_field_[i][j + 1].set_y_coord(battle_field_[i][j + 1].get_y());
            return end_of_move;
        case 2:  //  down
            if (i + 1 > BATTLEFIELD_HEIGHT - 1) {
                break;
            }
            if (!get_battle_field()[i + 1][j].get_type()) {
                break;
            }
            if (!get_battle_field()[i + 1][j].if_free()) {
                std::cout << get_battle_field()[i + 1][j].get_type() << get_battle_field()[i][j].get_type() << std::endl;
                if (get_battle_field()[i + 1][j].get_type() > 0 &&
                    get_battle_field()[i + 1][j].get_belonding() != get_battle_field()[i][j].get_belonding()) {
                    unsigned short int result = melee_combat(i, j, i + 1, j);
                    switch (result) {
                        case ENEMY_KILLED:
                            battle_field_[i + 1][j].delete_being();
                            end_of_move = STOP_MOVE;
                            break;
                        case FRIEND_KILLED:
                            battle_field_[i][j].delete_being();
                            return STOP_MOVE;
                        default:
                            return STOP_MOVE;
                    }
                } else {
                    break;
                }
            }

            set_Being_in_Cell(temp, i + 1, j);
            battle_field_[i + 1][j].set_belonding(get_battle_field()[i][j].get_belonding());
            battle_field_[i][j].set_belonding(0);
            battle_field_[i][j].delete_being();
            battle_field_[i + 1][j].set_y_coord(battle_field_[i + 1][j].get_y());
            return end_of_move;
        case 3:  //  left
            if (j == 0) {
                break;
            }
            if (!get_battle_field()[i][j - 1].get_type()) {
                break;
            }
            if (!get_battle_field()[i][j - 1].if_free()) {
                std::cout << get_battle_field()[i][j - 1].get_type() << get_battle_field()[i][j].get_type() << std::endl;
                if (get_battle_field()[i][j - 1].get_type() > 0 &&
                    get_battle_field()[i][j - 1].get_belonding() != get_battle_field()[i][j].get_belonding()) {
                    unsigned short int result = melee_combat(i, j, i, j - 1);
                    switch (result) {
                        case ENEMY_KILLED:
                            battle_field_[i][j - 1].delete_being();
                            end_of_move = STOP_MOVE;
                            break;
                        case FRIEND_KILLED:
                            battle_field_[i][j].delete_being();
                            return STOP_MOVE;
                        default:
                            return STOP_MOVE;
                    }
                } else {
                    break;
                }
            }

            set_Being_in_Cell(temp, i, j - 1);
            battle_field_[i][j - 1].set_belonding(get_battle_field()[i][j].get_belonding());
            battle_field_[i][j].set_belonding(0);
            battle_field_[i][j].delete_being();
            battle_field_[i][j - 1].set_y_coord(battle_field_[i][j - 1].get_y());
            return end_of_move;
    }
    return 0;
}

void Field::cell_control(sf::RenderWindow &window, size_t i, size_t j) {
    unsigned short int distance_of_walk = 0;
    distance_of_walk = get_battle_field()[i][j].get_Being()->get_distance_of_walk();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                battle_field_[i][j].set_belonding(get_battle_field()[i][j].get_belonding() + 2);
                departed_.push_back(std::pair<size_t, size_t>(i, j));
                return;
            }
            if (distance_of_walk == 0) {
                battle_field_[i][j].set_belonding(get_battle_field()[i][j].get_belonding() + 2);
                departed_.push_back(std::pair<size_t, size_t>(i, j));
                return;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                unsigned short int result = make_a_move(window, i, j, 0);
                if (result == NORMAL_MOVE) {
                    --distance_of_walk;
                    --i;
                } else if (result == STOP_MOVE) {
                    battle_field_[i][j].set_belonding(get_battle_field()[i][j].get_belonding() + 2);
                    departed_.push_back(std::pair<size_t, size_t>(i, j));
                    return;
                }
                break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                unsigned short int result = make_a_move(window, i, j, 1);
                if (result == NORMAL_MOVE) {
                    --distance_of_walk;
                    ++j;
                } else if (result == STOP_MOVE) {
                    battle_field_[i][j].set_belonding(get_battle_field()[i][j].get_belonding() + 2);
                    departed_.push_back(std::pair<size_t, size_t>(i, j));
                    return;
                }
                break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                unsigned short int result = make_a_move(window, i, j, 2);
                if (result == NORMAL_MOVE) {
                    --distance_of_walk;
                    ++i;
                } else if (result == STOP_MOVE) {
                    battle_field_[i][j].set_belonding(get_battle_field()[i][j].get_belonding() + 2);
                    departed_.push_back(std::pair<size_t, size_t>(i, j));
                    return;
                }
                break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                unsigned short int result = make_a_move(window, i, j, 3);
                if (result == NORMAL_MOVE) {
                    --distance_of_walk;
                    --j;
                } else if (result == STOP_MOVE) {
                    battle_field_[i][j].set_belonding(get_battle_field()[i][j].get_belonding() + 2);
                    departed_.push_back(std::pair<size_t, size_t>(i, j));
                    return;
                }
                break;
            }
        }
        window.clear(sf::Color::White);
        draw(window);
        window.display();
    }
}

void Field::catch_cursor(sf::RenderWindow &window, sf::Event event, short unsigned int player_move) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.key.code == sf::Mouse::Left) {
            sf::Vector2i cursor_position = sf::Mouse::getPosition(window);
            if (cursor_position.x > horizontal_indentation_
                && cursor_position.x < window.getSize().x - horizontal_indentation_ &&
                cursor_position.y > upper_indentation_ && cursor_position.y < window.getSize().y - lower_indentation_) {
                size_t i = (cursor_position.y - upper_indentation_) / cell_width_,
                    j = (cursor_position.x - horizontal_indentation_) / cell_width_;
                if (!get_battle_field()[i][j].if_free()) {
                    if (player_move + 1 == get_battle_field()[i][j].get_belonding()) {
                        cell_control(window, i, j);
                        sf::Mouse::setPosition(sf::Vector2i(0, 0), window);
                    }
                }
                return;
            }
        }
    }
}

void Field::calculation_of_screen_parameters(sf::RenderWindow &window) {
    cell_width_ = window.getSize().y / 12;
    horizontal_indentation_ = window.getSize().x / 2 - cell_width_ * 6;
    upper_indentation_ = window.getSize().y * 0.05;
}

void Field::resize(sf::RenderWindow &window) {
    calculation_of_screen_parameters(window);
    double field_x_position = horizontal_indentation_;
    double field_y_position = upper_indentation_;
    for (auto i = 0; i < BATTLEFIELD_HEIGHT; ++i) {
        for (auto j = 0; j < BATTLEFIELD_WIDTH; ++j) {
            battle_field_[i][j].set_coord(field_x_position, field_y_position);
            battle_field_[i][j].set_size(cell_width_, cell_width_);
            field_x_position += cell_width_;
        }
        field_x_position = horizontal_indentation_;
        field_y_position += cell_width_;
    }
}

double Field::get_horizontal_indentation() const {
    return horizontal_indentation_;
}

double Field::get_vertical_indentation() const {
    return upper_indentation_;
}

double Field::get_cell_width() const {
    return cell_width_;
}

void Field::output_field() {
    for (auto i = 0; i < battle_field_.size(); ++i) {
        for (auto j = 0; j < battle_field_[i].size(); ++j) {
            std::cout << battle_field_[i][j].get_x() << " " << battle_field_[i][j].get_y() << std::endl;
        }
        std::cout << std::endl;
    }
}

void Field::draw(sf::RenderWindow &window) {
    window.draw(background_sprite_);
    for (auto i = 0; i < BATTLEFIELD_HEIGHT; ++i) {
        for (auto j = 0; j < BATTLEFIELD_WIDTH; ++j) {
            window.draw(battle_field_[i][j].get_sprite());
            if (battle_field_[i][j].get_Being()) {
                window.draw(battle_field_[i][j].get_Being()->get_sprite());
            }
        }
    }
}

void Field::init_battle_field() {
    double field_x_position = horizontal_indentation_;
    double field_y_position = upper_indentation_;
    for (auto i = 0; i < BATTLEFIELD_HEIGHT; ++i) {
        std::vector<Cell> buf_bf_line;
        for (auto j = 0; j < BATTLEFIELD_WIDTH; ++j) {
            Cell temp_cell(field_x_position, field_y_position, cell_width_, cell_width_, 1, "test_map3");
            buf_bf_line.push_back(temp_cell);
            field_x_position += cell_width_;
        }
        field_x_position = horizontal_indentation_;
        field_y_position += cell_width_;
        battle_field_.push_back(buf_bf_line);
    }
    lower_indentation_ = field_y_position;
}

void Field::placement() {
    //  TODO: После написания player и game написать нормальную расстановку
    int j = 0;
    int misting_counter = 0;
    std::cout << "Placement:\n";
    for (size_t i = 0; i < players.size(); ++i) {
        for (auto it : players[i].get_mistborns()) {
            std::shared_ptr<Being> being(new Mistborn(it));
            set_Being_in_Cell(being, 0, j);
            battle_field_[0][j].set_belonding(i + 1);
        }
        for (auto it : players[i].get_soldiers()) {
            std::shared_ptr<Being> being(new Soldier(it));
            set_Being_in_Cell(being, 4, j);
            battle_field_[4][j].set_belonding(i + 1);
        }
        for (auto it : players[i].get_mistings()) {
            std::shared_ptr<Being> being(new Misting(it));
            set_Being_in_Cell(being, 2 * misting_counter + 1, j);  // пока нечетные клетки
            battle_field_[2 * misting_counter + 1][j].set_belonding(i + 1);
            misting_counter++;
        }
        players[i].clear_beings_vector();
        j += 11;
    }
    generation_of_obstacles();
}

Field::Field(sf::RenderWindow &window, Player &left, Player &right) {
    if (!background_texture_.loadFromFile(PATH_TO_BACKGROUND))
        std::cout << "UNABLE TO LOAD BACKGROUND" << std::endl;

    background_sprite_.setTexture(background_texture_);

    players.push_back(left);
    players.push_back(right);
    calculation_of_screen_parameters(window);
    init_battle_field();
    placement();
    lower_indentation_ = window.getSize().y - lower_indentation_;
    output_field_with_belonging();
}

void Field::generation_of_obstacles() {
    std::random_device rd;
    std::mt19937 generator(rd());
    for (auto i = 0; i < NUMBER_OF_OBSTACLES; ++i) {
        std::uniform_int_distribution<int> x(2, BATTLEFIELD_WIDTH - 3);
        std::uniform_int_distribution<int> y(0, BATTLEFIELD_HEIGHT - 1);
        size_t y_it = y(generator), x_it = x(generator);
        while (battle_field_[y_it][x_it].get_belonding() != 0) {
            y_it = y(generator);
            x_it = x(generator);
        }
        battle_field_[y_it][x_it].set_type(false);
    }
}

std::vector<std::vector<Cell>> Field::get_battle_field() const {
    return battle_field_;
}

unsigned int Field::get_battle_field_width() const {
    return BATTLEFIELD_WIDTH;
}

unsigned int Field::get_battle_field_height() const {
    return BATTLEFIELD_HEIGHT;
}

Field &Field::operator=(const Field &other) {

    horizontal_indentation_ = other.horizontal_indentation_;
    upper_indentation_ = other.upper_indentation_;
    lower_indentation_ = other.lower_indentation_;
    cell_width_ = other.cell_width_;

    background_texture_ = other.background_texture_;
    background_sprite_.setTexture(background_texture_);

    for (const auto &i : other.battle_field_) {
        battle_field_.push_back(i);
    }

    for (const auto &i : other.players) {
        players.push_back(i);
    }

    return *this;
}

void Field::output_field_with_belonging() {
    for (auto it:battle_field_) {
        for (auto is:it) {
            std::cout << is.get_belonding() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

Player Field::get_player(unsigned int number) {  // 0 - left, 1 - right
    return players[number];
}

void Field::renew_hp() {
    std::vector<short int> players_hp(2);
    players_hp[0] = players_hp[1] = 0;  // [0] - левый, [1] - правый

    for (auto i = 0; i < BATTLEFIELD_HEIGHT; ++i) {
        for (auto j = 0; j < BATTLEFIELD_WIDTH; ++j) {
            if (battle_field_[i][j].get_belonding() != 0) {
                if (battle_field_[i][j].get_belonding() % 2) {  // нечетная - владеет левый игрок
                    players_hp[0] += battle_field_[i][j].get_Being()->get_hp();
                } else {  // четная - владеет правый игрок
                    players_hp[1] += battle_field_[i][j].get_Being()->get_hp();
                }
            }
        }
    }

    for (int i = 0; i < players.size(); ++i) {
        players[i].set_hp(players_hp[i]);
    }
}
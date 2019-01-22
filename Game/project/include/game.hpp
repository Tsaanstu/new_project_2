#ifndef NEW_PROJECT_2_GAME_HPP
#define NEW_PROJECT_2_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "player.hpp"
#include "field.hpp"
#include "button.hpp"
#include "definitions.hpp"

class Game {
 public:
    Game() = default;
    Game(sf::RenderWindow *window);

    ~Game() = default;

    void run();

    void call_rules_module();
    void call_scores_module();

    sf::RenderWindow *get_window() const;
    void set_window(sf::RenderWindow *window);

    Player get_left_player() const;
    Player get_right_player() const;

    Player *get_left_player_ptr();
    Player *get_right_player_ptr();

    void set_left_player(const Player &player_1);
    void set_right_player(const Player &player_2);

    Field get_field() const;
    void set_field(Field &field);

    bool left_player_has_won();  // to check who has won the game: true - player_1, false - player_2

 private:
    sf::RenderWindow *window_pointer_;

    bool has_finished_ = false;  // TODO: (nmerk) move to consructor
    bool rules_were_shown_ = false;
    bool scores_were_shown_ = false;

    bool player_move;

    Player left_player_;
    Player right_player_;

    Field field_;

    void handle_events();
    void update();
    void render();

    void update_has_finished();
};

#endif  // NEW_PROJECT_2_GAME_HPP

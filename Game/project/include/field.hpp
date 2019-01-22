#ifndef NEW_PROJECT_2_FIELD_HPP
#define NEW_PROJECT_2_FIELD_HPP

#include <vector>

#include "cell.hpp"
#include "player.hpp"

#define NORMAL_MOVE 1
#define ENEMY_KILLED 10
#define FRIEND_KILLED 20
#define DRAW 0
#define STOP_MOVE 100

class Field {
 public:
  Field() = default;
  Field(sf::RenderWindow &window, Player &left, Player &right);
  ~Field() = default;
  Field &operator=(const Field &other);
  void renew_hp();
  void placement();
  void calculation_of_screen_parameters(sf::RenderWindow &window);
  void init_battle_field();
  void output_field();
  void draw(sf::RenderWindow &window);
  void catch_cursor(sf::RenderWindow &window, sf::Event event, short unsigned int player_move);
  void cell_control(sf::RenderWindow &window, size_t i, size_t j);
  void resize(sf::RenderWindow &window);
  unsigned short int make_a_move(sf::RenderWindow &window, size_t i, size_t j, unsigned short int mode);
  void generation_of_obstacles();
  void output_field_with_belonging();
  void reload();
  short unsigned int melee_combat(size_t f_i, size_t f_j, size_t s_i, size_t s_j);
  //  get
    Player get_player(unsigned int number);  // 0 - left, 1 - right
  std::vector<std::vector<Cell>> get_battle_field() const;
  unsigned int get_battle_field_width() const;
  unsigned int get_battle_field_height() const;
  double get_horizontal_indentation() const;
  double get_vertical_indentation() const;
  double get_cell_width() const;
  //  set
  void set_Being_in_Cell(std::shared_ptr<Being> being, size_t i, size_t j);
 private:
  std::vector<std::vector<Cell>> battle_field_;
  std::vector<std::pair<size_t, size_t>> departed_;  //  координаты походивших существ
  std::vector<Player> players;
  const unsigned int battle_field_width_ = 12;
  const unsigned int battle_field_height_ = 10;
  double horizontal_indentation_;
  double upper_indentation_;
  double lower_indentation_;
  double cell_width_;

  sf::Texture background_texture_;
  sf::Sprite background_sprite_;
};

#endif //NEW_PROJECT_2_FIELD_HPP

#ifndef NEW_PROJECT_2_CELL_HPP
#define NEW_PROJECT_2_CELL_HPP

#include "definitions.hpp"
#include "misting.hpp"
#include "mistborn.hpp"
#include "soldier.hpp"

class Cell {
 public:
  Cell() = default;
  Cell(double x_, double y_, double width_, double height_, bool type_, sf::String file_name_);
  Cell(const Cell &object);
  void delete_being();
  bool if_active(sf::Vector2i cursor_position);
  bool if_free();
  void update_being_hp(short int _hp);
  //  get
  double get_x() const;
  double get_y() const;
  double get_width() const;
  double get_height() const;
  bool get_type() const;
  sf::Sprite get_sprite();
  std::shared_ptr<Being> get_Being() const;
  unsigned short int get_belonding() const;
  //  set
  void set_Being(std::shared_ptr<Being> being);
  void set_x_coord(double _x);
  void set_y_coord(double _y);
  void set_coord(double _x, double _y);
  void set_being_coord(double _x, double _y);
  void set_size(double _width, double _height);
  void set_type(bool _type);
  void set_belonding(unsigned short int bl);
 private:
  double x_;
  double y_;
  double width_;
  double height_;
  bool type_;  //  Проходима?
  unsigned short int belonging_; //  0 - нейтральная, нечётная - владеет левый игрок, чётная - правый.

  sf::String file_name_;
  sf::Texture texture_;
  sf::Sprite sprite_;
  std::shared_ptr<Being> being_;
};

#endif //NEW_PROJECT_2_CELL_HPP

#ifndef NEW_PROJECT_2_BEING_HPP
#define NEW_PROJECT_2_BEING_HPP

#include "object.hpp"

class Being : public Object {
 public:
    Being(short int hp = 0, short int force = 0, short int distant_force = 0,
          double accuracy_of_shooting = 0, short int distance_of_walk = 0,
          int cost = 0, sf::String file_name = "", sf::String name = "");
    Being(const Being &b);
    ~Being() = default;

    //  get
    short int get_hp() const;
    short int get_force() const;
    short int get_distant_force() const;
    double get_accuracy_of_shooting() const;
    short int get_distance_of_walk() const;
    std::pair<float, float> get_coordinates() const;
    //  set
    void set_hp(short int hp);
    void set_force(short int force);
    void set_distant_force(short int range);
    void set_accuracy_of_shooting(double accuracy);
    void set_distance_of_walk(short int ranged_attack);
    void set_coordinates(std::pair<float, float> coord);
 private:
    short int hp_;  // здоровье
    short int force_;  // сила ближней атаки
    short int distant_force_;  // сила дальней атаки
    double accuracy_of_shooting_;  // меткость стрельбы
    short int distance_of_walk_;  // дальность хода
    std::pair<float, float> coordinates_;  // пара координат Х и Y
};

#endif //NEW_PROJECT_2_BEING_HPP
#ifndef NEW_PROJECT_2_ALLOMANT_HPP
#define NEW_PROJECT_2_ALLOMANT_HPP

#include "being.hpp"
#include "metal.hpp"

class Allomant : public Being {
 public:
    Allomant(short int hp = 0, short int force = 0, short int distant_force = 0,
             double accuracy_of_shooting = 0, short int distance_of_walk = 0,
             int cost = 0, sf::String file_name = "", sf::String name = "") :
        Being(hp, force, distant_force, accuracy_of_shooting, distance_of_walk, cost, file_name, name) {};
    ~Allomant() = default;
    //  set
    void set_allomantic_power(const Metal &metal);
    //  get
    short int get_force() const;
    short int get_distant_force() const;
    double get_accuracy_of_shooting() const;
    short int get_distance_of_walk() const;
 private:
    Allomantic_power power_;
};

#endif //NEW_PROJECT_2_ALLOMANT_HPP

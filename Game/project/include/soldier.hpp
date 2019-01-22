#ifndef NEW_PROJECT_2_SOLDIER_HPP
#define NEW_PROJECT_2_SOLDIER_HPP

#include "being.hpp"

class Soldier : public Being {
 public:
    Soldier(sf::String file_name = "", sf::String name = "",
            short int hp = 0, short int force = 0, short int distant_force = 0,
            double accuracy_of_shooting = 0, short int distance_of_walk = 0,
            int cost = 0) :
        Being(hp, force, distant_force, accuracy_of_shooting, distance_of_walk, cost, file_name, name) {};
    Soldier(const Soldier &b) : Being(b) {};
    ~Soldier() = default;
    void read_data_from_file(std::string path_file) override;
};

#endif //NEW_PROJECT_2_SOLDIER_HPP

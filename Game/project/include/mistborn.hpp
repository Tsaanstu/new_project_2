#ifndef NEW_PROJECT_2_BORN_HPP
#define NEW_PROJECT_2_BORN_HPP

#include "allomant.hpp"
#include "definitions.hpp"

class Mistborn : public Allomant {
 public:
    Mistborn(sf::String file_name = "", sf::String name = "",
             short int hp = 0, short int force = 0, short int distant_force = 0,
             double accuracy_of_shooting = 0, short int distance_of_walking = 0,
             int cost = 0) :
        Allomant(hp, force, distant_force, accuracy_of_shooting, distance_of_walking, cost, file_name, name) {};
    ~Mistborn() = default;
    void read_data_from_file(std::string path_file) override;
};

#endif //NEW_PROJECT_2_BORN_HPP

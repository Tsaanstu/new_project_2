#ifndef NEW_PROJECT_2_METAL_HPP
#define NEW_PROJECT_2_METAL_HPP

#include "definitions.hpp"
#include "object.hpp"
#include "allomantic_power.hpp"

class Metal : public Object {
 public:
    Metal(sf::String file_name = "", sf::String name = "",
          unsigned int act_time = 0, short int force = 0, short int distant_force = 0,
          double accuracy_of_shooting = 0, short int distance_of_walk = 0,
          int cost = 0);

    ~Metal() = default;
    void read_data_from_file(std::string path_file) override;

    //  set
    void set_action_time(unsigned int action_time);

    //  get
    Allomantic_power get_allomantic_power() const;
    unsigned int get_action_time() const;
 private:
    Allomantic_power metal_parameter_;
    unsigned int action_time_;
};

#endif //NEW_PROJECT_2_METAL_HPP

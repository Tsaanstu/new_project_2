#include <iostream>
#include <fstream>

#include "metal.hpp"

Metal::Metal(sf::String file_name, sf::String name,
              unsigned int act_time, short int force, short int distant_force,
             double accuracy_of_shooting, short int distance_of_walk,
             int cost) :
    Object(cost, file_name, name) {
    metal_parameter_ = Allomantic_power(force, distant_force, accuracy_of_shooting, distance_of_walk);
    action_time_ = act_time;
}

void Metal::set_action_time(unsigned int action_time) {
    this->action_time_ = action_time;
}

Allomantic_power Metal::get_allomantic_power() const {
    return metal_parameter_;
}

unsigned int Metal::get_action_time() const {
    return action_time_;
}

void Metal::read_data_from_file(std::string path_file) {
    std::string src = PATH_TO_METALS + path_file + ".txt";
    std::ifstream fin(src);
    if (!fin.is_open()) {
        std::cout << PATH_TO_METALS << path_file << ".txt ";
        std::cout << "not found\n";
        return;
    }

    std::string string_buf;
    int int_buf;
    short int short_int_buf;
    double double_buf;
    fin >> string_buf;
    this->set_name(sf::String(string_buf));
    fin >> short_int_buf;
    this->set_action_time(short_int_buf);
    fin >> short_int_buf;
    metal_parameter_.set_force(short_int_buf);
    fin >> short_int_buf;
    metal_parameter_.set_distant_force(short_int_buf);
    fin >> double_buf;
    metal_parameter_.set_accuracy_of_shooting(double_buf);
    fin >> short_int_buf;
    metal_parameter_.set_distance_of_walk(short_int_buf);
    fin >> int_buf;
    this->set_cost(int_buf);
}

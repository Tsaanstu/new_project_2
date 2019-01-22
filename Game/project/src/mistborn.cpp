#include <iostream>
#include <fstream>

#include "mistborn.hpp"

void Mistborn::read_data_from_file(std::string path_file) {
    std::string src = PATH_TO_MISTBORN + path_file + ".txt";
    std::ifstream fin(src);
    if (!fin.is_open()) {
        std::cout << PATH_TO_MISTBORN << path_file << ".txt ";
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
    this->set_hp(short_int_buf);
    fin >> short_int_buf;
    this->set_force(short_int_buf);
    fin >> short_int_buf;
    this->set_distant_force(short_int_buf);
    fin >> double_buf;
    this->set_accuracy_of_shooting(double_buf);
    fin >> short_int_buf;
    this->set_distance_of_walk(short_int_buf);
    fin >> int_buf;
    this->set_cost(int_buf);
}

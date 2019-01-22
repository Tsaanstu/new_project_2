#include "allomant.hpp"

// set
void Allomant::set_allomantic_power(const Metal &metal) {
    power_ = metal.get_allomantic_power();
};

// get
short int Allomant::get_force() const {
    return Being::get_force() + power_.get_force();
}

short int Allomant::get_distant_force() const {
    return Being::get_distant_force() + power_.get_distant_force();
}

double Allomant::get_accuracy_of_shooting() const {
    return Being::get_accuracy_of_shooting() + power_.get_accuracy_of_shooting();
}

short int Allomant::get_distance_of_walk() const {
    return Being::get_distance_of_walk() + power_.get_distance_of_walk();
}


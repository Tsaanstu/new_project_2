#include "allomantic_power.hpp"

Allomantic_power::Allomantic_power(short int force, short int distant_force,
                                   double accuracy_of_shooting, short int distance_of_walk) {
    this->force_ = force;
    this->distant_force_ = distant_force;
    this->accuracy_of_shooting_ = accuracy_of_shooting;
    this->distance_of_walk_ = distance_of_walk;
}

Allomantic_power &Allomantic_power::operator=(const Allomantic_power &ap2) {
    this->force_ = ap2.get_force();
    this->distant_force_ = ap2.get_distant_force();
    this->accuracy_of_shooting_ = ap2.get_accuracy_of_shooting();
    this->distance_of_walk_ = ap2.get_distance_of_walk();
    return *this;
}

// get
short int Allomantic_power::get_force() const {
    return force_;
}

short int Allomantic_power::get_distant_force() const {
    return distant_force_;
}

double Allomantic_power::get_accuracy_of_shooting() const {
    return accuracy_of_shooting_;
}

short int Allomantic_power::get_distance_of_walk() const {
    return distance_of_walk_;
}

// set
void Allomantic_power::set_force(short int force) {
    this->force_ = force;
}

void Allomantic_power::set_distant_force(short int distant_force) {
    this->distant_force_ = distant_force;
}

void Allomantic_power::set_accuracy_of_shooting(double accuracy_of_shooting) {
    this->accuracy_of_shooting_ = accuracy_of_shooting;
}

void Allomantic_power::set_distance_of_walk(short int distance_of_walk) {
    this->distance_of_walk_ = distance_of_walk;
}

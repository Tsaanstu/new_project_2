#include "being.hpp"

Being::Being(short int hp, short int force, short int distant_force,
             double accuracy_of_shooting, short int distance_of_walk,
             int cost, sf::String file_name, sf::String name) : Object(cost, file_name, name) {
    this->hp_ = hp;
    this->force_ = force;
    this->distant_force_ = distant_force;
    this->accuracy_of_shooting_ = accuracy_of_shooting;
    this->distance_of_walk_ = distance_of_walk;
    this->coordinates_ = std::make_pair(0, 0);
}

Being::Being(const Being &b) : Object(b) {
    hp_ = b.hp_;
    force_ = b.force_;
    distant_force_ = b.distant_force_;
    accuracy_of_shooting_ = b.accuracy_of_shooting_;
    distance_of_walk_ = b.distance_of_walk_;
    coordinates_ = b.coordinates_;
}

// get
short int Being::get_hp() const {
    return hp_;
}

short int Being::get_force() const {
    return force_;
}

short int Being::get_distant_force() const {
    return distant_force_;
}

double Being::get_accuracy_of_shooting() const {
    return accuracy_of_shooting_;
}

short int Being::get_distance_of_walk() const {
    return distance_of_walk_;
}

std::pair<float, float> Being::get_coordinates() const {
    return coordinates_;
}

// set
void Being::set_hp(short int hp) {
    this->hp_ = hp;
}

void Being::set_force(short int force) {
    this->force_ = force;
}

void Being::set_distant_force(short int distant_force) {
    this->distant_force_ = distant_force;
}

void Being::set_accuracy_of_shooting(double accuracy_of_shooting) {
    this->accuracy_of_shooting_ = accuracy_of_shooting;
}

void Being::set_distance_of_walk(short int distance_of_walk) {
    this->distance_of_walk_ = distance_of_walk;
}

void Being::set_coordinates(std::pair<float, float> _coordinates) {
    this->coordinates_ = _coordinates;
}

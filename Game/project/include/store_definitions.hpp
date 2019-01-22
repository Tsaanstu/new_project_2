#ifndef NEW_STRATEGY_1_PROJECT_INCLUDE_STORE_DEFINITIONS_HPP
#define NEW_STRATEGY_1_PROJECT_INCLUDE_STORE_DEFINITIONS_HPP

#include <iostream>

const int LONG_GAP = 300;

const int NUM_OF_PROPERTIES_BEINGS = 6;
const int NUM_OF_PROPERTIES_METALS = 6;

const std::string ALL_PROPERTIES_BEINGS[] = {
    "hp: ",
    "force: ",
    "distant_force: ",
    "accuracy: ",
    "distance: ",
    "cost: "
};

const std::string ALL_PROPERTIES_METALS[] = {
    "time: ",
    "force: ",
    "distant_force: ",
    "accuracy: ",
    "distance: ",
    "cost: "
};

const std::string BUTTON_BACK_STRING = " Back ";
const std::string BUTTON_BUY_STRING = " Buy ";

const int NUM_OF_METALS = 1;

const int NUM_OF_SOLDIERS = 1;
const int NUM_OF_MISTBORNS = 1;
const int NUM_OF_MISTINGS = 3;

const int NUM_OF_ITEMS_BEINGS = NUM_OF_SOLDIERS + NUM_OF_MISTBORNS + NUM_OF_MISTINGS; 

const int TYPE_SOLDIER = 2;
const int TYPE_MISTBORN = 3;
const int TYPE_MISTING = 4;

const std::string ALL_METALS[] = {
    "test_metal_1"
};

const std::string ALL_SOLDIERS[] = {
    "soldier"
};

const std::string ALL_MISTBORNS[] = {
    "mistborn"
};

const std::string ALL_MISTINGS[] = {
    "hunter",
    "trasher",
    "lightener"
};

#endif  // NEW_STRATEGY_1_PROJECT_INCLUDE_STORE_DEFINITIONS_HPP

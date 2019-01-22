#ifndef NEW_STRATEGY_1_DEFINITIONS_HPP
#define NEW_STRATEGY_1_DEFINITIONS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <memory>
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <array>
#include <any>
#include <random>

const std::string PATH_TO_GAME_DATA = "game_data/";
/*
 * to run with CMake add "../" at the beginning,
 * to run with Makefile vice versa
 */

const unsigned int WINDOW_WIDTH = 1440;
const unsigned int WINDOW_HEIGHT = 855;

//  object "database"
const std::string PATH_TO_SOLDIER = PATH_TO_GAME_DATA + "objects/beings/soldiery/";
const std::string PATH_TO_MISTBORN = PATH_TO_GAME_DATA + "objects/beings/allomancy/mistborn/";
const std::string PATH_TO_MISTING = PATH_TO_GAME_DATA + "objects/beings/allomancy/mistings/";
const std::string PATH_TO_METALS = PATH_TO_GAME_DATA + "objects/metals/";

const std::string PATH_TO_PICTURES = PATH_TO_GAME_DATA + "pictures/";
const std::string PATH_TO_FONTS = PATH_TO_GAME_DATA + "fonts/";
const std::string PICTURES_FORMAT = ".png";

const unsigned int BEING_WIDTH = 53;
const unsigned int BEING_HEIGHT = 66;

const std::string PLAYER_FONT = PATH_TO_FONTS + "12769.ttf";

//  avatar
const unsigned int AVATAR_VERT_INDENT = 100;
const unsigned int AVATAR_HOR_INDENT = 100;
const unsigned int AVATAR_HEIGHT = 100;
const unsigned int AVATAR_WIDTH = 100;
const unsigned int PLAYER_NAME_VERT_INDENT = 20;
const unsigned int PLAYER_NAME_HOR_INDENT = 100;

// player
const std::string PATH_TO_PLAYER_AVATAR = PATH_TO_PICTURES + "player.png";
const unsigned int DEFAULT_PLAYER_MONEY = 100;

// field
const unsigned int BATTLEFIELD_WIDTH = 12;
const unsigned int BATTLEFIELD_HEIGHT = 10;
const unsigned int NUMBER_OF_OBSTACLES = 7;
const std::string PATH_TO_BACKGROUND = PATH_TO_PICTURES + "background" + PICTURES_FORMAT;

// menu
const std::string PROJECT_NAME = "New_strategy_1";

const std::string MENU_FONT = PATH_TO_FONTS + "12561.otf";
const std::string CONFIG_PATH = PATH_TO_GAME_DATA + "menu_config.txt";
// const std::string PATH_PHOENIX = PATH_TO_PICTURES + "birdo250x250" + PICTURES_FORMAT;
const std::string PATH_PHOENIX = PATH_TO_PICTURES + "phoenix11frames" + PICTURES_FORMAT;


const unsigned int TITLE_POSITION_X = 20;
const unsigned int TITLE_POSITION_Y = 20;
const unsigned int TITLE_SIZE = 60;

const unsigned int FONT_SIZE_MENU_BUTTON_sm = 50;
const unsigned int FONT_SIZE_MENU_BUTTON_bg = 60;

const int OPEN_FILE_ERROR  = -1;

// store
const int NUM_OF_TABS = 2;
const std::string STORE_FONT = PATH_TO_FONTS + "ocr_onectt.ttf";
const int SIZE_OF_TEXT = 20;
const std::string TABNAMES[NUM_OF_TABS] = { " Heroes ", " Metals "};
const float GAP = 10;

const int  NUM_OF_PAGES = 1; //delete

const int NUM_OF_TYPES = 2;
const int TYPE_BEING = 0;
const int TYPE_METAL = 1;

const int NO_ACTIVE_ITEMS = -1;
const int NUM_OF_ITEMS = 3;

#endif // NEW_STRATEGY_1_DEFINITIONS_HPP

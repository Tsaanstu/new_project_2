#include "catch.hpp"
#include "menu.hpp"

TEST_CASE("menu", "[menu]") {
    Menu menu;
    SECTION("config") {
        REQUIRE(menu.config_reader("something wrong") == -1);
        REQUIRE(menu.config_reader(CONFIG_PATH) == 0);
    }
    
    SECTION("constructor") {
        REQUIRE(menu.get_title().getColor() == sf::Color::White);
        REQUIRE(menu.get_title().getString() == sf::String(L"New_project_1"));

        REQUIRE(menu.get_title().getPosition().x == TITLE_POSITION_X);
        REQUIRE(menu.get_title().getPosition().y == TITLE_POSITION_Y);

        REQUIRE(menu.get_title().getColor() == sf::Color::White);
        REQUIRE(menu.get_title().getCharacterSize() == TITLE_SIZE);

        REQUIRE(menu.get_user_level() == "main");
        REQUIRE(menu.get_prev_user_level() == "main");
    }

    SECTION("main_levels") {  // уровни из конфига
        std::string level = "main";
    
        std::vector<sf::String> strings;
        strings.push_back(sf::String(L"Play"));
        strings.push_back(sf::String(L"O_нас"));
        size_t i = 0;
        for (auto &x : menu.get_all_vals(level)) {
            REQUIRE(x.first.getString() == strings[i]);
            ++i;
        }   
    }
    
}

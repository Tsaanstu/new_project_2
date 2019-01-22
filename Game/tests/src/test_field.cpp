#include "catch.hpp"
#include "field.hpp"
#include "window.hpp"
#include "Game.hpp"

TEST_CASE("Field characteristics", "[field]") {

Window window(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, "Test");
    Field field(window);

    SECTION("horizontal_indentation") {
        REQUIRE(static_cast<int> (field.get_horizontal_indentation()) == 240);
    }

    SECTION("vertical_indentation") {
        REQUIRE(static_cast<int> (field.get_vertical_indentation()) == 66);
    }

    SECTION("cell_width") {
        REQUIRE(static_cast<int> (field.get_cell_width()) == 66);
    }
}

TEST_CASE("Cell position", "[field]") {

    Window window(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, "Test");
    Field field(window);

    SECTION("first cell") {
        REQUIRE(static_cast<int> (field.get_battle_field()[0][0].get_x()) == 240);
        REQUIRE(static_cast<int> (field.get_battle_field()[0][0].get_y()) == 66);
    }

    SECTION("last cell") {
        REQUIRE(static_cast<int> (field.get_battle_field()[9][11].get_x()) == 973);
        REQUIRE(static_cast<int> (field.get_battle_field()[9][11].get_y()) == 666);
    }
}

TEST_CASE("Cell position", "[field]") {

    Window window(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, "Test");
    G
    Field field(window);

    SECTION("first cell") {
        REQUIRE(static_cast<int> (field.get_battle_field()[0][0].get_x()) == 240);
        REQUIRE(static_cast<int> (field.get_battle_field()[0][0].get_y()) == 66);
    }

    SECTION("last cell") {
        REQUIRE(static_cast<int> (field.get_battle_field()[9][11].get_x()) == 973);
        REQUIRE(static_cast<int> (field.get_battle_field()[9][11].get_y()) == 666);
    }
}
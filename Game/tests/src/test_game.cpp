#include "catch.hpp"

#include "window.hpp"
#include "game.hpp"
#include "player.hpp"
#include "soldier.hpp"
#include "misting.hpp"
#include "mistborn.hpp"
#include "metal.hpp"

// game

TEST_CASE("game constructor", "[game]") {
  Window window((DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, "Test");

  SECTION("1") {
    Game game(&window);

    REQUIRE(game.get_window() == &window);
  }
}

TEST_CASE("player_1", "[game]") {
  Window window(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, "Test");
  Game game(&window);

  SECTION("1") {
    Player player_1;
    game.set_player_1(player_1);

    REQUIRE(game.get_player_1() == player_1);
  }
}

TEST_CASE("player_2", "[game]") {
  Player player_2;
  game.set_player_2(player_2);
  SECTION("1") {
    REQUIRE(game.get_player_2() == player_2);
  }
}

TEST_CASE("field", "[game]") {
  SECTION("1") {
    Field field;
    game.set_field(field);
    REQUIRE(game.get_field() == field);
  }
}

TEST_CASE("game finish", "[game]") {
  SECTION("1") {
    REQUIRE(game.has_finished() == false);
  }
}


// player

TEST_CASE("hp", "[player]") {
  Player player;
  SECTION("1") {
    REQUIRE(player.get_hp() == 0);
  }
}

TEST_CASE("soldiers", "[player]") {
  Player player;
  Soldier soldier;
  player.add_soldier(soldier);
  SECTION("1") {
    REQUIRE(player.get_soldiers()[0] == soldier);
  }
}

TEST_CASE("mistings", "[player]") {
  Player player;
  Misting misting;
  player.add_misting(misting);
  SECTION("1") {
    REQUIRE(player.get_mistings()[0] == misting);
  }
}

TEST_CASE("mistborns", "[player]") {
  Player player;
  Mistborn mistborn;
  player.add_mistborn(mistborn);
  SECTION("1") {
    REQUIRE(player.get_mistborns()[0] == mistborn);
  }
}

TEST_CASE("metals", "[player]") {
  Player player;
  Metal metal;
  player.add_metal(metal);
  SECTION("1") {
    REQUIRE(player.get_metals()[0] == metal);
  }
}


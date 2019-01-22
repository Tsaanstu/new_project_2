#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "store.hpp"

/*TEST_CASE("store construction default initialisation", "[store]") {
    Window window(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, "Test");
	
	SECTION("without activeTab argument") {
		Store store(&window);

		REQUIRE(store.getWindow() == &window);
		REQUIRE(store.getActiveTab() == 0);
	}

	SECTION("with normal activeTab argument") {
		Store store(&window, 1);

		REQUIRE(store.getWindow() == &window);
		REQUIRE(store.getActiveTab() == 1);
	}
}*/

TEST_CASE("tab initialisation", "[tab]") {
	SECTION("without arguments, small initialisation") {
		Tab tab;

		REQUIRE(tab.getNum() == 0);
		REQUIRE(tab.getIsActive() == false);
		REQUIRE(tab.getActivePage() == 0);
	}
	
	SECTION("full initialisation") {
		Tab tab(1);

		REQUIRE(tab.getNum() == 1);
		REQUIRE(tab.getIsActive() == false);
		REQUIRE(tab.getActivePage() == 0);
	}

	SECTION("with all args, but second argument -- unnormal value") {
		Tab tab(1, 2, 1);

		REQUIRE(tab.getNum() == 1);
		REQUIRE(tab.getIsActive() == true);
		REQUIRE(tab.getActivePage() == 1);
	}
}

TEST_CASE("tab setWindow function", "[tab]") {
    Window window(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, "Test");
	Tab tab;
	
	SECTION("with argument -- normal value") {
		REQUIRE(tab.setWindow(&window) == true);  	// TODO(gleensande): ask, is it normal -- to have a return value in such a function
		REQUIRE(tab.getWindow() == &window);
	}

	SECTION("with argument -- unnormal value") {
		REQUIRE(tab.setWindow(NULL) == false);  	// TODO(gleensande): ask, is it norma - return false this time and don`t set value
	}
}

TEST_CASE("page setWindow function", "[page]") {
    Window window(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, "Test");
	Page page;
	
	SECTION("with argument -- normal value") {
		REQUIRE(page.setWindow(&window) == true);
		REQUIRE(page.getWindow() == &window);
	}

	SECTION("with argument -- unnormal value") {
		REQUIRE(page.setWindow(NULL) == false);
	}
}

#include "catch.hpp"
#include "mistborn.hpp"
#include "misting.hpp"
#include "soldier.hpp"
#include "metal.hpp"

TEST_CASE("mistborn, constructor with initialisation", "[mistborn]") {
	
	SECTION("without argument") {
		Mistborn mistborn(100, 10, 9, 8, 7, 600, String("test_mistborn_1"), String("test_mistborn_1"));
		REQUIRE(mistborn.get_name().toAnsiString() == "test_mistborn_1");
		REQUIRE(mistborn.get_hp() == 100);
		REQUIRE(mistborn.get_force() == 10);
		REQUIRE(mistborn.get_distant_force() == 9);
		REQUIRE(mistborn.get_accuracy_of_shooting() == 8);
		REQUIRE(mistborn.get_distance_of_walk() == 7);
		REQUIRE(mistborn.get_cost() == 600);

	}

	SECTION("from file") {
		Mistborn mistborn;
		mistborn.read_data_from_file("test_mistborn_1");
		REQUIRE(mistborn.get_name().toAnsiString() == "test_mistborn_1");
		REQUIRE(mistborn.get_hp() == 80);
		REQUIRE(mistborn.get_force() == 10);
		REQUIRE(mistborn.get_distant_force() == 11);
		REQUIRE(mistborn.get_accuracy_of_shooting() == 12);
		REQUIRE(mistborn.get_distance_of_walk() == 13);
		REQUIRE(mistborn.get_cost() == 100);
	}
}


TEST_CASE("misting, constructor with initialisation", "[misting]") {
	
	SECTION("without argument") {
		Misting misting(100, 10, 9, 8, 7, 600, String("test_misting_1"), String("test_misting_1"));
		REQUIRE(misting.get_name().toAnsiString() == "test_misting_1");
		REQUIRE(misting.get_hp() == 100);
		REQUIRE(misting.get_force() == 10);
		REQUIRE(misting.get_distant_force() == 9);
		REQUIRE(misting.get_accuracy_of_shooting() == 8);
		REQUIRE(misting.get_distance_of_walk() == 7);
		REQUIRE(misting.get_cost() == 600);

	}

	SECTION("from file") {
		Misting misting;
		misting.read_data_from_file("test_misting_1");
		REQUIRE(misting.get_name().toAnsiString() == "test_misting_1");
		REQUIRE(misting.get_hp() == 90);
		REQUIRE(misting.get_force() == 10);
		REQUIRE(misting.get_distant_force() == 11);
		REQUIRE(misting.get_accuracy_of_shooting() == 12);
		REQUIRE(misting.get_distance_of_walk() == 13);
		REQUIRE(misting.get_cost() == 110);
	}
}

TEST_CASE("soldier, constructor with initialisation", "[soldier]") {
	
	SECTION("without argument") {
		Soldier soldier(100, 10, 9, 8, 7, 600, String("test_soldier_1"), String("test_soldier_1"));
		REQUIRE(soldier.get_name().toAnsiString() == "test_soldier_1");
		REQUIRE(soldier.get_hp() == 100);
		REQUIRE(soldier.get_force() == 10);
		REQUIRE(soldier.get_distant_force() == 9);
		REQUIRE(soldier.get_accuracy_of_shooting() == 8);
		REQUIRE(soldier.get_distance_of_walk() == 7);
		REQUIRE(soldier.get_cost() == 600);

	}

	SECTION("from file") {
		Soldier soldier;
		soldier.read_data_from_file("test_soldier_1");
		REQUIRE(soldier.get_name().toAnsiString() == "test_soldier_1");
		REQUIRE(soldier.get_hp() == 100);
		REQUIRE(soldier.get_force() == 10);
		REQUIRE(soldier.get_distant_force() == 11);
		REQUIRE(soldier.get_accuracy_of_shooting() == 12);
		REQUIRE(soldier.get_distance_of_walk() == 13);
		REQUIRE(soldier.get_cost() == 90);
	}
}

TEST_CASE("metal, constructor with initialisation", "[metal]") {
	
	SECTION("without argument") {
		Metal metal(100, 10, 9, 8, 7, 600, String("test_metal_1"), String("test_metal_1"));
		REQUIRE(metal.get_name().toAnsiString() == "test_metal_1");
		REQUIRE(metal.get_action_time() == 100);
		REQUIRE(metal.get_allomantic_power().get_force() == 10);
    		REQUIRE(metal.get_allomantic_power().get_distant_force() == 9);
    		REQUIRE(metal.get_allomantic_power().get_accuracy_of_shooting() == 8);
		REQUIRE(metal.get_allomantic_power().get_distance_of_walk() == 7);
		REQUIRE(metal.get_cost() == 600);

	}

	SECTION("from file") {
		Metal metal;
		metal.read_data_from_file("test_metal_1");
		REQUIRE(metal.get_name().toAnsiString() == "test_metal_1");
		REQUIRE(metal.get_action_time() == 3);
		REQUIRE(metal.get_allomantic_power().get_force() == 10);
    		REQUIRE(metal.get_allomantic_power().get_distant_force() == 11);
    		REQUIRE(metal.get_allomantic_power().get_accuracy_of_shooting() == 12);
		REQUIRE(metal.get_allomantic_power().get_distance_of_walk() == 13);
		REQUIRE(metal.get_cost() == 200);
	}
}

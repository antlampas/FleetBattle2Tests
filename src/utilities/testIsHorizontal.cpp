#include "catch2/catch_test_macros.hpp"

#include "utilities.hpp"

using namespace fleetBattle;

std::vector<ShipPosition> ships1    {   ShipPosition({0,0},{0,1}),
                                        ShipPosition({0,0},{0,3}),
                                        ShipPosition({2,2},{3,5}),
                                        ShipPosition({1,1},{3,3}),
                                        ShipPosition({1,1},{3,1}),
                                        ShipPosition({2,1},{5,1})
                                    };

TEST_CASE("Ship is horizontal","[testIsHorizontal]")
{
    REQUIRE(isHorizontal(ships1.at(0)) == true);
    REQUIRE(isHorizontal(ships1.at(1)) == true);
    REQUIRE(isHorizontal(ships1.at(2)) == false);
    REQUIRE(isHorizontal(ships1.at(3)) == false);
    REQUIRE(isHorizontal(ships1.at(4)) == false);
    REQUIRE(isHorizontal(ships1.at(5)) == false);
}
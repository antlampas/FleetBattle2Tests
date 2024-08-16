#include "catch2/catch_test_macros.hpp"

#include "utilities.hpp"

using namespace fleetBattle;

std::vector<ShipPosition> ships2    {   ShipPosition({0,0},{3,0}),
                                        ShipPosition({0,0},{5,0}),
                                        ShipPosition({2,2},{3,5}),
                                        ShipPosition({1,1},{3,3}),
                                        ShipPosition({1,0},{1,5}),
                                        ShipPosition({1,0},{1,7})
                                    };

TEST_CASE("Ship is horizontal","[testIsVertical]")
{
    CHECK(isVertical(ships2.at(0)) == true);
    CHECK(isVertical(ships2.at(1)) == true);
    CHECK(isVertical(ships2.at(2)) == false);
    CHECK(isVertical(ships2.at(3)) == false);
    CHECK(isVertical(ships2.at(4)) == false);
    CHECK(isVertical(ships2.at(5)) == false);
}
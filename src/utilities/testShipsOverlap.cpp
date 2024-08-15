#include "catch2/catch_test_macros.hpp"

#include "utilities.hpp"

using namespace fleetBattle;

std::vector<ShipPosition> ships3    {   ShipPosition({0,0},{3,0}),
                                        ShipPosition({0,0},{5,0}),
                                        ShipPosition({2,2},{2,5}),
                                        ShipPosition({3,1},{5,1}),
                                        ShipPosition({1,0},{1,5}),
                                        ShipPosition({1,0},{1,7})
                                    };


TEST_CASE("Ships are overlapping","testShipsOverlap")
{
    REQUIRE(shipsOverlap(ships3.at(0),ships3.at(1)) == true);
    REQUIRE(shipsOverlap(ships3.at(0),ships3.at(2)) == false);
    REQUIRE(shipsOverlap(ships3.at(4),ships3.at(3)) == false);
}
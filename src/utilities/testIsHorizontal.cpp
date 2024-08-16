#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "utilities.hpp"

using namespace fleetBattle;

std::vector<ShipPosition> ships1    {   ShipPosition({0,0},{0,1}), //True
                                        ShipPosition({0,0},{0,3}), //True
                                        ShipPosition({2,2},{3,5}), //False
                                        ShipPosition({1,1},{3,3}), //False
                                        ShipPosition({1,1},{3,1}), //False
                                        ShipPosition({2,1},{5,1})  //False
                                    };

TEST_CASE("Ship is horizontal","[testIsHorizontal][!benchmark]")
{
    auto ship = ships1.begin();
    for(int i=0;i<2;i++,ship++)
    {
        CHECK(isHorizontal(*ship) == true);
        BENCHMARK("Check ship is vertical")
        {
            return isHorizontal(*ship);
        };
    }
    for(int i=0;ship!=ships1.end();i++,ship++)
    {
        CHECK(isHorizontal(*ship) == false);
        BENCHMARK("Check ship is vertical")
        {
            return isHorizontal(*ship);
        };
    }
}
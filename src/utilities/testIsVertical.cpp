#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "utilities.hpp"

using namespace fleetBattle;

std::vector<ShipPosition> ships2    {   ShipPosition({0,0},{3,0}), //True
                                        ShipPosition({0,0},{5,0}), //True
                                        ShipPosition({2,2},{3,5}), //False
                                        ShipPosition({1,1},{3,3}), //False
                                        ShipPosition({1,0},{1,5}), //False
                                        ShipPosition({1,0},{1,7})  //False
                                    };

TEST_CASE("Ship is vertical","[testIsVertical]")
{
    auto ship = ships2.begin();
    for(int i=0;i<2;i++,ship++)
    {
        CHECK(isVertical(*ship) == true);
    }
    for(int i=0;ship!=ships2.end();i++,ship++)
    {
        CHECK(isVertical(*ship) == false);
    }
}

TEST_CASE("Ship is vertical","[!benchmark]")
{
    auto ship = ships2.begin();
    for(int i=0;i<2;i++,ship++)
    {
        BENCHMARK("Check ship is vertical")
        {
            return isVertical(*ship);
        };
    }
    for(int i=0;ship!=ships2.end();i++,ship++)
    {
        BENCHMARK("Check ship is vertical")
        {
            return isVertical(*ship);
        };
    }
}
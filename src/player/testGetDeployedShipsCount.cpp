#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "player.hpp"

using namespace fleetBattle;

TEST_CASE("Get deployed ships count","[testGetDeployedShipsCount]")
{
    std::vector<ShipPosition> ships {   ShipPosition{{0,0},{0,1}}, //size 2
                                        ShipPosition{{1,4},{3,4}}, //size 3
                                        ShipPosition{{9,5},{9,8}}, //size 4
                                        ShipPosition{{0,1},{0,5}}, //size 5
                                        ShipPosition{{3,6},{8,6}}  //size 6
                                    };
    player p{ships};

    CHECK(p.getDeployedShipsCount() == 5);
}

TEST_CASE("Get deployed ships count benchmark","[!benchmark]")
{
    BENCHMARK("Get deployed ships count")
    {

    };
}
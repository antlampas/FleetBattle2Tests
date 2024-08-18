#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "player.hpp"

using namespace fleetBattle;

TEST_CASE("Check shoot","[testCheckShoot]")
{
    std::vector<ShipPosition> ships {   ShipPosition{{0,0},{0,1}}, //size 2
                                        ShipPosition{{1,4},{3,4}}, //size 3
                                        ShipPosition{{9,5},{9,8}}, //size 4
                                        ShipPosition{{0,1},{0,5}}, //size 5
                                        ShipPosition{{3,6},{8,6}}  //size 6
                                    };
    BoardType board{makeBoardFromShipsList(ships)};

    player playerA{ships};

    CHECK(playerA.checkShoot(std::make_pair(0,0)) == SquareStatus::SHIP_HIT);
    CHECK(playerA.checkShoot(std::make_pair(0,1)) == SquareStatus::SHIP_HIT);
    CHECK(playerA.checkShoot(std::make_pair(0,2)) == SquareStatus::WATER_HIT);
}

TEST_CASE("Check shoot benchmark","[!benchmark]")
{
    std::vector<ShipPosition> ships {   ShipPosition{{0,0},{0,1}}, //size 2
                                        ShipPosition{{1,4},{3,4}}, //size 3
                                        ShipPosition{{9,5},{9,8}}, //size 4
                                        ShipPosition{{0,1},{0,5}}, //size 5
                                        ShipPosition{{3,6},{8,6}}  //size 6
                                    };
    BoardType board{makeBoardFromShipsList(ships)};

    player playerA{ships};

    BENCHMARK("Check shoot")
    {
        return playerA.checkShoot(std::make_pair(0,0));
    };
    BENCHMARK("Check shoot")
    {
        return playerA.checkShoot(std::make_pair(0,2));
    };
}
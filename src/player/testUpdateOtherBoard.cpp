#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "player.hpp"

using namespace fleetBattle;

TEST_CASE("Update other board","[testUpdateOtherBoard]")
{
    std::vector<ShipPosition> ships {   ShipPosition{{0,0},{0,1}}, //size 2
                                        ShipPosition{{1,4},{3,4}}, //size 3
                                        ShipPosition{{9,5},{9,8}}, //size 4
                                        ShipPosition{{0,1},{0,5}}, //size 5
                                        ShipPosition{{3,6},{8,6}}  //size 6
                                    };
    player p{ships};

    CHECK(p.updateOtherBoard(std::make_pair(0,0),'S' == 'S'));
    CHECK(p.updateOtherBoard(std::make_pair(0,1),'S' == 'S'));
    CHECK(p.updateOtherBoard(std::make_pair(0,2),'S' == 'S'));
    CHECK(p.updateOtherBoard(std::make_pair(1,0),'s' == 's'));
    CHECK(p.updateOtherBoard(std::make_pair(1,1),'s' == 's'));
    CHECK(p.updateOtherBoard(std::make_pair(1,2),'s' == 's'));
    CHECK(p.updateOtherBoard(std::make_pair(2,0),'w' == 'w'));
    CHECK(p.updateOtherBoard(std::make_pair(2,1),'w' == 'w'));
    CHECK(p.updateOtherBoard(std::make_pair(2,2),'w' == 'w'));
}

TEST_CASE("Update other board benchmark","[!benchmark]")
{
    BENCHMARK("Update other board")
    {

    };
}
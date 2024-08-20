#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "player.hpp"
#include <ranges>

using namespace fleetBattle;

TEST_CASE("","[]")
{
    std::vector<ShipPosition> ships {   ShipPosition{{0,0},{0,1}}, //size 2
                                        ShipPosition{{1,4},{3,4}}, //size 3
                                        ShipPosition{{9,5},{9,8}}, //size 4
                                        ShipPosition{{0,1},{0,5}}, //size 5
                                        ShipPosition{{3,6},{8,6}}  //size 6
                                    };

    BoardType blankBoard{};
    for(int row: std::ranges::iota_view{0,9})
    {
        blankBoard.push_back(ColumnType());
        for(int column: std::ranges::iota_view{0,9})
            blankBoard.at(row).push_back('W');
    }

    player p{ships};

    CHECK(p.checkOtherBoard() == blankBoard);
}

TEST_CASE("","[!benchmark]")
{
    BENCHMARK("")
    {

    };
}
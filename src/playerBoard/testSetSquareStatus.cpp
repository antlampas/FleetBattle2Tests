#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "playerBoard.hpp"

using namespace fleetBattle;

TEST_CASE("Set square status","[testSetSquareStatus]")
{
    playerBoard board1{};

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            CHECK(board1.setSquareStatus(DecodedCoordinates(row,column),'S') == 'S');
        }
    }
}

TEST_CASE("Set square status benchmark","[!benchmark]")
{
    playerBoard board1{};

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            BENCHMARK("Set square status")
            {
                return board1.setSquareStatus(DecodedCoordinates(row,column),'S');
            };
        }
    }
}
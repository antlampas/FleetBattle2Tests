#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "opponentBoard.hpp"

using namespace fleetBattle;

TEST_CASE("Get square status", "[testGetSquareStatus]")
{
    BoardType blankBoard {};

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        blankBoard.push_back(ColumnType());
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            blankBoard.at(row).push_back('W');
        }
    }

    fleetBattle::opponentBoard board;

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            CHECK(board.getSquareStatus(DecodedCoordinates(row,column)) == 'W');
        }
    }
}

TEST_CASE("Get square status benchmark","[!benchmark]")
{
    BoardType blankBoard {};

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        blankBoard.push_back(ColumnType());
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            blankBoard.at(row).push_back('W');
        }
    }

    fleetBattle::opponentBoard board;

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            BENCHMARK("Get square status")
            {
                return board.getSquareStatus(DecodedCoordinates(row,column)) == 'W';
            };
        }
    }
    
}
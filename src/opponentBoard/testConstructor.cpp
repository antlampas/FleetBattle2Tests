#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "opponentBoard.hpp"

using namespace fleetBattle;

TEST_CASE("Opponent board construction", "[testOpponentBoardConstructor]")
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

    CHECK(board.getBoardStatus() == blankBoard);
}

TEST_CASE("Opponent board construction benchmark","[!benchmark]")
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

    BENCHMARK("Opponent board constructor")
    {
        return board.getBoardStatus() == blankBoard;
    };
}
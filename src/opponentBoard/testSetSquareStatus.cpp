#include "catch2/catch_test_macros.hpp"

#include "opponentBoard.hpp"

using namespace fleetBattle;

TEST_CASE("Set Square status", "[testSetSquareStatus]")
{

    fleetBattle::opponentBoard board;

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            board.setSquareStatus(std::pair<int,int>(row,column),'S');
            CHECK(board.getSquareStatus(std::pair<int,int>(row,column)) == 'S');
        }
    }
}
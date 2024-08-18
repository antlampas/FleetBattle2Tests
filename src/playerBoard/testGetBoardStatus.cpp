#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "playerBoard.hpp"

using namespace fleetBattle;

TEST_CASE("Get board status","[testGetBoardStatus]")
{
    std::vector<ShipPosition> ships {   ShipPosition{{0,0},{0,1}},
                                        ShipPosition{{0,1},{0,6}},
                                        ShipPosition{{9,5},{9,8}},
                                        ShipPosition{{1,4},{3,4}},
                                        ShipPosition{{3,6},{8,6}}
                                    };
    
    BoardType whiteBoard{};
    BoardType board{};

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        whiteBoard.push_back(ColumnType());
        board.push_back(ColumnType());
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            whiteBoard.at(row).push_back('W');
            board.at(row).push_back('W');
        }
    }

    for(auto ship: ships)
        for(int row=ship.first.first;row<=ship.second.first;row++)
            for(int column=ship.first.second;column<=ship.second.second;column++)
                board.at(row).at(column) = 'S';

    playerBoard board1{};
    playerBoard board2{ships};

    CHECK(board1.getBoardStatus() == whiteBoard);
    CHECK(board2.getBoardStatus() == board);
}

TEST_CASE("Get board status benchmark","[!benchmark]")
{
    std::vector<ShipPosition> ships {   ShipPosition{{0,0},{0,1}},
                                        ShipPosition{{0,1},{0,6}},
                                        ShipPosition{{9,5},{9,8}},
                                        ShipPosition{{1,4},{3,4}},
                                        ShipPosition{{3,6},{8,6}}
                                    };
    
    BoardType whiteBoard{};
    BoardType board{};

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        whiteBoard.push_back(ColumnType());
        board.push_back(ColumnType());
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            whiteBoard.at(row).push_back('W');
            board.at(row).push_back('W');
        }
    }

    for(auto ship: ships)
        for(int row=ship.first.first;row<=ship.second.first;row++)
            for(int column=ship.first.second;column<=ship.second.second;column++)
                board.at(row).at(column) = 'S';

    playerBoard board1{};
    playerBoard board2{ships};

    BENCHMARK("Get board status")
    {
        return board1.getBoardStatus();       
    };
     BENCHMARK("Get board status")
    {
        return board2.getBoardStatus();       
    };
}
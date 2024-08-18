#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "playerBoard.hpp"

using namespace fleetBattle;

TEST_CASE("Get square status","[testGetSquareStatus]")
{
    std::vector<ShipPosition> ships {   ShipPosition{{0,0},{0,1}},
                                        ShipPosition{{0,1},{0,6}},
                                        ShipPosition{{9,5},{9,8}},
                                        ShipPosition{{1,4},{3,4}},
                                        ShipPosition{{3,6},{8,6}}
                                    }
    
    BoardType whiteBoard{};
    BoardType board{};

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        whiteBoard.push_back(ColumnType());
        board.push_back(ColumnType());
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            whiteBoard.at(row).push_back('W');
            board.at(row).push_back('W')
        }
    }

    for(auto ship: ships)
        for(int row=ship.first.first;row<=ship.second.first;row++)
            for(int column=ship.first.second;column>=ship.second.second;column++)
                board.at(row).at(column) = 'S';

    playerBoard board1{};
    playerBoard board2{ships};

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            CHECK(board1.getSquareStatus(DecodedCoordinates(row,column)) == 'W');
        }
    }
}

TEST_CASE("Get square status benchmark","[!benchmark]")
{
    std::vector<ShipPosition> ships {   ShipPosition{{0,0},{0,1}},
                                        ShipPosition{{0,1},{0,6}},
                                        ShipPosition{{9,5},{9,8}},
                                        ShipPosition{{1,4},{3,4}},
                                        ShipPosition{{3,6},{8,6}}
                                    }
    
    BoardType whiteBoard{};
    BoardType board{};

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        whiteBoard.push_back(ColumnType());
        board.push_back(ColumnType());
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            whiteBoard.at(row).push_back('W');
            board.at(row).push_back('W')
        }
    }

    for(auto ship: ships)
        for(int row=ship.first.first;row<=ship.second.first;row++)
            for(int column=ship.first.second;column>=ship.second.second;column++)
                board.at(row).at(column) = 'S';

    playerBoard board1{};
    playerBoard board2{ships};

    for(int row: {0,1,2,3,4,5,6,7,8,9})
    {
        for(int column: {0,1,2,3,4,5,6,7,8,9})
        {
            BENCHMARK("Get square status")
            {
                return board1.getSquareStatus(DecodedCoordinates(row,column));
            };
        }
    }
}
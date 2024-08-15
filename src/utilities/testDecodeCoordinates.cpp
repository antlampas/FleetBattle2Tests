#include "catch2/catch_test_macros.hpp"

#include "utilities.hpp"

using namespace fleetBattle;

TEST_CASE("Decode coordinates", "[decodeCoordinates]"){
    for(char column: {'a','b','c','d','e','f','g','h','i','j'})
    {
        for(int row: {1,2,3,4,5,6,7,8,9,10})
        {
            REQUIRE(decodeCoordinates(std::string(1,column)+std::to_string(row)) == DecodedCoordinates{static_cast<int>(column)-97,row});
        }
    }

    for(char column: {'A','B','C','D','E','F','G','H','I','J'})
    {
        for(int row: {1,2,3,4,5,6,7,8,9,10})
        {
            REQUIRE(decodeCoordinates(std::string(1,column)+std::to_string(row)) == DecodedCoordinates{static_cast<int>(column)-65,row});
        }
    }
}
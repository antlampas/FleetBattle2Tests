#include "catch2/catch_test_macros.hpp"

#include "utilities.hpp"

TEST_CASE("Decode coordinates", "[decodeCoordinates]"){
    for(char column: {'a','b','c','d','e','f','g','h','i','j'})
        for(int row: {1,..,10})
        {
            REQUIRE(decodeCoordinates(std::string(1,column)+std::itos(row)) == decodedCoordinates(static_cast<int>(column)-97,row));
            REQUIRE(decodeCoordinates(std::string(1,column-32)+std::itos(row)) == decodedCoordinates(static_cast<int>(column)-65,row));
        }
}
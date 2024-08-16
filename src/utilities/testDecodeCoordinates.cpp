#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "utilities.hpp"

using namespace fleetBattle;

TEST_CASE("Decode coordinates", "[decodeCoordinates][!benchmark]"){
    for(char column: {'a','b','c','d','e','f','g','h','i','j'})
    {
        for(int row: {1,2,3,4,5,6,7,8,9,10})
        {
            CHECK(decodeCoordinates(std::string(1,column)+std::to_string(row)) == DecodedCoordinates{static_cast<int>(column)-97,row});
            BENCHMARK("Decode Coordinates " + std::string(1,column) + " " + std::to_string(row))
            {
                return decodeCoordinates(std::string(1,column)+std::to_string(row));
            };
        }
    }
    for(char column: {'A','B','C','D','E','F','G','H','I','J'})
    {
        for(int row: {1,2,3,4,5,6,7,8,9,10})
        {
            CHECK(decodeCoordinates(std::string(1,column)+std::to_string(row)) == DecodedCoordinates{static_cast<int>(column)-65,row});
            BENCHMARK("Decode Coordinates " + std::string(1,column) + " " + std::to_string(row))
            {
                return decodeCoordinates(std::string(1,column)+std::to_string(row));
            };
        }
    }
}
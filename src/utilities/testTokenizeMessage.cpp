#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "utilities.hpp"

using namespace fleetBattle;

TEST_CASE("Tokenize message","[testTokenizeMessage]")
{
    std::string               message          {"Message Tokenizer"};
    std::vector<std::string>> tokenizedMessage {"Message","Tokenizer"};

    CHECK(tokenizeMessage(message) == tokenizedMessage);
}
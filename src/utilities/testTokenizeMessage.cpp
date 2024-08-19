#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"

#include "utilities.hpp"

using namespace fleetBattle;

TEST_CASE("Tokenize message","[testTokenizeMessage]")
{
    std::string              message          {"Message Tokenizer"};
    std::vector<std::string> tokenizedMessage {"Message","Tokenizer"};

    CHECK(tokenizeMessage(message) == tokenizedMessage);

    message.clear();
    tokenizedMessage.clear();

    message = "Message Tokenizer again and again";
    tokenizedMessage.push_back("Message");
    tokenizedMessage.push_back("Tokenizer");
    tokenizedMessage.push_back("again");
    tokenizedMessage.push_back("and");
    tokenizedMessage.push_back("again");

    CHECK(tokenizeMessage(message) == tokenizedMessage);
}
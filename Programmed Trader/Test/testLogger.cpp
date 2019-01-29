#include "catch.hpp"
#include "../logger.hpp"

TEST_CASE("Create Logger Dumb Version")
{
    Logger logger;
}

TEST_CASE("Stores input correctly")
{
    Logger logger;
    logger.addLog(true, "aapl", 5, 120.4, "trader said so");
    std::vector<Log> temp = logger.getLogs();
    REQUIRE(temp[0].buy == true);
    REQUIRE(temp[0].company == "aapl");
    REQUIRE(temp[0].amount == 5);
    REQUIRE(temp[0].price == 120.4);
    REQUIRE(temp[0].reason == "trader said so");
}

TEST_CASE("Outputs to a file with local path")
{
    Logger logger;
    logger.addLog(true, "aapl", 5, 120.4, "trader said so");
    logger.addLog(true, "msft", 12, 150.2, "seemed like a good idea");
    logger.addLog(false, "amzn", 3, 1203.4, "Amazon is a good company");
    logger.printLogs("test.txt", 100);
}


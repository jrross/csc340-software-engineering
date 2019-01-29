#include "catch.hpp"
#include "../analyst.hpp"
#include "../include/Trader.h"

TEST_CASE("Create analyst")
{
    Trader trader("test_account");
    Analyst analyst(trader);
}

TEST_CASE("Retrieves available positions correctly")
{
    Trader trader("test_account");
    Analyst analyst(trader);
    
    for(auto x: analyst.availablePositions)
    {
        REQUIRE(x.symbol == "amzn");
        
        for (unsigned int i = 0; i < x.h_high.size(); i++)
        {
            REQUIRE(x.h_high[i] == (double)i);
            REQUIRE(x.h_low[i] == (double)i);
            REQUIRE(x.h_start[i] == (double)i);
            REQUIRE(x.h_end[i] == (double)i);
            REQUIRE(x.h_volume[i] == i);
        }
    }
}

TEST_CASE("Retrieves open positions correctly")
{
    Trader trader("test_account");
    Analyst analyst(trader);
    
    for(auto x: analyst.openPositions)
    {
        REQUIRE(x.symbol == "aapl");
        REQUIRE(x.buyPrice == 12.50);
        REQUIRE(x.count == 5);
        REQUIRE(x.dayOfPurchase == 2);
        REQUIRE(x.monthOfPurchase == 7);
        REQUIRE(x.yearOfPurchase == 2016);
        REQUIRE(x.type == 0);
        REQUIRE(x.sellPrice == 0);
    }
}

TEST_CASE("Retrieves symbols correctly")
{
    Trader trader("test_account");
    Analyst analyst(trader);
    
    for(auto x: analyst.symbols)
    {
        REQUIRE(x == "amzn");
    }
}

TEST_CASE("Retrieves current prices correctly")
{
    Trader trader("test_account");
    Analyst analyst(trader);
    map<string, double> currentPrices = analyst.getCurrentPrices();
    
    for(auto x: analyst.symbols)
    {
        REQUIRE(currentPrices[x] == 0.0);
    }
}

TEST_CASE("Calculates average accurately")
{
    Trader trader("test_account");
    Analyst analyst(trader);
    map<string, double> averages = analyst.getAverages(10);
    
    for(auto x: analyst.symbols)
    {
        REQUIRE(averages[x] == 4.5);
    }
}

TEST_CASE("Calculates moving averages accurately")
{
    Trader trader("test_account");
    Analyst analyst(trader);
    int data = 1;
    
    map<string, vector<double>> movAverages = analyst.getMovingAverages(3, 10);
    
    //only for test data set
    REQUIRE(movAverages["amzn"].size() == 8);
    
    for(auto x: analyst.symbols)
    {   
        for(auto y: movAverages[x])
        {
            //only for test data set
            REQUIRE(y == data);
            data++;
        }
    }
}

TEST_CASE("Calculates correct number of stocks to purchase")
{
    Trader trader("test_account");
    Analyst analyst(trader);
    
    REQUIRE(analyst.numToPurchase(5.56, trader.getAccountCash(), 0.02) == 359);
}

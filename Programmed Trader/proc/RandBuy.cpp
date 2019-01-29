#include "../procedure.hpp"

void procedure(Trader trader)
{
    Analyst analyst(trader);
    Logger logger;
    
    map<string, double> current = analyst.getCurrentPrices();
    
    srand(time(NULL));

    for (auto x: analyst.symbols)
    {
        if ((rand() % 2)+1 == 2)
        {
            if (!trader.buy(x, 1))
                logger.addLog(true, x, 1, trader.getStockPrice(x),
                    "Random purchase");
        }
    }
    
    if (trader.getAccountCash() < 1000.00)
    {
        for (auto x: analyst.openPositions)
        {
            if ((rand() % 2)+1 == 2)
            {
                if (!trader.sell(x, 1))
                    logger.addLog(false, x.symbol, 1, trader.getStockPrice(x.symbol),
                    "Random sale");
            }
        }
    }
    
    //calculate account value
    double value = 0;
    for (auto x: analyst.getOpenPositions)
    {
        value += current[x.symbol] * x.count;
    }
    
    value += trader.getAccountCash();
    
    logger.printLogs("TradingLog.txt", value);
    
    return;
}

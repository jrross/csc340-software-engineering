#include "../procedure.hpp"

struct holder
{
    double diff;
    std::string stock;
};

bool compare(holder left, holder right)
{
    return right.diff < left.diff;
}

void procedure(Trader trader)
{
    Analyst analyst(trader);
    Logger logger;
    
    //get current end of day prices
    map<string, double> curr = analyst.getCurrentPrices();
    
    //get 20 day averages
    map<string, double> avg20 = analyst.getAverages(20);
    
    vector<holder> toPurchase;
    
    //sell any owned stock whose current price is 2% lower than 20 day average   
    for (auto x: analyst.openPositions)
    {
        if(curr[x.symbol] != 0.0 && curr[x.symbol] != 1.0)
        {
            if ( (curr[x.symbol] - avg20[x.symbol]) < (curr[x.symbol] * 0.02) )
            {
                trader.sell(x, x.count);
                logger.addLog(false, x.symbol, x.count, trader.getStockPrice(x.symbol),
                    "current price 2% lower than 20 day average");
            }
        }
    }

    //place any stock whose current price is 10% higher than 20 day average on 
    //toPurchase list
    for (auto x: analyst.symbols)
    {
        if( curr[x] != 0.0 && curr[x] != 1.0)
        {
            if ( (curr[x] - avg20[x]) > (curr[x] * 0.10) )
            {
                holder temp;
                temp.diff = (curr[x] - avg20[x]);
                temp.stock = x;
                toPurchase.push_back(temp);
            }
        }
    }
    
    //sort toPurchase
    std::sort(toPurchase.begin(), toPurchase.end(), compare);
    
    //buy best to worst
    for(unsigned int i = 0; i < toPurchase.size(); i++)
    {
        int count = analyst.numToPurchase(trader.getStockPrice(toPurchase[i].stock),
                                trader.getAccountCash(), 0.03);
                                
        if (!trader.buy(toPurchase[i].stock, count))
            logger.addLog(true, toPurchase[i].stock, count, curr[toPurchase[i].stock],
                "current price is 10% higher than 20 day average");
    }
    
    //calculate account value
    double value = 0;
    for (auto x: analyst.openPositions)
    {
        value += curr[x.symbol] * x.count;
    }
    
    value += trader.getAccountCash();
    
    logger.printLogs("TradingLog.txt", value);
    
    return;
}

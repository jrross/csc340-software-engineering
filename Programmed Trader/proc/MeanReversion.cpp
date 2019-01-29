#include "../procedure.hpp"
//THIS ALGORITHM GOES THROUGH AND CHECKS IF ANY STOCKS ARE BELOW THE AVERAGE OF
//THE LAST 60 DAYS BY 7%, IF SO, THE TRADER BUYS THEM UNDER THE PREMISE THAT ALL
//STOCKS WILL RETURN TO AVERAGE. VICE VERSA IS DONE FOR SELLING STOCKS.
struct holder
{
    double percent;
    std::string stock;
};

bool compare(holder left, holder right)
{
    return left.percent < right.percent;
}

void procedure(Trader trader)
{   //values that can be changed to modify how the procedure operates
    int days = 60;
    double percent = 7.0;
    
    Analyst analyst(trader);
    Logger logger;
    
    //get current end of day prices
    map<string, double> curr = analyst.getCurrentPrices();
    
    //get average for past (days) days
    map<string, double> avg = analyst.getAverages(days);

    vector<holder> list;

    //sell any owned stock in which it is above a specified percentage  
    for (auto x: analyst.openPositions)
    {
        if(curr[x.symbol] != 0.0 && curr[x.symbol] != 1.0)
        {
            double diff = ((curr[x.symbol] - avg[x.symbol])/avg[x.symbol])*100;
            if (diff > percent)
            {
                trader.sell(x, x.count);
                logger.addLog(false, x.symbol, x.count, curr[x.symbol],
                    std::to_string(diff) + " percent increase.");
            }
        }
    }
    
    for (auto x: analyst.symbols)
    {
        if(curr[x] != 0.0 && curr[x] != 1.0)
        {
            double diff = ((curr[x] - avg[x])/avg[x])*100;
            if (diff < 0 - percent)
            {   //if meets criteria, add to list
                holder temp;
                temp.percent = diff;
                temp.stock = x;
                list.push_back(temp);
            }
        }
    }

    //sort the percentages
    std::sort(list.begin(),list.end(),compare);
    
    //go from highest percent to least, buying any that have enough funds for
    for(unsigned int i = 0; i < list.size(); i++)
    {
        int count = analyst.numToPurchase(trader.getStockPrice(list[i].stock),
                                trader.getAccountCash(), 0.05);
                                
        if (!trader.buy(list[i].stock, count))
            logger.addLog(true, list[i].stock, count, curr[list[i].stock],
                std::to_string(list[i].percent) + " percent decrease.");
    }

    //calculate account value
    analyst.updatePortfolio(trader);
    double value = 0;
    for (auto x: analyst.openPositions)
    {
        value += curr[x.symbol] * x.count;
    }
    
    value += trader.getAccountCash();
    
    logger.printLogs("TradingLog.txt", value);
    
    return;
}

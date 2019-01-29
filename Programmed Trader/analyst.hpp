#ifndef _ANALYST_H
#define _ANALYST_H

#include "include/Trader.h"

class Analyst
{
private:

public:
    vector<Stock> availablePositions;
    vector<OpenPosition> openPositions;
    vector<string> symbols;

    //Constructor
    Analyst(Trader);
    
    map<string, double> getAverages(int);
    map<string, vector<double>> getMovingAverages(unsigned int, int);
    map<string, double> getCurrentPrices();
    int numToPurchase(double, double, double);
    void updatePortfolio(Trader trader);
};

#endif

#include <iostream>

#include "include/Trader.h"
#include "procedure.hpp"
#include "analyst.hpp"

int main()
{
    Trader trader("DarthTrader");
    
    procedure(trader);
    return 0;
}

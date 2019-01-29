#!/bin/bash

>./data/StockFile.txt

for symbol in $(cat stockSymbols)
do
    range=$(grep -A59 $1 ./data/RawStockData/$symbol.dat | cut -d ":" -f-5,7-)
    
    echo $symbol{ >> ./data/StockFile.txt
    echo "$range" >> ./data/StockFile.txt
    echo } >> ./data/StockFile.txt
    
done

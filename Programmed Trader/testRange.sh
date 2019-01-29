#!/bin/bash

month=$1
day=$2
year=$3
range=$4

count=0

make main PROC=$5

while [ "$count" != "$range" ]
do
    date="$month/$day/$year"
    echo $date
    if grep -q $date ./data/RawStockData/ibm.dat; then

        ./data/getRange.sh $date
        ./data/format.sh
        make runMain
        
        count=$((count+1))
    fi
    
    if [ "$day" -eq "31" ]
    then
        day="01"
        if [ "$month" -eq "12" ]
        then
            month="01"
            year=$((year+1))
        else
            month=$((10#$month+1))
            month=`printf %02d $month`
        fi
    else
        day=$((10#$day+1))
        day=`printf %02d $day`
    fi
done

#!/bin/bash

sed -i '/^[0-9]/ s/$/;/' ./data/StockFile.txt

sed -i '/^[0-9]/ s/^/\t/' ./data/StockFile.txt

sed -i 's/-/0/' ./data/StockFile.txt

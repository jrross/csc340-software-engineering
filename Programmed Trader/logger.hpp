#ifndef _LOGGER_H
#define _LOGGER_H

#include <vector>
#include <fstream>
#include <string>

struct Log
{
    bool buy;
    std::string company;
    int amount;
    double price;
    std::string reason;
};

class Logger
{
    public:
    std::vector<Log> getLogs();
    void printLogs(std::string, double);
    void addLog(bool,std::string,int,double,std::string);

    private:
    std::vector<Log> logs;
};

#endif

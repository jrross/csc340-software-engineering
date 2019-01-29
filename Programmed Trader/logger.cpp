#include "logger.hpp"

std::vector<Log> Logger::getLogs()
{
    return logs;
}

void Logger::printLogs(std::string path, double accountValue)
{
    std::ofstream file;
    file.open(path, std::ios_base::app);
    
    file << "\nStart of log" << std::endl;
    
    for (unsigned int i = 0; i < logs.size(); i++)
    {
        if(logs[i].buy)
            file << "bought ";
        else
            file << "sold ";
        file << logs[i].amount << " shares of " << logs[i].company << " at $"
            << logs[i].price << " because " << logs[i].reason << "\n";
    }
    
    file << "Account Value: " << accountValue;
    file.close();
}

void Logger::addLog(bool b,std::string c,int a, double p,std::string r)
{
    for(unsigned int i = 0; i < logs.size(); i++)
    {
        if(logs[i].company == c)
        {
            logs[i].amount = logs[i].amount + a;
            return;
        }
    }
    Log tempLog;
    tempLog.buy = b;
    tempLog.company = c;
    tempLog.amount = a;
    tempLog.price = p;
    tempLog.reason = r;
    logs.push_back(tempLog);
}

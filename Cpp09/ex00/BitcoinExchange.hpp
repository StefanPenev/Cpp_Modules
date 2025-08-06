#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& dbFile);
    void processInput(const std::string& inputFile) const;

private:
    std::map<std::string, double> _db;

    static bool isValidDate(const std::string& date);
    static bool isValidValue(const std::string& valueStr, double& value);
    static std::string trim(const std::string& s);
    double getRateForDate(const std::string& date) const;
};

#endif
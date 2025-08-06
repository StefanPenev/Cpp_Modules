#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <limits>

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    std::ifstream db(dbFile.c_str());
    if (!db) throw std::runtime_error("Error: could not open file.");
    std::string line;
    std::getline(db, line);
    while (std::getline(db, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr))
            continue;
        date = trim(date);
        valueStr = trim(valueStr);
        double value = 0.0;
        std::istringstream valss(valueStr);
        valss >> value;
        if (!valss || !valss.eof())
            continue;
        _db[date] = value;
    }
}

void BitcoinExchange::processInput(const std::string& inputFile) const {
    std::ifstream in(inputFile.c_str());
    if (!in) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(in, line);
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (!std::getline(iss, date, '|')) {
            std::cerr << "Error: bad input => " << trim(line) << std::endl;
            continue;
        }
        valueStr = "";
        std::getline(iss, valueStr);
        date = trim(date);
        valueStr = trim(valueStr);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        double value;
        if (!isValidValue(valueStr, value)) {
            if (valueStr.empty())
                std::cerr << "Error: bad input => " << line << std::endl;
            else if (value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else if (value > 1000)
                std::cerr << "Error: too large a number." << std::endl;
            else
                std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        double rate = getRateForDate(date);
        std::cout << date << " => " << valueStr << " = " << value * rate << std::endl;
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int year = 0, month = 0, day = 0;
    for (int i = 0; i < 4; ++i) {
        if (!std::isdigit(date[i])) return false;
        year = year * 10 + (date[i] - '0');
    }
    for (int i = 5; i < 7; ++i) {
        if (!std::isdigit(date[i])) return false;
        month = month * 10 + (date[i] - '0');
    }
    for (int i = 8; i < 10; ++i) {
        if (!std::isdigit(date[i])) return false;
        day = day * 10 + (date[i] - '0');
    }
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) {
    if (valueStr.empty())
        return false;
    std::istringstream iss(valueStr);
    iss >> value;
    if (!iss || !iss.eof())
        return false;
    if (value < 0)
        return false;
    if (value > 1000)
        return false;
    return true;
}

std::string BitcoinExchange::trim(const std::string& s) {
    size_t start = 0;
    while (start < s.length() && std::isspace(s[start]))
        ++start;
    size_t end = s.length();
    while (end > start && std::isspace(s[end - 1]))
        --end;
    return s.substr(start, end - start);
}

double BitcoinExchange::getRateForDate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = _db.lower_bound(date);
    if (it != _db.end() && it->first == date)
        return it->second;
    if (it == _db.begin())
        return 0.0;
    --it;
    return it->second;
}
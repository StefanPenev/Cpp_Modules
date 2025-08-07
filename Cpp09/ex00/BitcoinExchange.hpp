/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenev <spenev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:33:06 by spenev            #+#    #+#             */
/*   Updated: 2025/08/07 11:33:07 by spenev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
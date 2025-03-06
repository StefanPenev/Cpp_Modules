/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefan <stefan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:13:21 by stefan            #+#    #+#             */
/*   Updated: 2025/02/28 20:19:42 by stefan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

// Initialize static members
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Helper function to display timestamps in log format
void Account::_displayTimestamp() {
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);
    std::cout << "[" 
              << 1900 + ltm->tm_year
              << ((ltm->tm_mon < 9) ? "0" : "") << 1 + ltm->tm_mon
              << ((ltm->tm_mday < 10) ? "0" : "") << ltm->tm_mday << "_"
              << ((ltm->tm_hour < 10) ? "0" : "") << ltm->tm_hour
              << ((ltm->tm_min < 10) ? "0" : "") << ltm->tm_min
              << ((ltm->tm_sec < 10) ? "0" : "") << ltm->tm_sec
              << "] ";
}

// Constructor: Initializes a new account
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

// Destructor: Closes the account
Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

// Get total number of accounts
int Account::getNbAccounts() {
    return _nbAccounts;
}

// Get total amount across all accounts
int Account::getTotalAmount() {
    return _totalAmount;
}

// Get total number of deposits made
int Account::getNbDeposits() {
    return _totalNbDeposits;
}

// Get total number of withdrawals made
int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

// Displays summary of all accounts
void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

// Deposit money into the account
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

// Withdraw money from the account
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:";

    if (_amount < withdrawal) {
        std::cout << "refused" << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    
    return true;
}

// Check current amount in account
int Account::checkAmount() const {
    return _amount;
}

// Display status of a specific account
void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}



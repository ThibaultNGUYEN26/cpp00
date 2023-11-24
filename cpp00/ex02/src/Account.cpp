/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:01:01 by thibault          #+#    #+#             */
/*   Updated: 2023/11/24 15:48:16 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Static variables initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Default constructor
Account::Account() {}

// Function to display the timestamp in the required format
void Account::_displayTimestamp() {
	// Get the current time
	std::time_t currentTime = std::time(NULL);

	// Convert to a local time struct
	std::tm* localTime = std::localtime(&currentTime);

	// Create a character buffer to store the formatted time
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);

	// Output the formatted timestamp
	std::cout << buffer << " ";
}

// Returns the total number of accounts created
int Account::getNbAccounts() {
	return Account::_nbAccounts;
}

// Returns the total amount in all accounts combined
int Account::getTotalAmount() {
	return Account::_totalAmount;
}

// Returns the total number of deposits made across all accounts
int Account::getNbDeposits() {
	return Account::_totalNbDeposits;
}

// Returns the total number of withdrawals made across all accounts
int Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;
}

// Constructor with initial deposit for an Account instance
Account::Account(int initial_deposit) {
	// Initialize account data
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;

	// Display creation timestamp and account details
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->checkAmount() << ";" << "created" << std::endl;
}

// Destructor for an Account instance
Account::~Account() {
	// Display closing timestamp and account details
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->checkAmount() << ";" << "closed" << std::endl;
}

// Function to make a deposit to the account
void Account::makeDeposit(int deposit) {
	// Display timestamp and deposit details
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << this->checkAmount() << ";" << "deposit:" << deposit << ";";
	
	// Update account data
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	// Display updated account details
	std::cout << "amount:" << this->checkAmount() << ";" << "nb_deposits:" << this->_nbDeposits << std::endl;
}

// Function to make a withdrawal from the account
bool Account::makeWithdrawal(int withdrawal) {
	// Display timestamp and withdrawal details
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << this->checkAmount() << ";";
	
	// Check if withdrawal is possible
	if (this->checkAmount() < withdrawal) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	} else {
		// Update account data
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;

		// Display updated account details
		std::cout << "withdrawal:" << withdrawal << ";" << "amount:" << this->checkAmount() << ";" << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
}

// Function to check the amount in the account
int Account::checkAmount() const {
	return this->_amount;
}

// Function to display the current status of the account
void Account::displayStatus() const {
	// Display timestamp and account details
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->checkAmount() << ";" << "deposits:" << this->_nbDeposits << ";" << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// Function to display overall account information
void Account::displayAccountsInfos() {
	// Display timestamp and overall account data
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" << "total:" << getTotalAmount() << ";" << "deposits:" << getNbDeposits() << ";" << "withdrawals:" << getNbWithdrawals() << std::endl;
}

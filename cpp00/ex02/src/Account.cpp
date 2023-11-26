/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:01:01 by thibault          #+#    #+#             */
/*   Updated: 2023/11/26 21:30:56 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

#define BLACK	"\033[1;30m"
#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define WHITE	"\033[1;37m"
#define RED2	"\033[0;31m"
#define GREEN2	"\033[0;32m"
#define BLUE2	"\033[0;34m"
#define EOC		"\033[0;0m"

// Static variables initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Default constructor
Account::Account() {}

// Function to display the timestamp in the required format
void Account::_displayTimestamp() {
	std::time_t currentTime = std::time(NULL);

	std::tm* localTime = std::localtime(&currentTime);

	char buffer[80];
	std::strftime(buffer, sizeof(buffer), YELLOW "[%Y%m%d_%H%M%S]" EOC, localTime);

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
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;

	_displayTimestamp();
	if (this->checkAmount() >= 0) {
		std::cout << WHITE "index:" << this->_accountIndex << EOC ";" << GREEN "amount:" << this->checkAmount() << EOC ";" << CYAN "created" EOC << std::endl;
	} else {
		std::cout << WHITE "index:" << this->_accountIndex << EOC ";" << RED "amount:" << this->checkAmount() << EOC ";" << CYAN "created" EOC << std::endl;
	}
}

// Destructor for an Account instance
Account::~Account() {
	_displayTimestamp();
	if (this->checkAmount() >= 0) {
		std::cout << WHITE "index:" << this->_accountIndex << EOC ";" << GREEN "amount:" << this->checkAmount() << EOC ";" << MAGENTA "closed" EOC << std::endl;
	} else {
		std::cout << WHITE "index:" << this->_accountIndex << EOC ";" << RED "amount:" << this->checkAmount() << EOC ";" << MAGENTA "closed" EOC << std::endl;
	}
}

// Function to make a deposit to the account
void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << WHITE "index:" << this->_accountIndex << EOC ";" << GREEN2 "p_amount:" << this->checkAmount() << EOC ";" << BLUE "deposit:" << deposit << EOC ";";
	
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	
	if (this->checkAmount() >= 0) {
		std::cout << GREEN "amount:" << this->checkAmount() << EOC ";" << BLUE2 "nb_deposits:" << this->_nbDeposits << EOC << std::endl;
	} else {
		std::cout << RED "amount:" << this->checkAmount() << EOC ";" << BLUE2 "nb_deposits:" << this->_nbDeposits << EOC << std::endl;
	}
}

// Function to make a withdrawal from the account
bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << WHITE "index:" << this->_accountIndex << EOC ";" << GREEN2 "p_amount:" << this->checkAmount() << EOC ";";
	
	if (this->checkAmount() < withdrawal) {
		std::cout << RED "withdrawal:refused" EOC << std::endl;
		return false;
	} else {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;

		if (this->checkAmount() >= 0) {
			std::cout << RED "withdrawal:" << withdrawal << EOC ";" << GREEN "amount:" << this->checkAmount() << EOC ";" << RED2 "nb_withdrawals:" << this->_nbWithdrawals << EOC << std::endl;
		} else {
			std::cout << RED "withdrawal:" << withdrawal << EOC ";" << RED "amount:" << this->checkAmount() << EOC ";" << RED2 "nb_withdrawals:" << this->_nbWithdrawals << EOC << std::endl;
		}
		return true;
	}
}

// Function to check the amount in the account
int Account::checkAmount() const {
	return this->_amount;
}

// Function to display the current status of the account
void Account::displayStatus() const {
	_displayTimestamp();
	if (this->checkAmount() >= 0) {
		std::cout << WHITE "index:" << this->_accountIndex << EOC ";" << GREEN "amount:" << this->checkAmount() << EOC ";" << BLUE "deposits:" << this->_nbDeposits << EOC ";" << RED "withdrawals:" << this->_nbWithdrawals << EOC << std::endl;
	} else {
		std::cout << WHITE "index:" << this->_accountIndex << EOC ";" << RED "amount:" << this->checkAmount() << EOC ";" << BLUE "deposits:" << this->_nbDeposits << EOC ";" << RED "withdrawals:" << this->_nbWithdrawals << EOC << std::endl;
	}
}

// Function to display overall account information
void Account::displayAccountsInfos() {
	_displayTimestamp();
	if (getTotalAmount() >= 0) {
		std::cout << WHITE "accounts:" << getNbAccounts() << EOC ";" << GREEN "total:" << getTotalAmount() << EOC ";" << BLUE "deposits:" << getNbDeposits() << EOC ";" << RED "withdrawals:" << getNbWithdrawals() << EOC << std::endl;
	} else {
		std::cout << WHITE "accounts:" << getNbAccounts() << EOC ";" << RED "total:" << getTotalAmount() << EOC ";" << BLUE "deposits:" << getNbDeposits() << EOC ";" << RED "withdrawals:" << getNbWithdrawals() << EOC << std::endl;
	}
}

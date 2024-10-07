/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:45:27 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/26 10:06:23 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";closed" << std::endl;
	Account::_nbAccounts--;
}

void	Account::_displayTimestamp(void)
{
	time_t	now;

	now = time(NULL);
	std::cout << std::put_time(localtime(&now), "[%Y%m%d_%H%M%S] ");
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:" << Account::getNbAccounts() 
				<< ";total:" << Account::getTotalAmount()
				<< ";deposits:" << Account::getNbDeposits() 
				<< ";withdrawals:" << Account::getNbWithdrawals() 
				<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout	<< "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";" << std::flush;
    _amount += deposit;
    std::cout	<< "deposit:" << deposit << ";"
                << "amount:" << _amount << ";"
                << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
    std::cout 	<< "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";"
                << "withdrawal:";
    if (withdrawal > checkAmount()) 
	{
        std::cout << "refused" << std::endl;
        return false;
    }
    this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout	<< withdrawal
				<< ";amount:" << this->checkAmount() - withdrawal 
				<< ";nb_withdrawals:" << this->_nbWithdrawals 
				<< std::endl;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	return (true);
}

int	Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "deposits:" << _nbDeposits << ";"
                << "withdrawals:" << _nbWithdrawals << std::endl;
}

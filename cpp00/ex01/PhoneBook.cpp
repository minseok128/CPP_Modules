/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:47:13 by michang           #+#    #+#             */
/*   Updated: 2024/03/06 21:25:58 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_idx = 0;
}

PhoneBook::~PhoneBook()
{
}

int	PhoneBook::getIdx() const
{
	return (this->_idx);
}

void	PhoneBook::addContact(std::string firstName, std::string lastName, \
	std::string nickname, std::string phoneNumber, std::string secret)
{
	this->_list[_idx].setFirstName(firstName);
	this->_list[_idx].setLastName(lastName);
	this->_list[_idx].setNickname(nickname);
	this->_list[_idx].setPhoneNumber(phoneNumber);
	this->_list[_idx].setSecret(secret);
	_idx = (_idx + 1) % MAXIDX;
}

Contact& PhoneBook::searchContact(long long idx)
{
	if (idx < 0 || idx >= MAXIDX || this->_list[idx].getFirstName().empty())
		throw std::logic_error("index out of range");
	return (this->_list[idx]);
}

void	PhoneBook::printAllContact()
{
	std::cout << "\n     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < MAXIDX; i++)
	{
		if (!this->_list[i].getFirstName().empty())
		{
			std::cout << "         " << i << "|";
			this->_list[i].printShort();
		}
	}
}

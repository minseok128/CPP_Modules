/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:47:13 by michang           #+#    #+#             */
/*   Updated: 2024/03/06 21:45:45 by michang          ###   ########.fr       */
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
	return (_idx);
}

void	PhoneBook::addContact(std::string firstName, std::string lastName, \
	std::string nickname, std::string phoneNumber, std::string secret)
{
	_list[_idx].setFirstName(firstName);
	_list[_idx].setLastName(lastName);
	_list[_idx].setNickname(nickname);
	_list[_idx].setPhoneNumber(phoneNumber);
	_list[_idx].setSecret(secret);
	_idx = (_idx + 1) % MAXIDX;
}

Contact& PhoneBook::searchContact(long long idx)
{
	if (idx < 0 || idx >= MAXIDX || _list[idx].getFirstName().empty())
		throw std::logic_error("index out of range");
	return (_list[idx]);
}

void	PhoneBook::printAllContact()
{
	std::cout << "\n     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < MAXIDX; i++)
	{
		if (!_list[i].getFirstName().empty())
		{
			std::cout << "         " << i << "|";
			_list[i].printShort();
		}
	}
}

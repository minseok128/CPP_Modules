/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:49:09 by michang           #+#    #+#             */
/*   Updated: 2024/03/04 12:59:07 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{	
}

Contact::~Contact()
{
}

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

std::string	Contact::getFirstName()
{
	return (this->_firstName);
}

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

std::string	Contact::getLastName()
{
	return (this->_lastName);
}

void	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

std::string	Contact::getNickname()
{
	return (_nickname);
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumbe = phoneNumber;
}

std::string	Contact::getPhoneNumber()
{
	return (_phoneNumbe);
}

void	Contact::setSecret(std::string secret)
{
	this->_secret = secret;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:49:27 by michang           #+#    #+#             */
/*   Updated: 2024/03/04 15:09:48 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
public:
	Contact();
	~Contact();
	void		setFirstName(std::string firstName);
	void		setLastName(std::string lastName);
	void		setNickname(std::string nickname);
	void		setPhoneNumber(std::string phoneNumber);
	void		setSecret(std::string secret);
	void		printInfo();

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_secret;
};

#endif
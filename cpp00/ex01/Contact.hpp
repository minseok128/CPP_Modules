/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:49:27 by michang           #+#    #+#             */
/*   Updated: 2024/03/04 13:07:33 by michang          ###   ########.fr       */
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
	std::string	getFirstName();
	void		setLastName(std::string lastName);
	std::string	getLastName();
	void		setNickname(std::string nickname);
	std::string	getNickname();
	void		setPhoneNumber(std::string phoneNumber);
	std::string	getPhoneNumber();
	void		setSecret(std::string secret);

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_secret;
};

#endif
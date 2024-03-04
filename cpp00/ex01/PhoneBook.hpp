/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:47:08 by michang           #+#    #+#             */
/*   Updated: 2024/03/04 13:17:08 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include "Contact.hpp"

class PhoneBook
{
public :
	PhoneBook();
	~PhoneBook();
	void	addContact();
	Contact	&searchContact(int index);

private :
	Contact	_list[10];
	int		_next;
};

#endif
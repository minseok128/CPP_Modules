/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:49:27 by michang           #+#    #+#             */
/*   Updated: 2024/03/01 23:00:36 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
public:
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_numbe;
	std::string	secret;
};

#endif
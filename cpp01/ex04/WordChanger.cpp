/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WordChanger.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:31:07 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 18:51:14 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include "WordChanger.hpp"

WordChanger::WordChanger()
	: _totalStr("")
{
}

WordChanger::WordChanger(std::string totalStr)
	: _totalStr(totalStr)
{
}

WordChanger::~WordChanger()
{
}

void	WordChanger::setTotalStr(std::string str)
{
	_totalStr = str;
}

std::string	WordChanger::changeWord(const std::string &s1, const std::string &s2)
{
	std::string::size_type	n;

	if (_totalStr.empty())
		throw (std::string("WordChanger has empty string!"));
	while (1)
	{
		n = _totalStr.find(s1, n);
		if (n == std::string::npos)
			break;
		_totalStr.erase(n, s1.length());
		_totalStr.insert(n, s2);
		n += s2.length();
	}
	return (_totalStr);
}

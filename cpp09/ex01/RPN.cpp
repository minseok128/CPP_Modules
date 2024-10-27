/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:12 by michang           #+#    #+#             */
/*   Updated: 2024/10/27 16:54:32 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN* RPN::_instance = 0;

RPN::RPN() {}

RPN::~RPN() {}

RPN& RPN::getInstance() {
	if (_instance == 0)
		_instance = new RPN();
	return *_instance;
}

void RPN::push(const std::string& token) {
	int a, b;

	if (token.length() != 1)
		throw std::string("Error");
	if (token[0] >= '0' && token[0] <= '9')
		_stack.push(token[0] - '0');
	else if ((token[0] == '+' || token[0] == '-' || token[0] == '*' ||
			  token[0] == '/') &&
			 _stack.size() < 2) {
		a = _stack.top();
		_stack.pop();
		b = _stack.top();
		_stack.pop();
		if (token[0] == '+')
			_stack.push(b + a);
		else if (token[0] == '-')
			_stack.push(b - a);
		else if (token[0] == '*')
			_stack.push(b * a);
		else if (token[0] == '/') {
			if (a == 0)
				throw std::string("Error");
			_stack.push(b / a);
		}
	} else
		throw std::string("Error");
}

int RPN::getResult() {
	if (_stack.size() != 1)
		throw std::string("Error");
	return _stack.top();
}
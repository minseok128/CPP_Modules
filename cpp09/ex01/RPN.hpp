/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:19 by michang           #+#    #+#             */
/*   Updated: 2024/10/27 19:26:34 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <deque>
#include <string>
#include <iostream>
#include <sstream>

class RPN {
  public:
	static RPN& getInstance();
	void push(const std::string& token);
	int getResult();

  private:
	RPN();
	RPN(const RPN& obj);
	~RPN();
	RPN& operator=(const RPN& obj);

	static RPN* _instance;
	std::deque<int> _stack;
};

#endif
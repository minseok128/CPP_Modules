/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:19 by michang           #+#    #+#             */
/*   Updated: 2024/10/27 16:38:49 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>

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
	std::stack<int> _stack;
};

#endif
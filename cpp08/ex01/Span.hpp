/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:04:54 by michang           #+#    #+#             */
/*   Updated: 2024/09/28 21:16:04 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <algorithm>
#include <set>
#include <cstdint>

class Span {
  public:
	Span();
	Span(unsigned int n);
	Span(const Span& copy);
	~Span();
	Span& operator=(const Span& other);
	void addNumber(int n);
	void addNumbers(int min, int max, unsigned int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();

  private:
	unsigned int _n;
	std::multiset<int> _v;
};

#endif
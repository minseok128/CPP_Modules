/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:16:23 by michang           #+#    #+#             */
/*   Updated: 2024/09/28 21:16:31 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int64_t abs_int64(int64_t n) {
	return n < 0 ? -n : n;
}

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& copy) : _n(copy._n), _v(copy._v) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_n = other._n;
		_v = other._v;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_v.size() >= _n)
		throw std::out_of_range("Span is full");
	_v.insert(n);
}

void Span::addNumbers(int min, int max, unsigned int n) {
	if (_v.size() + n > _n)
		throw std::out_of_range("Span is full");
	for (unsigned int i = 0; i < n; i++)
		_v.insert(rand() % (max - min + 1) + min);
}

unsigned int Span::shortestSpan() {
	if (_v.size() <= 1)
		throw std::out_of_range("Span is empty or has only one element");
	std::multiset<int>::iterator it = _v.begin();
	std::multiset<int>::iterator it2 = ++_v.begin();
	int64_t min = abs_int64(static_cast<int64_t>(*it) - *it2);
	while (it2 != _v.end()) {
		int64_t diff = abs_int64(static_cast<int64_t>(*it) - *it2);
		min = std::min(min, diff);
		it++;
		it2++;
	}
	return static_cast<unsigned int>(min);
}

unsigned int Span::longestSpan() {
	if (_v.size() <= 1)
		throw std::out_of_range("Span is empty or has only one element");
	std::multiset<int>::iterator it = _v.begin();
	std::multiset<int>::iterator it2 = --_v.end();
	return static_cast<unsigned int>(abs_int64(static_cast<int64_t>(*it) - *it2));
}
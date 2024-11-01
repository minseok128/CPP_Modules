/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:05:22 by michang           #+#    #+#             */
/*   Updated: 2024/11/01 12:27:49 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe* PmergeMe::_instance = 0;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj) { (void)obj; }

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
	(void)obj;
	return *this;
}

PmergeMe& PmergeMe::getInstance() {
	if (!_instance)
		_instance = new PmergeMe();
	return *_instance;
}

void PmergeMe::deleteInstance() {
	if (_instance) {
		delete _instance;
		_instance = 0;
	}
}

void PmergeMe::pushBack(int n) {
	t_data tmp = {n, 0, 0};
	_v.push_back(tmp);
	_l.push_back(tmp);
}

void PmergeMe::printAll(const std::string& s) {
	std::cout << s;
	std::vector<t_data>::iterator it_v = _v.begin();
	std::list<t_data>::iterator it_l = _l.begin();

	while (it_v != _v.end() && it_l != _l.end()) {
		if (it_v->value != it_l->value)
			std::cerr << "Unmatched values: ";
		std::cout << it_v->value << " ";
		it_v++;
		it_l++;
	}
	std::cout << std::endl;
}

void PmergeMe::sortVector() {
	unsigned int h = _v.size() / 2;

	(void)h;
}

void PmergeMe::sortList() {
	unsigned int h = _v.size() / 2;

	(void)h;
}
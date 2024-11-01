/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:05:22 by michang           #+#    #+#             */
/*   Updated: 2024/11/01 16:25:37 by michang          ###   ########.fr       */
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
	t_data* tmp = new t_data(n, 0, 0);
	_v.push_back(tmp);
	_l.push_back(tmp);
}

void PmergeMe::printAll(const std::string& s) {
	std::cout << s;
	std::vector<t_data*>::iterator it_v = _v.begin();
	std::list<t_data*>::iterator it_l = _l.begin();

	while (it_v != _v.end() && it_l != _l.end()) {
		// if ((*it_v)->value != (*it_l)->value)
		// 	std::cerr << "Unmatched values: ";
		std::cout << (*it_v)->value << " ";
		it_v++;
		it_l++;
	}
	std::cout << std::endl;
}

void PmergeMe::debugData(t_data* d, int level) {
	if (d->left != 0 && d->right != 0) {
		std::cout << "<[{("[level % 3] << " ";
		debugData(d->left, level + 1);
		debugData(d->right, level + 1);
		std::cout << ">]})"[level % 3] << " ";
	} else {
		std::cout << d->value << " ";
	}
}

void PmergeMe::debugVector() {
	for (std::vector<t_data*>::iterator it = _v.begin(); it != _v.end(); it++)
		debugData(*it, 0);
	std::cout << std::endl;
}

void PmergeMe::sortVector() {
	const unsigned int s = _v.size();
	const unsigned int h = s / 2;

	if (h == 0)
		return;

	for (unsigned int i = 0; i < h; i++) {
		unsigned int j = _v.size() - 1;
		_v[i] = _v[i]->value > _v[j]->value
						  ? new t_data(_v[i]->value, _v[j], _v[i])
						  : new t_data(_v[j]->value, _v[i], _v[j]);
		_v.pop_back();
	}
	sortVector();

	debugVector();
	std::cout << "h:" << h << ", s:" << s <<  std::endl; 
	for (unsigned int i = 0; i < s; ++++i) {
		int value = _v[i]->left->value;
		std::cout << "value:" << value << std::endl;

		long long left = 0, right = i;
		while (left <= right) {
			long long mid = (left + right) / 2;
			if (_v[mid]->value < value)
				left = mid + 1;
			else
				right = mid - 1;
		}
		std::cout << "left:" << left << std::endl;
		_v.insert(_v.begin() + left, _v[i]->left);
		// t_data* tmp = _v[i];
		_v[i + 1] = _v[i + 1]->right;
		// delete tmp;
	}
}

void PmergeMe::sortList() {
	unsigned int h = _v.size() / 2;

	(void)h;
}
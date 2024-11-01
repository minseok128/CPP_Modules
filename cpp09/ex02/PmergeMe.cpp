/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:05:22 by michang           #+#    #+#             */
/*   Updated: 2024/11/01 13:02:43 by michang          ###   ########.fr       */
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
	t_data* tmp = new t_data;
	tmp->value = n;
	tmp->left = 0;
	tmp->right = 0;
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

void PmergeMe::debugData(t_data* d) {
	if (d->left != 0 && d->right != 0) {
		std::cout << "[ ";
		debugData(d->left);
		debugData(d->right);
		std::cout << "] ";
	} else {
		std::cout << d->value << " ";
	}
}

void PmergeMe::debugVector() {
	std::vector<t_data*>::iterator it = _v.begin();
	while (it != _v.end()) {
		debugData(*it);
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::sortVector() {
	const unsigned int h = _v.size() / 2;

	if (h == 0)
		return;

	for (unsigned int i = 0; i < h; i++) {
		unsigned int j = _v.size() - 1;
		t_data* tmp;
		if (_v[i]->value > _v[j]->value) {
			tmp = new t_data(*_v[i]);
			tmp->left = _v[i];
			tmp->right = _v[j];
			tmp->value = _v[i]->value;
		} else {
			tmp = new t_data(*_v[j]);
			tmp->left = _v[j];
			tmp->right = _v[i];
			tmp->value = _v[j]->value;
		}
		_v[i] = tmp;
		_v.pop_back();
	}
	sortVector();
}

void PmergeMe::sortList() {
	unsigned int h = _v.size() / 2;

	(void)h;
}
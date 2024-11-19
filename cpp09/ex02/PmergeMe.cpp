/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:05:22 by michang           #+#    #+#             */
/*   Updated: 2024/11/19 17:29:01 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe* PmergeMe::_instance = 0;

PmergeMe::PmergeMe() : _vCount(0), _lCount(0) {}

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
	// for (std::vector<t_data*>::iterator it = _v.begin(); it != _v.end(); it++)
	// 	debugData(*it, 0);
	// std::cout << std::endl;
	std::cout << _vCount << "\n";
	// std::cout << "\n";
}

int PmergeMe::getJNum(int k) {
	if (k < 0)
		return 0;
	return (std::pow(2, k) - (k % 2 ? -1 : 1)) / 3;
}

void PmergeMe::insertVector(int i) {
	long long left = 0, right = i;
	// std::cout << "Inserting " << _v[i]->left->value << " at " << left << ", " << i
	// 		  << std::endl;
	while (left < right) {
		long long mid = (left + right) / 2;
		if (_v[mid]->value < _v[i]->left->value)
			left = mid + 1;
		else
			right = mid;
		_vCount++;
	}
	_v.insert(_v.begin() + left, _v[i]->left);
	if (_v[i + 1]->right)
		_v[i + 1] = _v[i + 1]->right;
	else
		_v.pop_back();
}

void PmergeMe::sortVector() {
	unsigned int s = _v.size(), h = s / 2;

	if (h == 0)
		return;

	for (unsigned int i = 0; i < h; i++) {
		unsigned int j = _v.size() - 1;
		_v[i] = _v[i]->value > _v[j]->value
					? new t_data(_v[i]->value, _v[j], _v[i])
					: new t_data(_v[j]->value, _v[i], _v[j]);
		_vCount++;
		_v.pop_back();
	}

	if (s % 2) {
		t_data* oddData = _v.back();
		_v.pop_back();
		sortVector();
		_v.push_back(new t_data(oddData->value, oddData, 0));
	} else {
		sortVector();
	}
	// debugVector();

	int j = 1, k = 0;
	int nowLevel = _v[0]->level, prevJNum = getJNum(j - 1), nowJNum = getJNum(j), jNumGap;
	int flag = 0;

	while (!flag) {
		// std::cout << "prevJNum: " << prevJNum << ", nowJNum: " << nowJNum << std::endl;
		jNumGap = nowJNum - prevJNum;
		k = prevJNum * 2 + jNumGap - 1;
		// std::cout << "k: " << k << std::endl;
		if  (k >= static_cast<int>(_v.size())) {
			k = _v.size() - 1;
			flag = 1;
		}
		for (int l = 0; l < jNumGap && k >= 0; k--) {
			if (_v[k]->level == nowLevel) {
				insertVector(k++);
				l++;
			}
		}
		prevJNum = nowJNum;
		nowJNum = getJNum(++j);
	}
	// debugVector();
}

void PmergeMe::sortList() {
	unsigned int h = _v.size() / 2;

	_lCount = 0;
	(void)h;
}
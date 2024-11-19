/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:05:22 by michang           #+#    #+#             */
/*   Updated: 2024/11/19 19:50:37 by michang          ###   ########.fr       */
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
		if ((*it_v)->value != (*it_l)->value)
			std::cerr << "Unmatched values: ";
		std::cout << (*it_v)->value << " ";
		it_v++;
		it_l++;
	}
	std::cout << std::endl;
}

int PmergeMe::getVCoutn() { return _vCount; }

int PmergeMe::getLCount() { return _lCount; }

int PmergeMe::getJNum(int k) {
	if (k < 0)
		return 0;
	return (std::pow(2, k) - (k % 2 ? -1 : 1)) / 3;
}

// Vector
void PmergeMe::insertVector(int i) {
	long long left = 0, right = i;

	while (left < right) {
		long long mid = (left + right) / 2;
		if (_v[mid]->value < _v[i]->left->value)
			left = mid + 1;
		else
			right = mid;
		_vCount++;
	}
	_v.insert(_v.begin() + left, _v[i]->left);

	t_data* tmp;
	if (_v[i + 1]->right) {
		tmp = _v[i + 1];
		_v[i + 1] = _v[i + 1]->right;
	} else {
		tmp = _v[i + 1];
		_v.pop_back();
	}
	delete tmp;
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

	int j = 1, k = 0, nowLevel = _v[0]->level, flag = 0;
	int prevJNum = getJNum(0), nowJNum = getJNum(1), jNumGap;

	while (!flag) {
		jNumGap = nowJNum - prevJNum;
		k = prevJNum * 2 + jNumGap - 1;
		if (k >= static_cast<int>(_v.size())) {
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
}

// List
std::list<t_data*>::iterator PmergeMe::getIteratorAtIndex(int index) {
	std::list<t_data*>::iterator it = _l.begin();
	std::advance(it, index);
	return it;
}

void PmergeMe::insertList(int i) {
	int left_index = 0;
	int right_index = i;
	std::list<t_data*>::iterator left_it = _l.begin();
	std::list<t_data*>::iterator right_it = getIteratorAtIndex(i);

	t_data* value_to_insert = (*getIteratorAtIndex(i))->left;

	while (left_index < right_index) {
		int mid_index = (left_index + right_index) / 2;
		std::list<t_data*>::iterator mid_it = left_it;
		std::advance(mid_it, mid_index - left_index);

		if ((*mid_it)->value < value_to_insert->value) {
			left_it = mid_it;
			++left_it;
			left_index = mid_index + 1;
		} else {
			right_it = mid_it;
			right_index = mid_index;
		}
		_lCount++;
	}

	_l.insert(left_it, value_to_insert);

	t_data* tmp = 0;
	std::list<t_data*>::iterator next_it = getIteratorAtIndex(i + 1);
	if (next_it != _l.end() && (*next_it)->right) {
		tmp = *next_it;
		*next_it = (*next_it)->right;
	} else if (next_it != _l.end()) {
		tmp = *next_it;
		_l.erase(next_it);
	}
	delete tmp;
}

void PmergeMe::sortList() {
	unsigned int s = _l.size(), h = s / 2;

	if (h == 0)
		return;

	std::list<t_data*>::iterator front_it = _l.begin();
	std::list<t_data*>::iterator back_it = _l.end();
	--back_it;

	for (unsigned int i = 0; i < h; ++i) {
		t_data* front_data = *front_it;
		t_data* back_data = *back_it;

		t_data* new_data;
		if (front_data->value > back_data->value)
			new_data = new t_data(front_data->value, back_data, front_data);
		else
			new_data = new t_data(back_data->value, front_data, back_data);
		_lCount++;

		*front_it = new_data;

		std::list<t_data*>::iterator temp_it = back_it;
		if (back_it == front_it) {
			++front_it;
		}
		if (back_it != _l.begin()) {
			--back_it;
		}
		_l.erase(temp_it);

		++front_it;
	}

	if (s % 2) {
		t_data* oddData = _l.back();
		_l.pop_back();
		sortList();
		_l.push_back(new t_data(oddData->value, oddData, 0));
	} else {
		sortList();
	}

	int j = 1, flag = 0;
	int prevJNum = getJNum(0), nowJNum = getJNum(1), jNumGap;
	int nowLevel = _l.front()->level;

	while (!flag) {
		jNumGap = nowJNum - prevJNum;
		int k = prevJNum * 2 + jNumGap - 1;
		if (k >= static_cast<int>(_l.size())) {
			k = _l.size() - 1;
			flag = 1;
		}
		for (int l = 0; l < jNumGap && k >= 0; k--) {
			std::list<t_data*>::iterator it = getIteratorAtIndex(k);
			if ((*it)->level == nowLevel) {
				insertList(k++);
				l++;
			}
		}
		prevJNum = nowJNum;
		nowJNum = getJNum(++j);
	}
}

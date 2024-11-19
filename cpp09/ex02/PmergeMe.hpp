/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:05:04 by michang           #+#    #+#             */
/*   Updated: 2024/11/19 17:39:16 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <cctype>
#include <cmath>
#include <exception>
#include <iostream>
#include <list>
#include <string>
#include <vector>

typedef struct s_data {
	int value;
	int level;
	struct s_data* left;
	struct s_data* right;

	s_data(int v, s_data* l, s_data* r) : value(v), left(l), right(r) {
		level = l != 0 ? l->level + 1 : 0;
	}
} t_data;

class PmergeMe {
  public:
	static PmergeMe& getInstance();
	void pushBack(int n);
	void printAll(const std::string& s);
	void sortVector();
	void sortList();

  private:
	PmergeMe();
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& obj);
	void insertVector(int i);
	static int getJNum(int k);

	static PmergeMe* _instance;
	std::vector<t_data*> _v;
	std::list<t_data*> _l;
	int _vCount;
	int _lCount;
};

#endif

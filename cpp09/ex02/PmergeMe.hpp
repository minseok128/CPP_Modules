/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:05:04 by michang           #+#    #+#             */
/*   Updated: 2024/11/02 22:20:19 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <cctype>
#include <exception>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <cmath>

typedef struct s_data {
	int value;
	int level;
	struct s_data* left;
	struct s_data* right;

	s_data(int v, int lv, s_data* l, s_data* r) : value(v), level(lv), left(l), right(r) {}
} t_data;

class PmergeMe {
  public:
	static PmergeMe& getInstance();
	static void deleteInstance();
	void pushBack(int n);
	void printAll(const std::string& s);
	void sortVector();
	void debugVector();
	void debugData(t_data* d, int level);
	void sortList();

  private:
	PmergeMe();
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& obj);
	void insertVector(t_data* d, int i);
	static int getJacobsthalNumber(int k);

	static PmergeMe* _instance;
	std::vector<t_data*> _v;
	std::list<t_data*> _l;
	int _vCount;
	int _lCount;
};

#endif

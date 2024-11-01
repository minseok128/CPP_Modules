/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:05:04 by michang           #+#    #+#             */
/*   Updated: 2024/11/01 12:27:41 by michang          ###   ########.fr       */
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

typedef struct s_data {
	int value;
	struct s_data* left;
	struct s_data* right;
} t_data;

class PmergeMe {
  public:
	static PmergeMe& getInstance();
	static void deleteInstance();
	void pushBack(int n);
	void printAll(const std::string& s);
	void sortVector();
	void sortList();

  private:
	PmergeMe();
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();
	PmergeMe& operator=(const PmergeMe& obj);

	static PmergeMe* _instance;
	std::vector<t_data> _v;
	std::list<t_data> _l;
};

#endif

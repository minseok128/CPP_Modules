/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:05:04 by michang           #+#    #+#             */
/*   Updated: 2024/10/29 21:22:49 by michang          ###   ########.fr       */
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
	std::vector<int> _v;
	std::list<int> _l;
};

#endif

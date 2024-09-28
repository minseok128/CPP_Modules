/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:36:44 by michang           #+#    #+#             */
/*   Updated: 2024/09/28 21:44:19 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <deque>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
  public:
	MutantStack();
	MutantStack(const MutantStack& ref);
	virtual ~MutantStack();
	MutantStack& operator=(const MutantStack& ref);

	typedef typename std::deque<T>::iterator iterator;
	iterator begin();
	iterator end();
	const iterator begin() const;
	const iterator end() const;
};

template <typename T> MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& ref) : std::stack<T>(ref) {}

template <typename T> MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& ref) {
	if (this != &ref)
		std::stack<T>::operator=(ref);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (std::stack<T>::c.begin());
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (std::stack<T>::c.end());
}

template <typename T>
const typename MutantStack<T>::iterator MutantStack<T>::begin() const {
	return (std::stack<T>::c.begin());
}

template <typename T>
const typename MutantStack<T>::iterator MutantStack<T>::end() const {
	return (std::stack<T>::c.end());
}

#endif
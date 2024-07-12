/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:03:04 by michang           #+#    #+#             */
/*   Updated: 2024/07/12 19:57:41 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstdlib>
#include <exception>

template <typename T> class Array {
  public:
	Array();
	Array(unsigned int n);
	Array(const Array& obj);
	~Array();
	Array& operator=(const Array& obj);
	T& operator[](unsigned int i);
	const T& operator[](unsigned int i) const;
	unsigned int size() const;

  private:
	T* _arr;
	unsigned int _size;
};

template <typename T> Array<T>::Array() : _arr(0), _size(0) {}

template <typename T> Array<T>::Array(unsigned int n) {
	if (n == 0) {
		_arr = 0;
		_size = 0;
	} else {
		_arr = new T[n];
		_size = n;
	}
}

template <typename T> Array<T>::Array(const Array& obj) {
	_size = obj._size;
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = obj._arr[i];
}

template <typename T> Array<T>& Array<T>::operator=(const Array& obj) {
	if (this != &obj) {
		if (_arr != 0)
			delete[] _arr;
		_size = obj._size;
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = obj._arr[i];
		return *this;
	}
	return *this;
}

template <typename T> Array<T>::~Array() { delete[] _arr; }

template <typename T> T& Array<T>::operator[](unsigned int i) {
	if (i >= _size || i < 0)
		throw std::exception();
	return _arr[i];
}

template <typename T> const T& Array<T>::operator[](unsigned int i) const {
	if (i >= _size || i < 0)
		throw std::exception();
	return _arr[i];
}

template <typename T> unsigned int Array<T>::size() const { return _size; }

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:18:08 by michang           #+#    #+#             */
/*   Updated: 2024/07/12 18:26:58 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T const& min(T const& a, T const& b) {
	return (a < b ? a : b);
}

template <typename T> T& min(T& a, T& b) { return (a < b ? a : b); }

template <typename T> T const& max(T const& a, T const& b) {
	return (a > b ? a : b);
}

template <typename T> T& max(T& a, T& b) { return (a > b ? a : b); }

#endif

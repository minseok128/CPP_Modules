/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:44:47 by michang           #+#    #+#             */
/*   Updated: 2024/09/28 17:59:51 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>

template <typename T> int easyfind(T& container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		return -1;
	return std::distance(container.begin(), it);
}

#endif
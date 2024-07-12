/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:49:09 by michang           #+#    #+#             */
/*   Updated: 2024/07/12 18:56:35 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include <string>

int main()
{
	{
		std::cout << "string test\n";
		std::string obj1 = "obj1";
		std::string obj2 = "obj2";
		std::string obj3 = "obj3";
		std::string arr[3] = {obj1, obj2, obj3};
		::iter(arr, 3, printValue);
	}

	{
		std::cout << "\nconst string test\n";
		const std::string obj1 = "obj1";
		const std::string obj2 = "obj2";
		const std::string obj3 = "obj3";
		std::string arr[3] = {obj1, obj2, obj3};
		::iter(arr, 3, printValue);
	}

	{
		std::cout << "\nint test\n";
		int arr[3] = {0, 1, 2};
		::iter(arr, 3, printValue);
	}

	{
		std::cout << "\nconst int test\n";
		const int arr[3] = {0, 1, 2};
		::iter(arr, 3, printValue);
	}
}
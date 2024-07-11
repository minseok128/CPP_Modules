/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:42:40 by michang           #+#    #+#             */
/*   Updated: 2024/07/11 20:48:32 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data;
	data.name = "michang";
	data.age = 10;

	std::cout << "Data ptr : " << &data << std::endl;
	std::cout << "Data name : " << data.name << std::endl;
	std::cout << "Data age : " << data.age << std::endl;

	uintptr_t tmp = Serializer::serialize(&data);
	std::cout << "\nSerialized tmp : " << tmp << std::endl;
	Data* convertedData = Serializer::deserialize(tmp);

	std::cout << "\nConverted Data ptr : " << convertedData << std::endl;
	std::cout << "Converted Data name : " << convertedData->name << std::endl;
	std::cout << "Converted Data age : " << convertedData->age << std::endl;
	return (0);
}
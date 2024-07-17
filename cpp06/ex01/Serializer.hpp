/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:40:08 by michang           #+#    #+#             */
/*   Updated: 2024/07/11 20:44:58 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <string>
#define uintptr_t unsigned long

struct Data {
	std::string name;
	int age;
};

class Serializer {
  public:
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

  private:
	Serializer();
	Serializer(const Serializer& obj);
	Serializer& operator=(const Serializer& obj);
};

#endif
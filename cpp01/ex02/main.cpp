/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:27:47 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 14:39:56 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string	stringVAR = "HI THIS IS BRAIN";
	std::string	*stringPTR = &stringVAR;
	std::string	&stringREF = stringVAR;

	std::cout << &stringVAR << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << "\n" << std::endl;

	std::cout << stringVAR << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << "\n" << std::endl;

	return (0);
}

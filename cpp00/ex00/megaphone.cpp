/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:20:12 by michang           #+#    #+#             */
/*   Updated: 2024/03/01 22:38:34 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	to_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 0; argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << to_uppercase(argv[i][j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
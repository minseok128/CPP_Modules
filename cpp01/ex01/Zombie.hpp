/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michang <michang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:32:33 by michang           #+#    #+#             */
/*   Updated: 2024/03/11 14:02:59 by michang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{
public:
	Zombie();
	~Zombie();
	void	announce(void);
	void	setName(std::string name);

private:
	std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
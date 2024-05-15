#ifndef FLOOR_HPP
# define FLOOR_HPP
# include "AMateria.hpp"

class Floor
{
public:
	Floor();
	Floor(const Floor& obj);
	~Floor();
	Floor&	operator=(const Floor& obj);
	void	push(AMateria* m);
	void	clean();

private:
	AMateria*	_inventory[10];
	int			_idx;
};

#endif

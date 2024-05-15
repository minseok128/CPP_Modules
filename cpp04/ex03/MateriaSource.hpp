#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& obj);
	~MateriaSource();
	MateriaSource&	operator=(const MateriaSource& obj);
	void			learnMateria(AMateria* m);
	AMateria*		createMateria(std::string const & type);

private:
	AMateria*	_inventory[4];
};

#endif

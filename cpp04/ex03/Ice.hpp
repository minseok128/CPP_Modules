#ifndef ICE_HPP
# define ICE_HPP
# include <string>
# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& obj);
	~Ice();
	Ice&		operator=(const Ice& obj);
	AMateria*	clone() const;
	void		use(ICharacter& target);

private:

};

#endif

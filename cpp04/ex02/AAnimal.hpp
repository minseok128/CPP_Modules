#ifndef AANIMAL_CPP
# define AANIMAL_CPP
# include <iostream>
# include <string>

class AAnimal
{
public:
	virtual				~AAnimal();
	virtual void		makeSound() const = 0;
	const std::string&	getType() const;

protected:
	AAnimal();
	AAnimal(const AAnimal& obj);
	AAnimal(const std::string& type);
	AAnimal&	operator=(const AAnimal& obj);
	std::string	_type;
};

#endif


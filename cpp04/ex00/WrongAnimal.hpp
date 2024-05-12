#ifndef WRONGANIMAL_CPP
# define WRONGANIMAL_CPP
# include <iostream>
# include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& obj);
	WrongAnimal(const std::string& type);
	virtual				~WrongAnimal();
	WrongAnimal&		operator=(const WrongAnimal& obj);
	virtual void		makeSound() const;
	const std::string&	getType() const;

protected:
	std::string	_type;
};

#endif


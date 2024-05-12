#ifndef ANIMAL_CPP
# define ANIMAL_CPP
# include <string>

class Animal
{
public:
	Animal();
	Animal(const Animal& obj);
	Animal(const std::string& type);
	virtual			~Animal();
	Animal&			operator=(const Animal& obj);
	virtual void	makeSound() const = 0;

protected:
	std::string	_type;
};

#endif


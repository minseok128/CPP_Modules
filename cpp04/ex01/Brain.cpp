#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = obj._ideas[i];
	std::cout << "Brain copy constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

Brain&	Brain::operator=(const Brain& obj)
{
	if (this != &obj)
		for (int i = 0; i < 100; i++)
			_ideas[i] = obj._ideas[i];
	std::cout << "Brain copy assignment operator" << std::endl;
	return (*this);
}

const std::string&	Brain::getIdea(const int idx) const
{
	if (idx < 0 || idx >= 100)
		throw std::string("Index out of range");
	return (_ideas[idx]);
}

void	Brain::setIdea(const int idx, const std::string& idea)
{
	if (idx < 0 || idx >= 100)
		throw std::string("Index out of range");
	_ideas[idx] = idea;
}

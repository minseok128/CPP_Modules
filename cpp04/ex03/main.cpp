#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

// void	a()
// {
// 	system("leaks a.out");
// }

int main()
{
	// atexit(a);
	{
		std::cout << "subject test\n";
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	{
		std::cout << "\nanother test\n";
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());

		Floor floor;
		ICharacter* me = new Character("me");
		me->setFloor(&floor);

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("fire");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(663, *bob);
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(4);
		floor.clean();
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}
	return 0;
}
#include "../header/Character.hpp"
#include "../header/MateriaSource.hpp"
#include "../header/Ice.hpp"
#include "../header/Cure.hpp"


int main(void)
{
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
	
		ICharacter *moi = new Character("moi");
	
		AMateria *tmp;
		tmp = src->createMateria("ice");
		moi->equip(tmp);
		tmp = src->createMateria("cure");
		moi->equip(tmp);
	
		ICharacter *bob = new Character("bob");

		std::cout << std::endl;
		moi->use(0, *bob);
		moi->use(1, *bob);
		std::cout << std::endl;
	
		delete bob;
		delete moi;
		delete src;
	}
	std::cout << std::endl << "--- Unknow type test creating materia ---" << std::endl << "testing if u enter a unknow type of materia it doesnt crash and return 0"<< std::endl << std::endl;
	{
		IMateriaSource *source = new MateriaSource();
		source->learnMateria(new Ice());
		source->learnMateria(new Cure());
		std::cout << std::endl << "unknown type: " << source->createMateria("i do not exists") << std::endl << std::endl;
		delete source;
	}
	{
		std::cout << std::endl << "--- CHARACTER COPY (operator = )---" << std::endl << "Creer un character A -> lui attribue 2 materia, creer un character B -> lui attribue 1 materia. operator B = A doit supprimer le materia de B et faire une copie profonde des materia de A. Unequip le materia 0 de A et print les 2 materiaux de B. doit etre prnt initialement les deux materia donne a A soit ice puis cure" << std::endl << std::endl;

		IMateriaSource *source = new MateriaSource();
		source->learnMateria(new Ice());
		source->learnMateria(new Cure());

		Character *a = new Character("A");
		Character *b = new Character("B");
		Character *enemy = new Character("bob");

		a->equip(source->createMateria("ice"));
		a->equip(source->createMateria("cure"));
		b->equip(source->createMateria("cure"));

		*b = *a;

		a->unequip(0);
		std::cout << std::endl;
		b->use(0, *enemy);
		b->use(1, *enemy);
		std::cout << std::endl;

		delete source;
		delete a;
		delete b;
		delete enemy;
	}
	{
		std::cout << std::endl << "--- UNEQUIP ---" << std::endl << "Le character A se voit attribuer un materia a l'emplacement 0. On le supprime puis on le print. Rien ne doit s'afficher lors de l'appelle de la fonction use" << std::endl << std::endl;

		Ice *ice = new Ice();
		Character *a = new Character("A");

		a->equip(ice);
		a->unequip(0);

		std::cout << std::endl;
		std::cout << "(should not print anything)" << std::endl;
		a->use(0, *a);
		std::cout << std::endl;

		delete a;
	}
}

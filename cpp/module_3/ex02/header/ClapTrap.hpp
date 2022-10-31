#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap();
	ClapTrap	&operator=(ClapTrap const &src);

	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	int			getHit(void) const;
	std::string	getName(void) const;
	int 		getEnergy(void) const;
	int 		getDamage(void) const;

	protected:
	std::string	_name;
	int			_hit;
	int			_energy;
	int			_damageAttack;
	ClapTrap();
};

std::ostream	&operator<<(std::ostream &out, ClapTrap const &src);

#endif

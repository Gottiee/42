#ifndef DIAMONTRAP_HPP
#define DIAMONTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &src);
	~DiamondTrap();
	DiamondTrap	&operator=(DiamondTrap const &src);
	using		ScavTrap::attack;
	void		whoAmI(void);
	std::string	getName(void) const;

	private:
	DiamondTrap();		
	std::string	_name;
};

std::ostream	&operator<<(std::ostream &out, DiamondTrap const &src);

#endif

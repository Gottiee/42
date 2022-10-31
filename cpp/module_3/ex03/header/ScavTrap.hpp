#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:	
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap();
	ScavTrap	&operator=(ScavTrap const &src);
	void		guardGate();
	bool		getGateKeeper() const;
	void		attack(const std::string &target);

	protected:
	ScavTrap();
	static int hitPointsInit;
	static int energyPointsInit;
	static int attackDamageInit;
	bool	_gateKeeper;
};

std::ostream	&operator<<(std::ostream &out, ScavTrap const &src);

#endif

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap();
	FragTrap	&operator=(FragTrap const &src);
    void		highFivesGuys(void);

	protected:
	static int hitPointsInit;
	static int energyPointsInit;
	static int attackDamageInit;
	FragTrap();
};

//std::ostream	&operator<<(std::ostream &out, FragTrap const &src);

#endif

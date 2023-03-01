#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &copy);
		ClapTrap &operator=(ClapTrap const &copy);
		~ClapTrap(void);
		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
		std::string getName(void);
		unsigned int getAttack(void);
};

#endif

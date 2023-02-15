#include <ClapTrap.hpp>

int main(void) {
    ClapTrap bob = ClapTrap("Bob");
    ClapTrap jim = ClapTrap("Jim");

    bob.attack(jim.getName());
    jim.takeDamage(bob.getAttack());
    jim.beRepaired(2);
}

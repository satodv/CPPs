#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap Joe("Joe");
    Joe.attack("Enemy");
    Joe.takeDamage(5);
    Joe.beRepaired(3);

    std::cout << "\nScav Test\n";
    ScavTrap Jane("Jane");
    Jane.attack("Boss");
    Jane.takeDamage(20);
    Jane.beRepaired(15);
    Jane.guardGate();

    std::cout << "\nFrag test\n";
    FragTrap Frag("Frag");
    Frag.attack("boss");
    Frag.takeDamage(40);
    Frag.beRepaired(25);
    Frag.highFivesGuys();

    std::cout << "\n";
    FragTrap FragCopy = Frag;
    FragTrap FragAssign;
    FragAssign = Frag;

    std::cout << "\n\n";
    return 0;
}


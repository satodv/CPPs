#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    ClapTrap Joe("Joe");
    Joe.attack("Enemy");
    Joe.takeDamage(5);
    Joe.beRepaired(3);

    std::cout << "\n";
    ScavTrap Jane("Jane");
    Jane.attack("Boss");
    Jane.takeDamage(20);
    Jane.beRepaired(15);
    Jane.guardGate();
    // ClapTrap* ptr = &Jane;
    // ptr->attack("Target");

    std::cout << "\n";
    ScavTrap ScravCopy(Jane);
    ScavTrap ScravAssign;
    ScravAssign = Jane;

    return 0;
}

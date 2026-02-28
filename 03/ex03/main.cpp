#include "DiamondTrap.hpp"

int main() {
    DiamondTrap Diamond("DiamondMonster");

    Diamond.attack("Boss");
    Diamond.takeDamage(25);
    Diamond.beRepaired(10);
    Diamond.guardGate();
    Diamond.highFivesGuys();
    Diamond.whoAmI();

    std::cout << "\n\n";
    DiamondTrap copy = Diamond;

    std::cout << "\n\n";
    DiamondTrap assigned;
    assigned = Diamond;

    return 0;
}

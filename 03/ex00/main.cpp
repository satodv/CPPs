#include "ClapTrap.hpp"

int main() {
    ClapTrap Joe("Joe");
    ClapTrap Jane("Jane");

   Joe.attack("Jane");
   Joe.takeDamage(3);
   Joe.beRepaired(2);

    Jane.attack("Joe");
    Jane.takeDamage(11);
    Jane.beRepaired(5);

    ClapTrap JoeCopy = Joe;
    ClapTrap JaneOp;
    JaneOp = Jane;

    return 0;
}

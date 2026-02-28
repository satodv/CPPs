#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    name = "DefaultScav";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called for " << other.name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other); // Call ClapTrap assignemt op to copy ClapTrap's attributes (if I had Scav's also copy those)
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ScavTrap " << name << " cannot attack: no HP or energy!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target
              << ", dealing " << attackDamage << " damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}

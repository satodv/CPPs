#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap() {
    name = "DefaultDiamond";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
    std::cout << "DiamondTrap default constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& _name) : ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name) {
    name = _name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
    std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    name = other.name;
    std::cout << "DiamondTrap copy constructor called for " << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

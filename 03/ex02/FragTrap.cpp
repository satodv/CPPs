#include "FragTrap.hpp"

FragTrap::FragTrap() {
    name = "DefaultFrag";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const std::string& _name) : ClapTrap(_name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called for " << other.name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << name << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "FragTrap " << name << " can't attack: out of HP or energy!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "FragTrap " << name << " attacks " << target
              << ", making " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}

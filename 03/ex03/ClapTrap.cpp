#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap default constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const std::string& _name)
    : name(_name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hitPoints(other.hitPoints),
      energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "ClapTrap copy constructor called for " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ClapTrap " << name << " cannot attack: not enough HP or energy!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints <= 0) {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
        return;
    }
    hitPoints -= amount;
    if (hitPoints < 0) hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage! HP left: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ClapTrap " << name << " cannot repair: not enough HP or energy!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself, gaining " << amount
              << " HP! HP is now: " << hitPoints << std::endl;
}

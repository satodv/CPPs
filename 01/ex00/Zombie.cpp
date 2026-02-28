#include "Zombie.hpp"
#include <cstdlib>

Zombie::Zombie(const std::string name) : name(name) {}

void Zombie::announce()
{
    std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
} 

Zombie::~Zombie()
{
    std::cout << name << " has been deleted" << std::endl;
}
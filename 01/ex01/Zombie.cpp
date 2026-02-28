#include "Zombie.hpp"

Zombie::Zombie() : name("Zombie") {}

Zombie::Zombie(const std::string name) : name(name) {}

void Zombie::setName(const std::string name)
{
    this->name = name;
}

void Zombie::announce(int i)
{
    int count = i + 1;
    std::cout   << name << " " 
                << count << ":  BraiiiiiiinnnzzzZ..." 
                << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " has been deleted" << std::endl;
}

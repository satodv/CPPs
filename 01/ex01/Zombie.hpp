#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;

public:
    Zombie();
    Zombie(const std::string name);
    void setName(const std::string name);
    void announce(int);
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string> 
#include <iostream>
#include <cstdlib>


class Zombie 
{
    private:
        std::string name;

    public:
        Zombie(const std::string name);

        void announce( void );
        ~Zombie();
};

Zombie*     newZombie(std::string name);
void        randomChump(std::string name);

#endif
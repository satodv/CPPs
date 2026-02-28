#include "Zombie.hpp"

int main()
{
    int count = 5;
    Zombie* horde = zombieHorde(count, "Horde of Zombie single");

    for (int i = 0; i < count; ++i)
        horde[i].announce(i);

    delete[] horde;

    return 0;
}

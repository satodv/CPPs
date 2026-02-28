#include <iostream>
#include "Zombie.hpp"

int main(int argc, char *argv[])
{
    (void)argv;
    (void)argc;
    Zombie *heap = newZombie("Foo heap");
    heap->announce();
    randomChump("Foo stack");
    delete heap;
    return 0;
}

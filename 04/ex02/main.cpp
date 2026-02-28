#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "\nArray of Animals\n" << std::endl;
    std::cout << "#######################\n";
    const int size = 4;
    AAnimal* animals[size];

    for (int k = 0; k < size / 2; ++k)
        animals[k] = new Dog();
    for (int k = size / 2; k < size; ++k)
        animals[k] = new Cat();

    for (int k = 0; k < size; ++k)
        delete animals[k];

    std::cout << "\nDeep copy" << std::endl;
    std::cout << "#######################\n";

    Dog original;
    original.setIdea(0, "Eat!");
    original.setIdea(1, "Sleep!");

    Dog copy = original;

    std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
    std::cout << "Copy idea[0]:     " << copy.getIdea(0) << std::endl;

    original.setIdea(0, "Bark!!!");

    std::cout << "After modification:\n";
    std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
    std::cout << "Copy idea[0]:     " << copy.getIdea(0) << std::endl;
    
    //AAnimal* AAn = new Dog();
    //AAn->getType();
    //delete AAn;
    //AAnimal testAnimal;// Will cause error now

    return 0;
}

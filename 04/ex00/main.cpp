#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "\nAnimals Tests\n";
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n";
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    std::cout << "\n";
    cat->makeSound();
    dog->makeSound();
    animal->makeSound();

    delete animal;
    delete dog;
    delete cat;

    std::cout << "\nWrong Animals Tests\n";
    const WrongAnimal* WAnimal = new WrongAnimal();
    const WrongAnimal* WCat = new WrongCat();

    std::cout << "\n";
    std::cout << WAnimal->getType() << std::endl;
    std::cout << WCat->getType() << std::endl;

    std::cout << "\n";
    WAnimal->makeSound();
    WCat->makeSound();

    delete WAnimal;
    delete WCat;

    std::cout << "\n";
    WrongAnimal WA;
    WrongCat WC;

    WA.makeSound();
    WC.makeSound();

    return 0;
}

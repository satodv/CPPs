#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog assigned" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int i, const std::string& idea) {
    brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const {
    return brain->getIdea(i);
}

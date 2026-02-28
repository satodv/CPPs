#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat assigned" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miauuu!" << std::endl;
}

void Cat::setIdea(int i, const std::string& idea) {
    brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const {
    return brain->getIdea(i);
}

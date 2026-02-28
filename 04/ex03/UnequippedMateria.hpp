#ifndef UNEQUIPPED_MATERIA_HPP
#define UNEQUIPPED_MATERIA_HPP

#include "AMateria.hpp"

class UnequippedMateria {
private:
    struct Node {
        AMateria* materia;
        Node* next;
        Node(AMateria* m);
    };

    static Node* head;  // Static head of the linked list

public:
    static void add(AMateria* m);  // Add unequipped materia
    static void cleanup();         // Delete all unequipped materias
};

#endif // UNEQUIPPED_MATERIA_HPP
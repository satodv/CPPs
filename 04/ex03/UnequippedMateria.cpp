#include "UnequippedMateria.hpp"

UnequippedMateria::Node* UnequippedMateria::head = NULL;
UnequippedMateria::Node::Node(AMateria* m) : materia(m), next(NULL) {}

void UnequippedMateria::add(AMateria* m) {
    Node* newNode = new Node(m);
    newNode->next = head;
    head = newNode;
}

void UnequippedMateria::cleanup() {
    int count = 0;
    while (head) {
        count++;
        Node* temp = head;
        head = head->next;
        delete temp->materia;
        delete temp;
        std::cout << "Materia " << count << " lying around destroyed\n";
    }
}
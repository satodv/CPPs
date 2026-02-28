#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "UnequippedMateria.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;

    std::cout << std::endl << "=== Additional Tests ===" << std::endl;

    std::cout << "\n#######################\n";
    IMateriaSource* source = new MateriaSource();
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    
    source->learnMateria(ice);
    source->learnMateria(cure);
    
    Character alice("Alice");
    Character eve("Eve");
    
    std::cout << "\nInventory\n";
    std::cout << "\n#######################\n";
    alice.equip(source->createMateria("ice"));
    alice.equip(source->createMateria("cure"));
    alice.equip(source->createMateria("ice"));
    alice.equip(source->createMateria("cure"));
    
    // Try to equip to full inventory (should do nothing)
    alice.equip(source->createMateria("ice"));
    
    std::cout << "\nSlots\n";
    std::cout << "\n#######################\n";
    alice.use(0, eve);
    alice.use(1, eve);
    alice.use(2, eve);
    alice.use(3, eve);
    
    // Test invalid use (should do nothing)
    alice.use(4, eve);
    alice.use(-1, eve);
    
    // Test unequip
    alice.unequip(0);
    alice.unequip(0);
    alice.unequip(3);
    alice.use(0, eve); // Should do nothing now
    
    std::cout << "\nCopies\n";
    std::cout << "\n#######################\n";
    Character charlie(alice);
    charlie.use(1, eve);
    charlie.use(1, eve);
    charlie.use(0, eve);

    // Test copy assignment
    Character diana("Diana");
    diana = alice;
    diana.use(2, eve);
    
    // Test unknown materia type
    AMateria* unknown = source->createMateria("fire");
    if (!unknown)
        std::cout << "Unknown materia type" << std::endl;
    
    delete source;
    UnequippedMateria::cleanup();

    return 0;
}

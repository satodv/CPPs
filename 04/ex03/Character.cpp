#include "Character.hpp"
#include "UnequippedMateria.hpp"

Character::Character(const std::string& name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
}

Character::Character(const Character& other) : _name(other._name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        
        // Delete old materias
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = 0;
            }
        }
        
        // Copy new materias
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            std::cout << _name << " equips materia.\n";
            return;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
    {
        UnequippedMateria::add(_inventory[idx]);
        std::cout << _name << " unequips materia " << idx << std::endl;
        _inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
    {
        _inventory[idx]->use(target);
    }
}
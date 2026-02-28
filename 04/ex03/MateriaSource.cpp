#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = 0;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        // Delete old materias
        for (int i = 0; i < 4; i++)
        {
            if (_materias[i])
            {
                delete _materias[i];
                _materias[i] = 0;
            }
        }
        
        // Copy new materias
        for (int i = 0; i < 4; i++)
        {
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i])
            delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = m->clone();
            delete m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            std::cout << "Creates Materia " << type << std::endl;
            return _materias[i]->clone();
        }
    }
    return 0;
}
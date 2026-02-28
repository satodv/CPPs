#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
 Canonical form
 Default constructor
 *Custom constructor
 Copy constructor
 Copy assignment
 Destructor
*/
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = intVal << _fractionalBits;
}

Fixed::Fixed(const float floatVal) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(floatVal * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    _fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// << operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

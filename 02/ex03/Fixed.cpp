#include "Fixed.hpp"
#include <cmath>
#include <iostream>

/*
 Canonical form
 Default constructor
 *Custom constructor
 Copy constructor
 Copy assignment
 Destructor
*/
Fixed::Fixed() : _fixedPointValue(0) { 
    //std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const int intVal) { 
    //std::cout << "Int constructor called" << std::endl; 
    _fixedPointValue = intVal << _fractionalBits; 
}

Fixed::Fixed(const float floatVal) { 
    //std::cout << "Float constructor called" << std::endl; 
    _fixedPointValue = roundf(floatVal * (1 << _fractionalBits)); 
}

Fixed::Fixed(const Fixed& other) { 
    //std::cout << "Copy constructor called" << std::endl; 
    _fixedPointValue = other._fixedPointValue; 
}

Fixed& Fixed::operator=(const Fixed& other) {
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return *this;
}

Fixed::~Fixed() { 
    //std::cout << "Destructor called" << std::endl; 
}

// Getters/Setters
int Fixed::getRawBits() const { return _fixedPointValue; }

void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }

// Conversion
float Fixed::toFloat() const { 
    return (float)_fixedPointValue / (1 << _fractionalBits); 
}

int Fixed::toInt() const { return _fixedPointValue >> _fractionalBits; }

// <<
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

// Comparison
bool Fixed::operator>(const Fixed& other) const { return _fixedPointValue > other._fixedPointValue; }

bool Fixed::operator<(const Fixed& other) const { return _fixedPointValue < other._fixedPointValue; }

bool Fixed::operator>=(const Fixed& other) const { return _fixedPointValue >= other._fixedPointValue; }

bool Fixed::operator<=(const Fixed& other) const { return _fixedPointValue <= other._fixedPointValue; }

bool Fixed::operator==(const Fixed& other) const { return _fixedPointValue == other._fixedPointValue; }

bool Fixed::operator!=(const Fixed& other) const { return _fixedPointValue != other._fixedPointValue; }

// Arithmetic
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment / Decrement
Fixed& Fixed::operator++() {
    ++_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++_fixedPointValue;
    return temp;
}

Fixed& Fixed::operator--() {
    --_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --_fixedPointValue;
    return temp;
}

// Min / Max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

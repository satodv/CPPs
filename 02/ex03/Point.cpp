#include "Point.hpp"

/*  Canonical form
 Default constructor
 *Custom constructor
 Copy constructor
 Copy assignment
 Destructor
*/
Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY()) {}

Point& Point::operator=(const Point& other) {
    (void)other;
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }

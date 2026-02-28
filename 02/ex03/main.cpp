#include "Point.hpp"
#include <iostream>

extern bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point in(1, 1);
    Point edge(0, 5);
    Point ve(0, 0);
    Point out(20, 20);

    std::cout << "Inside: " << bsp(a, b, c, in) << std::endl;
    std::cout << "Edge: " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Vertex: " << bsp(a, b, c, ve) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, out) << std::endl;

    return 0;
}

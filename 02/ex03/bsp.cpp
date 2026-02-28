#include "Point.hpp"

//area = 1/2 *∣x1(y2-y3)+x2(y3​−y1)+x3(y1−y2)∣
static Fixed area(Point const a, Point const b, Point const c) {
    Fixed result(
        (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
         b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
         c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f
    );

    if (result < Fixed(0))
        result = result * Fixed(-1);

    return result;
}

// Area(ABC) = Area(PBC) + Area(APC) + Area(ABP)
//area == sub areas -> in
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = area(a, b, c);
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);

    // Edge/Vertex
    if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
        return false;

    return (totalArea == (area1 + area2 + area3));
}
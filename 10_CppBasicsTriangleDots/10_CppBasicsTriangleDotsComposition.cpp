#include "TriangleCompostion.h"
#include <iostream>

TriangleComposition::TriangleComposition(const Dot& d1, const Dot& d2, const Dot& d3)
    : dot1(d1), dot2(d2), dot3(d3) {
}

double TriangleComposition::calculatePerimeter() const {
    double side1 = dot1.distanceTo(dot2);
    double side2 = dot2.distanceTo(dot3);
    double side3 = dot3.distanceTo(dot1);

    return side1 + side2 + side3;
}

double TriangleComposition::calculateArea() const {
    double side1 = dot1.distanceTo(dot2);
    double side2 = dot2.distanceTo(dot3);
    double side3 = dot3.distanceTo(dot1);

    double halfPerimeter = (side1 + side2 + side3) / 2;
    return sqrt(halfPerimeter * (halfPerimeter - side1) * (halfPerimeter - side2) * (halfPerimeter - side3));
}

static int run() {
    Dot d1(0, 0);
    Dot d2(1, 2);
    Dot d3(1, 1);

    TriangleComposition triangleComp(d1, d2, d3);
    std::cout << "Composition:" << std::endl;
    std::cout << "Perimeter: " << triangleComp.calculatePerimeter() << std::endl;
    std::cout << "Area: " << triangleComp.calculateArea() << std::endl;

    return 0;
}
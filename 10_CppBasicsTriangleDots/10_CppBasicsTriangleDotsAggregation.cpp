#include "TriangleAggregation.h"
#include <iostream>

TriangleAggregation::TriangleAggregation(const Dot* d1, const Dot* d2, const Dot* d3)
    : dot1(d1), dot2(d2), dot3(d3) {
}

double TriangleAggregation::calculatePerimeter() const {
    double firstSide = dot1->distanceTo(*dot2);
    double secondSide = dot2->distanceTo(*dot3);
    double thirdSide = dot3->distanceTo(*dot1);

    return firstSide + secondSide + thirdSide;
}

double TriangleAggregation::calculateArea() const {
    double side1 = dot1->distanceTo(*dot2);
    double side2 = dot2->distanceTo(*dot3);
    double side3 = dot3->distanceTo(*dot1);

    double halfPerimeter = (side1 + side2 + side3) / 2;
    return sqrt(halfPerimeter * (halfPerimeter - side1) * (halfPerimeter - side2) * (halfPerimeter - side3));
}

int run() {
    Dot d1(0, 0);
    Dot d2(3, 0);
    Dot d3(0, 4);

    TriangleAggregation triangle(&d1, &d2, &d3);
    std::cout << "\nAggregation:" << std::endl;
    std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl;
    std::cout << "Area: " << triangle.calculateArea() << std::endl;

    return 0;
}

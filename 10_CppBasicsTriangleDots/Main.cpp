#include <iostream>
#include "TriangleCompostion.h"
#include "TriangleAggregation.h"

int main() {
    Dot d1(0, 0);
    Dot d2(1, 0);
    Dot d3(0, 2);

    TriangleComposition triangleComposition(d1, d2, d3);
    std::cout << "Composition:" << std::endl;
    std::cout << "Perimeter: " << triangleComposition.calculatePerimeter() << std::endl;
    std::cout << "Area: " << triangleComposition.calculateArea() << std::endl;

    TriangleAggregation triangleAggregation(&d1, &d2, &d3);
    std::cout << "\nAggregation:" << std::endl;
    std::cout << "Perimeter: " << triangleAggregation.calculatePerimeter() << std::endl;
    std::cout << "Area: " << triangleAggregation.calculateArea() << std::endl;

    return 0;
}
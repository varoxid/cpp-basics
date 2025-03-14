#ifndef TRIANGLE_AGGREGATION_H
#define TRIANGLE_AGGREGATION_H

#pragma once

#include "Dot.h"

class TriangleAggregation {
private:
    const Dot* dot1;
    const Dot* dot2;
    const Dot* dot3;

public:
    TriangleAggregation(const Dot* d1, const Dot* d2, const Dot* d3);
    double calculatePerimeter() const;
    double calculateArea() const;
};

#endif
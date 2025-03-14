#ifndef TRIANGLE_COMPOSITION_H
#define TRIANGLE_COMPOSITION_H

#pragma once

#include "Dot.h"

class TriangleComposition {
private:
    Dot dot1;
    Dot dot2;
    Dot dot3;

public:
    TriangleComposition(const Dot& d1, const Dot& d2, const Dot& d3);
    double calculatePerimeter() const;
    double calculateArea() const;
};

int run();

#endif
#include <iostream>
#include <cmath>

static double CalculateArea(double firstSide, double secondSide, double thirdSide) {
    double halfPerimeter = (firstSide + secondSide + thirdSide) / 2;
    return std::sqrt(halfPerimeter * (halfPerimeter - firstSide) * (halfPerimeter - secondSide) * (halfPerimeter - thirdSide));
}

static double CalculateArea(double side) {
    return (std::sqrt(3) / 4) * side * side;
}

int main() {
    int choice;
    std::cout << "Choose triangle:\n";
    std::cout << "1  Equilateral\n";
    std::cout << "2  Sided triangle\n";
    std::cin >> choice;

    if (choice == 1) {
        double side;
        std::cout << "Enter side: ";
        std::cin >> side;

        double area = CalculateArea(side);
        std::cout << "Area of an equilateral triangle: " << area << std::endl;
    }
    else if (choice == 2) {
        double firstSide, secondSide, thirdSide;
        std::cout << "Enter the lengths of the sides of an equilateral triangle (first second third): ";
        std::cin >> firstSide >> secondSide >> thirdSide;

        bool isValid = firstSide + secondSide > thirdSide && firstSide + thirdSide > secondSide && secondSide + thirdSide > firstSide;
        if (isValid) {
            double area = CalculateArea(firstSide, secondSide, thirdSide);
            std::cout << "Area of an equilateral triangle: " << area << std::endl;
        }
        else {
            std::cout << "Invalid triangle" << std::endl;
        }
    }
    else {
        std::cout << "Unknown choice" << std::endl;
    }

    return 0;
}
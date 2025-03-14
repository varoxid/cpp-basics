#include <iostream>
#include <cmath>

int calculateRoots(double, double, double, double&, double&);

int calculateRoots(double a, double b, double c, double& x1, double& x2) {
    double discriminant = b * b - 4 * a * c; 

    if (discriminant > 0) {
        x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        return 1;
    }
    else if (discriminant == 0) {
        x1 = -b / (2 * a);
        return 0;
    }
    else {
        return -1;
    }
}

int main() {
    double a, b, c;
    std::cout << "Enter the coefficients (a, b, c): ";
    std::cin >> a >> b >> c;

    double x1, x2;
    int result = calculateRoots(a, b, c, x1, x2);

    if (result == 1) {
        std::cout << "Roots: x1 = " << x1 << ", x2 = " << x2 << std::endl;
    }
    else if (result == 0) {
        std::cout << "One root: x1 = x2 = " << x1 << std::endl;
    }
    else {
        std::cout << "No roots" << std::endl;
    }

    return 0;
}
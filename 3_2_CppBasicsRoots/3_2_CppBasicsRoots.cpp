#include <iostream>
#include <cmath>
#include <iomanip>

static double CalculateWithPow(double a) {
    return pow(a, 1.0 / 3);
}

static double CalculateWithIterative(double number, double epsilon = 1e-6) {
    if (number == 0) {
        return 0;
    }

    double calculated = number; 
    double delta;
    do {
        double next = (2 * calculated + number / (calculated * calculated)) / 3; 
        delta = std::abs(next - calculated);
        calculated = next;
    } while (delta > epsilon); 

    return calculated;
}

int main() {
    double number;
    std::cout << "Enter number for cube root: ";
    std::cin >> number;

    double powVariant = CalculateWithPow(number);
    std::cout << "Using pow: " << std::fixed << std::setprecision(6) << powVariant << std::endl;

    double resultIterative = CalculateWithIterative(number);
    std::cout << "Using iterative: " << std::fixed << std::setprecision(6) << resultIterative << std::endl;

    return 0;
}
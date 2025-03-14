#include <iostream>
#include <cmath>

// we need to use "long long" type for big numbers
static bool IsPrime(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

static bool IsSuperPrime(int number) {
    while (number > 0) {
        if (!IsPrime(number)) {
            return false;
        }
        number /= 10; 
    }
    return true;
}

int main() {
    int number;
    std::cout << "Enter number: ";
    std::cin >> number;

    if (IsSuperPrime(number)) {
        std::cout << number << " supersimple." << std::endl;
    }
    else {
        std::cout << number << " not supersimple." << std::endl;
    }

    return 0;
}
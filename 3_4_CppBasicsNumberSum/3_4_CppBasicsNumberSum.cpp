#include <iostream>

static int CalculateSumRecursive(int n) {
    if (n == 0) {
        return 0; 
    }
    return 5 * n + CalculateSumRecursive(n - 1); 
}

int main() {
    int n;
    std::cout << "Enter n (n > 0): ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid n" << std::endl;
        return 1;
    }

    int sum = CalculateSumRecursive(n);
    std::cout << "Result sum : " << sum << std::endl;

    return 0;
}
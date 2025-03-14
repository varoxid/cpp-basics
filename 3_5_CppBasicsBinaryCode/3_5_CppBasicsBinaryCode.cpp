#include <iostream>

static void convertToBinary(int num) {
    if (num > 0) {
        convertToBinary(num / 2); 
        std::cout << num % 2;     
    }
}

int main() {
    int num;
    std::cout << "Enter number: ";
    std::cin >> num;

    std::cout << "Binary: ";
    if (num == 0) {
        std::cout << "0"; 
    }
    else {
        convertToBinary(num); 
    }
    std::cout << std::endl;

    return 0;
}
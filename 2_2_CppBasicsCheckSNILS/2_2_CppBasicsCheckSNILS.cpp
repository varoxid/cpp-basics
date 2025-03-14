#include <iostream>
#include <string>

int main() {
    std::string snils;
    std::cout << "Enter SNILS: ";
    std::cin >> snils;

    bool isNumbersCorrect = true;
    std::string shilsPart = snils.substr(0, 9);
    for (size_t i = 0; i < shilsPart.length() - 2; ++i) {
        if (shilsPart[i] == shilsPart[i + 1] && shilsPart[i] == shilsPart[i + 2]) {
            isNumbersCorrect = false;
            break;
        }
    }

    bool isValidControlNumber = false;
    if (isNumbersCorrect) {
        int sum = 0;
        for (size_t i = 0; i < 9; ++i) {
            int digit = shilsPart[i] - '0';
            sum += digit * (9 - i);
        }

        int controlNumber;
        if (sum < 100) {
            controlNumber = sum;
        }
        else if (sum == 100 || sum == 101) {
            controlNumber = 0;
        }
        else {
            controlNumber = sum % 101;
            if (controlNumber == 100) {
                controlNumber = 0;
            }
        }

        int currentControlNumber = std::stoi(snils.substr(9, 2));
        controlNumber == currentControlNumber;
        isValidControlNumber = controlNumber == currentControlNumber;
    }

    if (isNumbersCorrect && isValidControlNumber) {
        std::cout << "Valid SNILS" << std::endl;
    }
    else {
        std::cout << "Not valid SNILS" << std::endl;
    }

    return 0;
}
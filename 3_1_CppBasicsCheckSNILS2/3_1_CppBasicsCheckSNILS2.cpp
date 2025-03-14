#include <iostream>
#include <string>
#include <algorithm>

static std::string removeRedundantChars(const std::string& input) {
    std::string fixed;
    for (char ch : input) {
        if (isdigit(ch)) {
            fixed += ch;
        }
        else if (ch != ' ' && ch != '-') {
            return "";
        }
    }
    return fixed;
}

static bool isValid(const std::string& snilsValue) {
    std::string fixedValue = removeRedundantChars(snilsValue);
    if (fixedValue.empty() || fixedValue.length() != 11) {
        return false; 
    }

    for (size_t i = 0; i < fixedValue.length() - 2; ++i) {
        if (fixedValue[i] == fixedValue[i + 1] 
            && fixedValue[i] == fixedValue[i + 2]) {
            return false;
        }
    }

    int sum = 0;
    for (size_t i = 0; i < 9; ++i) {
        int digit = fixedValue[i] - '0';
        sum += digit * (9 - i);
    }

    int checkNumber = 0;
    if (sum < 100) {
        checkNumber = sum;
    }
    else if (sum == 100 || sum == 101) {
        checkNumber = 0;
    }
    else {
        checkNumber = sum % 101;
        
        if (checkNumber == 100) {
            checkNumber = 0;
        }
    }

    return checkNumber == std::stoi(fixedValue.substr(9, 2));
}

int main() {
    std::string snils;
    std::cout << "Enter SNILS: ";
    std::getline(std::cin, snils);

    if (isValid(snils)) {
        std::cout << "Valid SNILS" << std::endl;
    }
    else {
        std::cout << "Invalid SNILS" << std::endl;
    }

    return 0;
}
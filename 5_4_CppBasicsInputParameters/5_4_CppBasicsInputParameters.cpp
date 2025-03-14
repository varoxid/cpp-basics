#include <iostream>
#include <cstring> 
#include <cstdlib> 
using namespace std;


int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Invalid arguments count" << endl;
        return 1;
    }

    if (strncmp(argv[1], "-a", 2) != 0 && strncmp(argv[1], "-m", 2) != 0) {
        cerr << "Invalid format" << endl;
        return 1;
    }

    int firstNumber = atoi(argv[2]);
    int secondNumber = atoi(argv[3]);

    if (firstNumber == 0 && argv[2][0] != '0') {
        cerr << "Invalid first argument" << endl;
        return 1;
    }
    if (secondNumber == 0 && argv[3][0] != '0') {
        cerr << "Invalid second argument" << endl;
        return 1;
    }

    if (strncmp(argv[1], "-a", 2) == 0) {
        cout << "Sum: " << firstNumber + secondNumber << endl;
    }
    else if (strncmp(argv[1], "-m", 2) == 0) {
        cout << "Product: " << firstNumber * secondNumber << endl;
    }

    return 0;
}
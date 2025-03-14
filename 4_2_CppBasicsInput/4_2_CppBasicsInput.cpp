#include <iostream>

using namespace std;

static bool validateInput(int& a, int& b) {
    cout << "Enter numbers (a и b): ";
  
    if (!(cin >> a >> b)) {
        return false; 
    }

    return true; 
}

int main() {
    int a, b;

    if (validateInput(a, b) == false) {
        cerr << "error" << endl;
        return 1;
    }

    int s = a + b;
    cout << "Sum: " << s << endl;

    return 0;
}
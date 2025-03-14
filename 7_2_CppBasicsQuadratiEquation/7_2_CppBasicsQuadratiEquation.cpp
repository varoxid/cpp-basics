#include <iostream>
#include <cmath>
using namespace std;

struct EquationResult {
    double firstRoot;
    double secondRoot;
    bool hasRoots;
};

static EquationResult getQuadraticEquationRoots(double a, double b, double c) {
    EquationResult result{};
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        result.firstRoot = (-b + sqrt(discriminant)) / (2 * a);
        result.secondRoot = (-b - sqrt(discriminant)) / (2 * a);
        result.hasRoots = true;
    }
    else if (discriminant == 0) {
        result.firstRoot = result.secondRoot = -b / (2 * a);
        result.hasRoots = true;
    }
    else {
        cout << "No roots" << endl;
        result.firstRoot = result.secondRoot = NULL;
        result.hasRoots = false;
    }

    return result;
}

int main() {
    double a, b, c;

    cout << "Enter coefficients (a, b, c): ";
    cin >> a >> b >> c;

    if (a == 0) {
        cerr << "Invlaid: 'a' should be greater than 0" << endl;
        return 1;
    }

    const EquationResult result = getQuadraticEquationRoots(a, b, c);

    if (result.hasRoots) {
        if (result.firstRoot == result.secondRoot) {
            cout << "One root:" << endl 
                 << "x = " << result.firstRoot << endl;
        }
        else {
            cout << "Two roots:" << endl
                 << "x1 = " << result.firstRoot << "," << endl
                 <<" x2 = " << result.secondRoot << endl;
        }
    }

    return 0;
}
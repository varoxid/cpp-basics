#include <iostream>
#include <tuple> 
#include <cmath>
using namespace std;

using Tuple = tuple<double, double, bool, bool>;

static Tuple getQuadraticEquationRoots(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double firstRoot = (-b + sqrt(discriminant)) / (2 * a);
        double secondRoot = (-b - sqrt(discriminant)) / (2 * a);
        double hasTwoRoots = true;
        return make_tuple(firstRoot, secondRoot, hasTwoRoots, false);
    }
    else if (discriminant == 0) {
        double firstRoot = -b / (2 * a);
        double hasOneRoot = true;
        return make_tuple(firstRoot, NULL, false, hasOneRoot);
    }
    else {
        return make_tuple(NULL, NULL, false, false);
    }
}

int main() {
    double a, b, c;

    cout << "Enter coefficients (a, b, c): ";
    cin >> a >> b >> c;

    if (a == 0) {
        cerr << "Invlaid: 'a' should be greater than 0" << endl;
        return 1;
    }

    auto result = getQuadraticEquationRoots(a, b, c);
    double firstRoot = std::get<0>(result);
    double secondRoot = std::get<1>(result);
    double hasTwoRoots = std::get<2>(result);
    double hasOneRoot = std::get<3>(result);

    if (hasTwoRoots) {
        cout << "Two roots:" << endl
            << "x1 = " << firstRoot << "," << endl
            << "x2 = " << secondRoot << endl;
    }
    else if (hasOneRoot) {
        cout << "One root:" << endl
             << "x = " << firstRoot << endl;
    }
    else {
        cout << "No roots" << endl;
    }

    return 0;
}
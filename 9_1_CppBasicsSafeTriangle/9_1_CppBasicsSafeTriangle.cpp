#include <iostream>
#include <cmath>

using namespace std;

class IllegalTriangleException
{
public:
    IllegalTriangleException() : message("Invalid triangle") {}
    void printMessage()  const { cout << message << endl; }
private:
    string message;
};


class Triangle {
private:
    double firstSide;
    double secondSide;
    double thirdSide;

    bool isInvalidTriangle(double a, double b, double c) const {
        return !((a + b > c) && (a + c > b) && (b + c > a));
    }

public:
    Triangle(double a, double b, double c) {
        if (isInvalidTriangle(a, b, c)) {
            throw IllegalTriangleException();
        }
        firstSide = a;
        secondSide = b;
        thirdSide = c;
    }

    double calculateArea() const {
        double halfPerimeter = (firstSide + secondSide + thirdSide) / 2; 
        return sqrt(halfPerimeter 
            * (halfPerimeter - firstSide) 
            * (halfPerimeter - secondSide) 
            * (halfPerimeter - thirdSide));
    }
};

int main() {
    try {
        const Triangle validTriangle(3, 4, 5);
        cout << "Triangle area: " << validTriangle.calculateArea() << endl;
        
        const Triangle invalidTriangle(1, 2, 10);
        cout << "Triangle area: " << invalidTriangle.calculateArea() << endl;
    }
    catch (const IllegalTriangleException& e) {
        e.printMessage();
    }

    return 0;
}
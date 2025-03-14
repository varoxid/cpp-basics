#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Point {
private:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0) 
        : x(x), y(y) {}

    double calculateDistance() const {
        return std::sqrt(x * x + y * y);
    }

    friend std::ostream& operator<<(std::ostream& osstrm, const Point& point);

    bool operator<(const Point& point) const {
        return calculateDistance() < point.calculateDistance();
    }
};

std::ostream& operator<<(std::ostream& osstrm, const Point& point) {
    osstrm << "[" << point.x << " " << point.y << "]";
    return osstrm;
}

int main() {
    std::vector<Point> points;
    points.push_back(Point(1, 1));
    points.push_back(Point(2, 7));
    points.push_back(Point(8, 9));
    points.push_back(Point(3, 9));

    std::sort(points.begin(), points.end());

    for (auto& point : points) {
        std::cout << point << '\n';
    }

    return 0;
}
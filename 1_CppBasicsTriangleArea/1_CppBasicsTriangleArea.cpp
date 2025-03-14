#include <iostream>
#include <vector>
#include <cmath>

struct Vertice {
    double x;
    double y;
};

double CalculateArea(const std::vector<Vertice>& vertices) {
    double area = 0.0;
    size_t n = vertices.size();

    for (size_t i = 0; i < n; ++i) {
        size_t next = (i + 1) % n; 
        area += (vertices[i].x * vertices[next].y - vertices[next].x * vertices[i].y);
    }

    return std::abs(area) / 2.0;
}

int main() {
    std::vector<Vertice> vertices(5);

    std::cout << "Enter the coordinates of the vertices of the pentagon (x y):" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Vertice " << i + 1 << ": ";
        std::cin >> vertices[i].x >> vertices[i].y;
    }

    double area = CalculateArea(vertices);
    std::cout << "The area of a pentagon: " << area << std::endl;

    return 0;
}

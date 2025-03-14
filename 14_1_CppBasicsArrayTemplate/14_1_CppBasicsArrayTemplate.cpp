#include <iostream>
using namespace std;

template <typename T>
double calculateAverage(const T* source, int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += source[i];
    }

    return static_cast<double>(sum) / size;
}

int main() {

    char chars[] = { 'a', 'b', 'c', 'd', 'e' };
    cout << "Average: " << calculateAverage(chars, sizeof(chars) / sizeof(chars[0])) << endl;

    int ints[] = { 1, 2, 3, 4, 5 };
    cout << "Average: " << calculateAverage(ints, sizeof(ints) / sizeof(ints[0])) << endl;

    long longs[] = { 100L, 120L, 255L, 280L};
    cout << "Average: " << calculateAverage(longs, sizeof(longs) / sizeof(longs[0])) << endl;

    double doubles[] = { 1.3, 3.2, 5.9};
    cout << "Average: " << calculateAverage(doubles, sizeof(doubles) / sizeof(doubles[0])) << endl;

    return 0;
}
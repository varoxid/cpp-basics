#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename Collection>
void Print(const Collection& collection, const std::string& delimiter) {
    bool isFirst = true;

    for (const auto& element : collection) {
        if (!isFirst) {
            std::cout << delimiter; 
        }
        std::cout << element; 
        isFirst = false;     
    }
    std::cout << endl; 
}

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    std::list<std::string> objects = { "car", "house", "city" };
    int numberArray[] = { 100, 300, 400 };

    Print(numbers, ", ");       
    Print(objects, " || ");     
    Print(numberArray, " # ");     

    return 0;
}
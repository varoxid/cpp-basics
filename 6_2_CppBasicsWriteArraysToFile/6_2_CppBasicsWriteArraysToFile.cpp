#include <iostream>
#include <vector>
#include <limits>
#include <fstream>

static std::vector<int> fillArray(int size) {
    std::vector<int> filledArray(size);
    std::cout << "Enter " << size << " elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> filledArray[i];
    }
    return filledArray;
}

static void doSort(std::vector<int>& inputArray) {
    for (size_t i = 0; i < inputArray.size() - 1; ++i) {
        for (size_t j = 0; j < inputArray.size() - i - 1; ++j) {
            if (inputArray[j] > inputArray[j + 1]) {
                std::swap(inputArray[j], inputArray[j + 1]);
            }
        }
    }
}

static void writeToFile(const std::string& message, const std::vector<int>& inputArray, const std::string& filename = "output.txt") {
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile) {
        std::cerr << "Invalid file!" << std::endl;
        return;
    }

    outFile << message << std::endl;
    for (int num : inputArray) {
        outFile << num << " ";
    }
    outFile << std::endl;

    outFile.close();
}

int main() {
    int size;
    std::cout << "Enter elements count: ";
    std::cin >> size;

    std::vector<int> sourceArray = fillArray(size);

    writeToFile("Original array: ", sourceArray);
    doSort(sourceArray);
    writeToFile("Sorted array: ", sourceArray);
    std::cout << "Finished..." << std::endl;

    return 0;
}
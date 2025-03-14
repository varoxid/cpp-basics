#include <iostream>
#include <vector>
#include <limits>

static std::vector<int> fillArray(int size) {
    std::vector<int> filledArray(size);
    std::cout << "Enter " << size << " elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> filledArray[i];
    }
    return filledArray;
}

static int getSumNegatives(const std::vector<int>& inputArray) {
    int sum = 0;
    for (int num : inputArray) {
        if (num < 0) {
            sum += num;
        }
    }
    return sum;
}

static int getSumPositives(const std::vector<int>& inputArray) {
    int sum = 0;
    for (int num : inputArray) {
        if (num > 0) {
            sum += num;
        }
    }
    return sum;
}

static int getSumOdd(const std::vector<int>& inputArray) {
    int sum = 0;
    for (size_t i = 1; i < inputArray.size(); i += 2) {
        sum += inputArray[i];
    }
    return sum;
}

static int getSumEven(const std::vector<int>& inputArray) {
    int sum = 0;
    for (size_t i = 0; i < inputArray.size(); i += 2) {
        sum += inputArray[i];
    }
    return sum;
}

static void getMinMax(const std::vector<int>& inputArray, int& minVal, int& maxVal, int& minIndex, int& maxIndex) {
    minVal = std::numeric_limits<int>::max();
    maxVal = std::numeric_limits<int>::min();
    minIndex = maxIndex = 0;

    for (size_t i = 0; i < inputArray.size(); ++i) {
        if (inputArray[i] < minVal) {
            minVal = inputArray[i];
            minIndex = i;
        }
        if (inputArray[i] > maxVal) {
            maxVal = inputArray[i];
            maxIndex = i;
        }
    }
}

static int getProductBetweenMinMax(const std::vector<int>& inputArray) {
    int minVal, maxVal, minIndex, maxIndex;
    getMinMax(inputArray, minVal, maxVal, minIndex, maxIndex);

    if (minIndex > maxIndex) {
        std::swap(minIndex, maxIndex);
    }

    int product = 1;
    for (int i = minIndex + 1; i < maxIndex; ++i) {
        product *= inputArray[i];
    }
    return product;
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

static void printArray(const std::vector<int>& inputArray) {
    for (int num : inputArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    int size;
    std::cout << "Enter element count: ";
    std::cin >> size;

    std::vector<int> sourceArray = fillArray(size);

    std::cout << "Sum of negatives elements: " << getSumNegatives(sourceArray) << std::endl;
    std::cout << "Sum of positives elements: " << getSumPositives(sourceArray) << std::endl;
    std::cout << "Sum of odds elements: " << getSumOdd(sourceArray) << std::endl;
    std::cout << "Sum of even elements: " << getSumEven(sourceArray) << std::endl;
    int minVal, maxVal, minIndex, maxIndex;
    getMinMax(sourceArray, minVal, maxVal, minIndex, maxIndex);
    
    std::cout << "Min: " << minVal << "[ " << minIndex << " ]" << std::endl;
    std::cout << "Max: " << maxVal << "[ " << maxIndex << " ]" << std::endl;
    std::cout << "Product between min and max elements: " << getProductBetweenMinMax(sourceArray) << std::endl;
    
    std::cout << "Original array: ";
    printArray(sourceArray);
    
    doSort(sourceArray);
    std::cout << "Sorted array: ";
    printArray(sourceArray);

    return 0;
}
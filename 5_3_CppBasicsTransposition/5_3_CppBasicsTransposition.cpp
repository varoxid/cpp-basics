#include <iostream>
using namespace std;

static int search(int arr[], int size, int searchElement) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchElement) {
            if (i > 0) {
                swap(arr[i], arr[i - 1]);
                return i - 1; 
            }
            return i; 
        }
    }
    return -1; 
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter element: ";
    cin >> key;

    int index = search(arr, size, key);

    if (index != -1) {
        cout << "Element has been found: " << index << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    cout << "Result array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
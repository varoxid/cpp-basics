#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outputFile("output.txt"); 

    if (!outputFile.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    cout << "Add text:" << endl;

    string line;
    while (true) {
        
        getline(cin, line);
        
        if (line.empty()) {
            break;
        }
        
        outputFile << line << endl;
    }

    outputFile.close();

    cout << "Done!" << endl;

    return 0;
}
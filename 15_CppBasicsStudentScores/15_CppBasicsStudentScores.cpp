#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, char> studentGradesMap;

    studentGradesMap["Student1"] = '5';
    studentGradesMap["Student2"] = '5';
    studentGradesMap["Student3"] = '4';
    studentGradesMap["Student4"] = '3';

    std::string name;
    std::cout << "Enter student name: ";
    std::cin >> name;

    if (studentGradesMap.find(name) != studentGradesMap.end()) {
        char grade;
        std::cout << "Enter grade (5, 4, 3, 2): ";
        std::cin >> grade;
        studentGradesMap[name] = grade;
        std::cout << "Grade has been updated." << std::endl;
    }
    else {
        std::cout << "No student" << std::endl;
    }

    std::cout << "Student grades:" << std::endl;
    for (const auto& element : studentGradesMap) {
        std::cout << element.first << " = " << element.second << std::endl;
    }

    return 0;
}

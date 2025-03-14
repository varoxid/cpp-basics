#include <iostream>
#include <map>
#include <string>


class StudentGradeService {
private:
    std::map<std::string, char> studentGrades;

public:
    void addGrade(const std::string& name, char grade) {
        studentGrades[name] = grade;
    }

    char getGrade(const std::string& studentName) const {
        auto it = studentGrades.find(studentName);
        if (it != studentGrades.end()) {
            return it->second;
        }
        return '\0';
    }
};
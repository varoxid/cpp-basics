#include <iostream>
#include <vector>
#include "Human.h"
#include "Student.h"
#include "Teacher.h"

int main() {
    std::vector<int> scores = { 5, 3, 4, 4, 5, 3, 3, 3, 3 };
    Student* student = new Student("Surname1", "Name1", "SecondName1", scores);

    unsigned int teacher_work_time = 40;
    Teacher* teacher = new Teacher("Surname2", "Name2", "SecondName2", teacher_work_time);

    Human* people[] = { student, teacher };

    for (Human* person : people) {
        std::cout << person->getInfo() << "\n\n";
    }

    delete student;
    delete teacher;

    return 0;
}
#pragma once
#ifndef TEACHER_H
#define TEACHER_H

#include "Human.h"
#include <string>

class Teacher : public Human {
public:
    Teacher(std::string last_name, std::string name, std::string second_name, unsigned int work_time)
        : Human(last_name, name, second_name), work_time(work_time) {
    }

    std::string getInfo() const override {
        std::ostringstream full_info;
        full_info << Human::getInfo() << "\nWork hours count: " << work_time;
        return full_info.str();
    }

private:
    unsigned int work_time;
};

#endif // TEACHER_H
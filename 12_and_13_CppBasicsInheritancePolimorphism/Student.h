#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "Human.h"
#include <vector>
#include <string>

class Student : public Human {
public:
    Student(std::string last_name, std::string name, std::string second_name, std::vector<int> scores)
        : Human(last_name, name, second_name), scores(scores) {
    }

    std::string getInfo() const override {
        std::ostringstream full_info;
        full_info << Human::getInfo() << "\nAverage score: " << get_average_score();
        return full_info.str();
    }

    float get_average_score() const {
        unsigned int count_scores = scores.size();
        unsigned int sum_scores = 0;
        for (unsigned int i = 0; i < count_scores; ++i) {
            sum_scores += scores[i];
        }
        return (float)sum_scores / (float)count_scores;
    }

private:
    std::vector<int> scores;
};

#endif // STUDENT_H
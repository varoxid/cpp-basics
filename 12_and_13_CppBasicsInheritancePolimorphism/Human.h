#pragma once

#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include <sstream>

class Human {
public:
    Human(std::string last_name, std::string name, std::string second_name)
        : last_name(last_name), name(name), second_name(second_name) {
    }

    virtual ~Human() {} 

    virtual std::string getInfo() const {
        std::ostringstream full_name;
        full_name << last_name << " " << name << " " << second_name;
        return full_name.str();
    }

protected:
    std::string name;
    std::string last_name;
    std::string second_name;
};

#endif // HUMAN_H
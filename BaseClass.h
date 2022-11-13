//
// Created by ki on 13.11.22.
//
#ifndef TIMEHELPER_BASECLASS_H
#define TIMEHELPER_BASECLASS_H
#include <string>
#include <ctime>

class BaseClass {
private:
    std::string name;
    std::time_t beginTime{};
    std::time_t endTime{};
    int duration{};
    int countOfIterations{};
public:
    BaseClass(std::string name);
};


#endif //TIMEHELPER_BASECLASS_H

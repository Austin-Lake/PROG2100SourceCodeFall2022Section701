//
// Created by W0420180 on 2022-10-24.
//
#include <string>
#include <iostream>
using namespace std;

#ifndef ASSIGNMENT__2_STUDENTCOURSE_H
#define ASSIGNMENT__2_STUDENTCOURSE_H

class StudentCourse {

private:
    string studentName;
    string *courseList = new string;
public:
    StudentCourse() = default;
    ~StudentCourse() = default;

    void AddName(string &name);

    void AddCourse(string &course);

    void PrintInformation();
};

#endif //ASSIGNMENT__2_STUDENTCOURSE_H



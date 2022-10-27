//
// Created by W0420180 on 2022-10-24.
//
#include <string>
#include <iostream>
using namespace std;

#ifndef ASSIGNMENT__2_STUDENT_H
#define ASSIGNMENT__2_STUDENT_H

class Student {

private:
    string studentName;
    string *courseList = new string;
public:
    Student() = default;
    ~Student() = default;

    void AddName(string &name);

    void AddCourse(string &course);

    void PrintInformation();
};

//StudentCourse resizeArray(StudentCourse *studentArray, int size);

#endif //ASSIGNMENT__2_STUDENT_H



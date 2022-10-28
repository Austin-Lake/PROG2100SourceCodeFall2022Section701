//
// Created by W0420180 on 2022-10-24.
//

#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

void Student::AddName(string &name) {
    studentName = name;
}

void Student::AddCourse(string &course) {
    if (i >= size) {
        size *= 2;
        auto *temp = new string[size];

        for (int j = 0; j < i; j++) {
            temp[j] = courseList[j];
        }

        delete []courseList;

        courseList = temp;
    }
    courseList[i] = course;
    i++;
}

void Student::PrintInformation() {
    cout << "Student: " << studentName << endl;

    for (int j = 0; j < i; j++) {
        cout << "   Course " << "#" << j+1 << ": " << courseList[j] << endl;
    }
}
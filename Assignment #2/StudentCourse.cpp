//
// Created by W0420180 on 2022-10-24.
//

#include "StudentCourse.h"
#include <string>
#include <iostream>
using namespace std;

void StudentCourse::AddName(string &name) {
    this->studentName = name;
}

void StudentCourse::AddCourse(string &course) {
    this->courseList->append(course);
}

void StudentCourse::PrintInformation() {
    cout << studentName << endl;

    for (char course : *courseList) {
        cout << course << endl;
    }
}
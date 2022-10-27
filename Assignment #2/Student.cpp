//
// Created by W0420180 on 2022-10-24.
//

#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

void Student::AddName(string &name) {
    this->studentName = name;
}

void Student::AddCourse(string &course) {
    this->courseList->append(course);
}

void Student::PrintInformation() {
    cout << studentName << endl;

    for (int i = 0; i < sizeof(*courseList)/sizeof(courseList[0]); i++) {
        cout << "Course " << "#" << i << ":" << courseList[i] << endl;
    }
}
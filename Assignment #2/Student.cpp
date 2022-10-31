//
// Created by W0420180 on 2022-10-24.
//

#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student() {

}
// Copy Constructor to hard copy
Student::Student(const Student &student) {
    cout << "Copy Constructor Executed!" << endl;

    numCourses = student.numCourses;
    courseList = new string[numCourses];

    for (int i = 0; i < numCourses; i++)
        courseList[i] = student.courseList[i];
}

Student::~Student() {
    cout << "Deconstructor Executed!" << endl;
    if (courseList != nullptr) {
        delete []courseList;
        courseList = nullptr;
    }
}

void Student::SetName(string &name) {
    studentName = name;
}

void Student::AddCourse(string &course, int &size) {
    if (numCourses >= size) {
        size *= 2;
        auto *temp = new string[size];

        for (int j = 0; j < numCourses; j++)
            temp[j] = courseList[j];


        delete []courseList;

        courseList = temp;
    }
    courseList[numCourses] = course;
    numCourses++;
}

void Student::ResetCourseList() {
    numCourses = 0;
    delete []courseList;
    courseList = new string[2];
}

void Student::PrintInformation() {
    cout << "Student: " << studentName << endl;
    cout << "Number of Courses = " << numCourses << endl;
    for (int j = 0; j < numCourses; j++) {
        cout << "   Course " << "#" << j+1 << ": " << courseList[j] << endl;
    }
}
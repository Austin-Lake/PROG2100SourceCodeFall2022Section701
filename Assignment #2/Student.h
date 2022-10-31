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
    int numCourses = 0;
    string *courseList = new string[2];
public:
    Student();
    Student(const Student &student);
    ~Student();

//    Student &operator+ (Student &student) {
//        cout << "Assignment Operator Fired!" << endl;
//        int count = this->numCourses;
//        student.courseList = new string[count];
//
//        for (int i = 0; i < count; i++) {
//            student.courseList[i] = this->courseList[i];
//        }
//
//        return student;
//    }
    Student &operator=(const Student &student) {
        cout << "Assignment Operator Fired!" << endl;
        delete []this->courseList;
        this->courseList = new string[student.numCourses];
        this->numCourses = student.numCourses;

        for (int i = 0; i < student.numCourses; i++) {
            this->courseList[i] = student.courseList[i];
        }
        cout << "\n\n";
        return *this;
    }

    void SetName(string &name);

    void AddCourse(string &course, int &size);

    void ResetCourseList();

    void PrintInformation();
};


#endif //ASSIGNMENT__2_STUDENT_H



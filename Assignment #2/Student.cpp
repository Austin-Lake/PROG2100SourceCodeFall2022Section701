//
// Created by W0420180 on 2022-10-24.
//

#include "Student.h"
#include <string>
#include <iostream>
using namespace std;
// Student Class Implementations

// Default Constructor
Student::Student() {

}
// Copy Constructor to hard copy course list from one student object to another
Student::Student(const Student &student) {
    cout << "Copy Constructor Fired!" << "\n" << endl;

    // Assign member variables from the original student object to the new object
    numCourses = student.numCourses;
    courseList = new string[numCourses];

    for (int i = 0; i < numCourses; i++)
        courseList[i] = student.courseList[i];
}

// Deconstructor to delete course list array from dynamic memory and assign a null pointer in its place
Student::~Student() {
    cout << "Deconstructor Fired! for Student: " << studentName << "\n" << endl;

    if (courseList != nullptr) {
        delete []courseList;
        courseList = nullptr;
    }
}

// Set Name method to assign student object's name
void Student::SetName(string &name) {
    studentName = name;
}

// Add Course method to add a new course to the course list array and resize the dynamic array if necessary
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

// Reset Course List method to set number of courses to zero,
// delete all values in the current array and assign a new default sized array in its place
void Student::ResetCourseList() {
    numCourses = 0;
    delete []courseList;
    courseList = new string[2];
}

// Output method to print all the member values of the student object
void Student::PrintInformation() {
    cout << "Student: " << studentName << endl;
    cout << "Number of Courses = " << numCourses << endl;
    cout << *this;

    cout << "\n";
}
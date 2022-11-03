#include "Student.h"
#include <iostream>
using namespace std;

int main() {
    // Infinite Loop
    while(true) {
        // Variables to store student's name and course list details
        string name;
        int courseSize = 2;
        bool anotherCourse = true;

        // Student one object
        Student studentOne;
        // Get Student one name
        cout << "Enter first student's name: " << endl;
        cin >> name;

        // Set Student one name
        studentOne.SetName(name);

        // Repeatedly add courses that user enters
        while (anotherCourse) {
            // Course variables
            string course;
            string addCourse;
            // Get Course name
            cout << "Enter course: " << endl;
            cin >> course;

            // Add course to Student one object
            studentOne.AddCourse(course, courseSize);
            // Ask if another course is to be entered
            cout << "Add another course? y/N: " << endl;
            cin >> addCourse;
            // Check whether to reiterate and add another course
            if (addCourse == "y")
                anotherCourse = true;
            else
                anotherCourse = false;
        }

        // Print Student one object information
        studentOne.PrintInformation();

        // Get Student two name
        cout << "Enter second student's name: " << endl;
        cin >> name;

        // Instantiate Student two object with copy constructor passing in Student one object
        Student studentTwo(studentOne);
        // Set name of Student two object
        studentTwo.SetName(name);
        // Reset course list of Student one object
        studentOne.ResetCourseList();
        // Print information of Student two object
        studentTwo.PrintInformation();
        // Print information of Student one object again
        studentOne.PrintInformation();

        // Get Student three name
        cout << "Enter third student's name: " << endl;
        cin >> name;
        // Create Student three object with default constructor
        Student studentThree;
        // Set Student three name
        studentThree.SetName(name);
        // Uses Overloaded Assignment Operator to hard copy Student two course list to Student three
        studentThree = studentTwo;
        // Print Student three object
        studentThree.PrintInformation();

        // Reiterate through loop
    }
}

#include "Student.h"
#include <iostream>
using namespace std;

int main() {
    // Infinite Loop
    while(true) {
        string name;
        int courseSize = 2;
        bool anotherCourse = true;

        // Student one object
        Student studentOne;
        // Get Student one name
        cout << "Enter student name: " << endl;
        cin >> name;

        // Set Student one name
        studentOne.SetName(name);

        // Loop to repeatedly add courses until user specifies otherwise
        while (anotherCourse) {
            string course;
            string addCourse;

            cout << "Enter course: " << endl;
            cin >> course;

            // Add course to Student one object
            studentOne.AddCourse(course, courseSize);

            cout << "Add another course? y/n: " << endl;
            cin >> addCourse;

            if (addCourse == "y")
                anotherCourse = true;
            else
                anotherCourse = false;
        }

        // Print Student one object information
        studentOne.PrintInformation();

        // Get Student two name
        cout << "Enter Second Student's Name: " << endl;
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
        cout << "Enter Third Student's Name: " << endl;
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

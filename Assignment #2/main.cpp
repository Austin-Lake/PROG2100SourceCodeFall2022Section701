#include "Student.h"
#include <iostream>
using namespace std;

int main() {

    while(true) {
        string name;
        int courseSize = 2;
        bool anotherCourse = true;

        Student studentOne;

        cout << "Enter student name: " << endl;
        cin >> name;

        studentOne.SetName(name);

        while (anotherCourse) {
            string course;
            string addCourse;

            cout << "Enter course: " << endl;
            cin >> course;

            studentOne.AddCourse(course, courseSize);

            cout << "Add another course? y/n: " << endl;
            cin >> addCourse;

            if (addCourse == "y")
                anotherCourse = true;
            else
                anotherCourse = false;
        }

        studentOne.PrintInformation();

        cout << "Enter Second Student's Name: " << endl;
        cin >> name;

        Student studentTwo(studentOne);
        studentTwo.SetName(name);

        studentOne.ResetCourseList();

        studentTwo.PrintInformation();

        studentOne.PrintInformation();

        cout << "Enter Third Student's Name: " << endl;
        cin >> name;

        Student studentThree;
        studentThree.SetName(name);
        studentThree = studentTwo;
        studentThree.PrintInformation();
    }

    return 0;
}

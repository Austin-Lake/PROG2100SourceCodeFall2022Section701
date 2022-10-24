#include "StudentCourse.h"
#include <iostream>
using namespace std;

int main() {
    string name;
    bool anotherCourse = true;
    bool anotherStudent = true;
    auto *students = new StudentCourse;

    while (anotherStudent) {
        StudentCourse student;

        cout << "Enter student name: " << endl;
        cin >> name;

        student.AddName(name);

        while (anotherCourse) {
            string course;
            string addCourse;

            cout << "Enter course: " << endl;
            cin >> course;

            cout << "Add another course? y/n: " << endl;
            cin >> addCourse;

            if (addCourse == "y")
                anotherCourse = true;
            else
                anotherCourse = false;

            student.AddCourse(course);
        }

        string addStudent;

        cout << "Add another student? y/n: " << endl;
        cin >> addStudent;

        if (addStudent == "y")
            anotherStudent = true;
        else
            anotherStudent = false;


    }

    return 0;
}

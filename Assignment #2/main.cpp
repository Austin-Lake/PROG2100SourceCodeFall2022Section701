#include "Student.h"
#include <iostream>
using namespace std;

int main() {
    string name;
    int size = 3;
    int i = 0;
    bool anotherCourse = true;
    bool anotherStudent = true;
    auto *students = new Student[size];

    while (anotherStudent) {
        Student student;

        cout << "Enter student name: " << endl;
        cin >> name;

        student.AddName(name);

        while (anotherCourse) {
            string course;
            string addCourse;

            cout << "Enter course: " << endl;
            cin >> course;

            student.AddCourse(course);

            cout << "Add another course? y/n: " << endl;
            cin >> addCourse;

            if (addCourse == "y")
                anotherCourse = true;
            else
                anotherCourse = false;

            cout << "Finished loop" << endl;
        }
        cout << i << endl;
        if (i >= size) {
            size++;

            auto *temp = new Student[size];

            for (int j = 0; j <= i; j++) {
                temp[i] = students[i];
            }

            delete []students;

            students = temp;
        }

        students[i] = student;

        string addStudent;
        cout << "Add another student? y/n: " << endl;
        cin >> addStudent;

        if (addStudent == "y")
            anotherStudent = true;
        else
            anotherStudent = false;

        anotherCourse = true;
        i++;
    }

    for (int j = 0; j <= i; j++)
    {
        students[j].PrintInformation();
    }

    return 0;
}

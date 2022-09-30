// KIIT - Question 2 - 2
// Create a class which stores name, roll number and total marks for a student.
// Input the data for a student and display it.

#include <iostream>
using namespace std;

class Student{
    string name;
    int roll;
    float total_marks;

    public:
        void GetData(){
            cout << "Enter details of student:\n";
            cout << "Name - ";
            getline(cin >> ws, name);
            cout << "Roll - ";
            cin >> roll;
            cout << "Total Marks - ";
            cin >> total_marks;
        }

        void DisplayDetails(){
            cout << "\nName is: "<< name;
            cout << "\nRoll is: "<< roll;
            cout << "\nTotal marks is: "<< total_marks;
        }
};

int main(){
    Student s;
    s.GetData();
    s.DisplayDetails();
    return 0;
}
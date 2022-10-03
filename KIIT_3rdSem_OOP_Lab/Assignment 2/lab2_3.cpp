// KIIT OOP LAB Question 2-3
// Modify the program (q2-2) to store marks in 5 subjects. Calculate the total
// marks and percentage of a student and display it.

#include <iostream>
using namespace std;

class Student{
    string name;
    int roll;
    float marks[5]; // to store marks in 5 subjects

    public:
        void GetData(){
            cout << "Enter details of student:\n";
            cout << "Name - ";
            getline(cin >> ws, name);
            cout << "Roll - ";
            cin >> roll;
            cout << "Enter marks in 5 subjects (Out of 100) -\n";
            for (int i=0; i<5; i++){
                cin >> marks[i];
            }
        }

        void DisplayDetails(){
            cout << "\nName is: "<< name;
            cout << "\nRoll is: "<< roll;
            cout << "\nTotal marks is: ";
            float sum=0;
            for (int i=0; i<5; i++){
                sum+=marks[i];
            }
            cout <<sum;
            cout << "\nPercentage is " << sum/5;
        }
};

int main(){
    Student s;
    s.GetData();
    s.DisplayDetails();
    return 0;
}
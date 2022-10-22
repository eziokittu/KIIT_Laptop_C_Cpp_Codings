// OOPs LAB Assignment 6 -
// Q2) Create a class student which stores name, roll number and age
// of a student. Derive a class test from student class, which stores
// marks in 5 subjects. Input and display the details of a student

#include <iostream>
using namespace std;

class Student{
    public:
        string name;
        int roll;
        int age;
        void GetStudentInfo(){
            cout <<"\nEnter name : ";
            getline (cin>>ws, name);
            cout <<"Enter roll : ";
            cin >> roll;
            cout <<"Enter age : ";
            cin >> age;
        }
};

class Test: public Student{
    float marks[5];
    public: 
        void GetMarks(){
            cout <<"\nEnter marks for 5 subjects (0-100) -\n";
            for (int i=0; i<5; i++){
                cin >> marks[i];
            }
        }
        void ShowAllDetails(){
            cout <<"\nThe student - '"<<name<<"', Age-"<<age<<"years, of Roll-"<<roll<<", ";
            cout <<"has marks for 5 subjects as - ";
            for (int i=0; i<5; i++) cout<<marks[i]<<" ";
        }
};

int main(){
    Test student1;
    student1.GetStudentInfo();
    student1.GetMarks();
    student1.ShowAllDetails();

    return 0;
}
// OOPs LAB Assignment - 7
// Q7) Extend the program ii. of inheritance to include a class 
// sports, which stores the marks in sports activity. Derive the 
// result class from the classes ‘test’ and ‘sports’. Create
// objects using parameterized constructors .Calculate the total
// marks and percentage of a student.

// Assignment 6 - Q2) Create a class student which stores name,
// roll number and age of a student. Derive a class test from 
// student class, which stores marks in 5 subjects. Input and 
// display the details of a student.

#include <iostream>
using namespace std;

class Student{
    public:
        string name;
        int roll;
        int age;
        Student(){
            cout << "\n--- Enter Student Details ---\n";
            cout <<"Enter name : ";
            getline (cin>>ws, name);
            cout <<"Enter roll : ";
            cin >> roll;
            cout <<"Enter age : ";
            cin >> age;
        }
};

class Test: public Student{
    public: 
        float marks[5];
        Test(){
            cout <<"\nEnter marks for 5 subjects (0-100) -\n";
            for (int i=0; i<5; i++){
                cin >> marks[i];
            }
        }
};

class Sports{
    public:
        float mark;
        Sports(){
            cout <<"\nEnter marks for sports subject (0-100) -\n";
            cin >> mark;
        }
};

class Result: public Test, public Sports{
    float s=0;
    public:
        Result(){
            for (int i=0; i<5; i++){
                s+=marks[i];
            }
            s+= mark;
            cout << "\nTotal Sum = "<<s<<" out of 600.";
            cout << "\nPercentage = "<<s/6<<"%";
        }
};

int main(){
    Result r;

    return 0;
}
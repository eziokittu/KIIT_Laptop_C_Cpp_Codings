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
        }
};

class Test: public Student{
    public: 
        float marks[5];
        Test(){
        }
};

class Sports{
    public:
        float mark;
        Sports(){
            
        }
};

class Result: public Test, public Sports{
    float s=0;
    public:
        Result(string _name, int _roll, int _age, float _marks[], float _mark){
            name = _name;
            age = _age;
            roll = _roll;
            for (int i=0; i<5; i++) marks[i] = _marks[i];
            mark = _mark;

            for (int i=0; i<5; i++){
                s+=marks[i];
            }
            s+= mark;
            cout << "\nStudent '"<<name<<"' of roll-"<<roll<<", and age-"<<age<<"has result ----";
            cout << "\nTotal Sum = "<<s<<" out of 600.";
            cout << "\nPercentage = "<<s/6<<"%";
        }
};

int main(){
    float marks_arr[5] = {98, 76.5, 87, 98.5, 94};
    Result ("One Sided Lover", 22057025, 20, marks_arr, 75);

    return 0;
}
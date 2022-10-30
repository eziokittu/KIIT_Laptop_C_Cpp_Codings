// OOPs LAB Assignment 6 -
// Q3) Expend thr program in (Q2) to derive a class from result from 
// class test which includes member function to calculate total marks
// and percentage of a student. Input the data for a student and
// display it's total marks and percentage

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
    public: 
        float marks[5];
        void GetMarks(){
            cout <<"\nEnter marks for 5 subjects (0-100) -\n";
            for (int i=0; i<5; i++){
                cin >> marks[i];
            }
        }
        void ShowMarks(){
            cout <<"\nThe student - '"<<name<<"', Age-"<<age<<"years, of Roll-"<<roll<<", ";
            cout <<"has marks for 5 subjects as - ";
            for (int i=0; i<5; i++) cout<<marks[i]<<" ";
        }
};

class Result: public Test{
    public:
        float t;
        float p;
        void Calculate(){
            float sum=0;
            for (int i=0; i<5; i++){
                sum += marks[i];
            }
            t = sum;
            p = sum/5;
        }
        void ShowTotalAndPercentage(){
            cout <<"\nTotal = "<<t<<" out of 500"<<", Percentage = "<<p<<"%";
        }
};

int main(){
    Result student1;
    student1.GetStudentInfo();
    student1.GetMarks();
    student1.ShowMarks();
    student1.Calculate();
    student1.ShowTotalAndPercentage();

    return 0;
}
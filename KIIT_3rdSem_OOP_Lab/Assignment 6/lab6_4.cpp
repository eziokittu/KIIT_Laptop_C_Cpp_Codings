// OOPs LAB Assignment 6 -
// Q4) Expend the program in (Q2) to include a class sports which stores
// the marks in sports activity. Derive the result class from the classes
// test and sport. Calculate and display total marks and percentage.

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

class Sports: public Student{
    public: 
        float mark;
        void GetMark(){
            cout <<"\nEnter marks sports subject (0-100) - ";
            cin >> mark;
        }
        void ShowMark(){
            cout <<"\nMarks in sports = "<<mark;
        }
};

class Result: public Test, public Sports{
    float t;
    float p;
    public:
        void Calculate(){
            float sum=0;
            for (int i=0; i<0; i++){
                sum += marks[i];
            }
            sum += mark;
            t += sum;
            p = sum/6;
        }
        void ShowTotalAndPercentage(){
            cout <<"\nTotal = "<<t<<"out of 600"<<", Percentage = "<<p<<"%";
        }
};

int main(){
    Result student1;
    student1.Test::GetStudentInfo();
    student1.GetMarks();
    student1.GetMark();
    student1.ShowMarks();
    student1.ShowMark();
    student1.Calculate();
    student1.ShowTotalAndPercentage();

    return 0;
}
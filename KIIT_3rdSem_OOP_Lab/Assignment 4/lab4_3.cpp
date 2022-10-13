// OOP LAB Assignment 4
// Q3) Create a class with an integer data member. Include functions
// for input and output in class. Count the number of times each
// fucntion is called and display it.

#include <iostream>
using namespace std;

class A{
    private:
        int num;

        // static member variable
        static int count;

    public:

        void Input(){
            cout <<"Enter data: "; cin>>num;
            IncrementCount();
        }
        void Output(){
            cout <<"The number is: "<<num;
            IncrementCount();
        }
        // static member variable
        static void IncrementCount(){ 
            count++;
        }
        // static member variable
        static void ShowCount(){
            cout << "\nCount = "<< count << endl;
        }
};

// defining outside class is necessary
int A::count; // default value is 0

int main(){
    A a;
    A::ShowCount();
    a.Input();
    A::ShowCount();
    a.Output();
    A::ShowCount();

    A b;
    A::ShowCount();
    b.Input();
    A::ShowCount();
    b.Output();
    A::ShowCount();

    return 0;
}
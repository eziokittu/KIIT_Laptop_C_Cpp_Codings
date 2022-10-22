// OOPs LAB Assignment 5
// Q4) WAP to demonstrate the order of call of constructors and
// destructors for a class

#include <iostream>
using namespace std;

class A{
    public:
        A(){
            cout <<"\nDefault constructor called.";
        }
        A(string a){
            cout <<"\nParameterised constructor called. Hello "<<a;
        }
        ~A(){
            cout <<"\nDestructor called.";
        }
};

void func(){
    cout <<"\n---Entered func body.";
    A a3;
    cout <<"\n---Exiting func body.";
}
// object a3 destroyes after exit from function to main

int main(){
    // program starts from here 
    cout << "\n----------Inside main function.";
    A a1;
    func();
    A a2("Harry");
    cout << "\n----------Exiting main function.";
}
// a1 and a2 gets destroyed after main ends
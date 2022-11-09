// OOPs LAB Assignment 7
// Q1) WAP to demonstrate the order of call of constructors and
// destructors in case of multiple inheritance.

#include <iostream>
using namespace std;

// first base class
class Parent1
{  
    public:  
        Parent1()
        {
            cout << "Parent 1 class constructor" << endl;
        }
        ~Parent1(){
            cout << "Parent 1 class destructor" << endl;
        }
};
 
// second base class
class Parent2
{
    public:  
        Parent2()
        {
            cout << "Parent 2 class constructor" << endl;
        }
        ~Parent2(){
            cout << "Parent 2 class destructor" << endl;
        }
};
 
// child class inherits Parent1 and Parent2
class Child : public Parent1, public Parent2
{
    public:  
        Child()
        {
            cout << "Child class constructor" << endl;
        }
        ~Child(){
            cout << "Child class destructor" << endl;
        }
};
 
int main() {
    cout << "--- Example of Multiple Inheritance ---\n";
    Child obj1;
    return 0;
}
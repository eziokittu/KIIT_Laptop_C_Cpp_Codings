// OOPs LAB Assignment 7
// Q2) WAP to demonstrate the order of call of constructors and
// destructors in case of multilevel inheritance

#include <iostream>
using namespace std;

// first base class
class Parent1{  
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
class Child1: public Parent1{
    public:  
        Child1()
        {
            cout << "Child 1 class constructor" << endl;
        }
        ~Child1(){
            cout << "Child 1 class destructor" << endl;
        }
};


class GrandChild1 : public Child1{
    public:  
        GrandChild1()
        {
            cout << "GrandChild 1 class constructor" << endl;
        }
        ~GrandChild1(){
            cout << "GrandChild 1 class destructor" << endl;
        }
};
 
int main() {
    cout << "--- Example of Multi-level Inheritance ---\n";
    GrandChild1 obj1;
    return 0;
}
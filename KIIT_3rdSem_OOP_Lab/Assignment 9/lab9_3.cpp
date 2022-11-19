// OOPs LAB Assignment 9
// Q3) WAP to demonstrate use of pure virtual function and abstract base class.

#include <iostream>
using namespace std;

class Base{ // abstract base class
    public:
        void func1(){ // normal member function
            cout << "\nHello Base function 1";
        }
        virtual void func2(){ // virtual member function
            cout << "\nHi Base function 2";
        }
        virtual void func3()=0; // pure virtual function
};
// Since base class has a pure virtal function
// it is also known as abstract class

class Derived : public Base{
    public:
        void func1(){ // gets overloaded by func1() of base class
            cout << "\nHello Derived function 1";
        }
        void func2(){ // derived func2() overrides base class func2()
            cout << "\nHi Derived function 2";
        }
        void func3(){
            // func3() inside child class must be defined, otherwise 
            // compiler gives errors
            cout << "\nHola Derived function 3";
        }
};

int main(){
    Base *b;
    Derived d;
    b = &d;
    b->func1();
    b->func2();
    b->func3();
    return 0;
}
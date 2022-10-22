// OOPs LAB Assignment 5
// Q5) WAP to count number of objects created from a class using concept
// of static data member and static member functions

#include <iostream>
using namespace std;

class A{
    static int count;
    public:
        A(){
            cout <<"\nNo Name!";
            count++;
        }
        A(string name){
            cout <<"\nHello "<<name;
            count++;
        }
        ~A(){
            cout <<"\nObject Destroyed";
            count--;
        }
        static void ShowCount(){
            cout <<" Count : "<<count;
        }
};

int A::count;

void func(){
    cout <<"\n---Entered func body.";A::ShowCount();
    A a3;
    cout <<"\n---Exiting func body.";A::ShowCount();
}

int main(){
    // program starts from here 
    cout << "\n----------Inside main function.";A::ShowCount();
    A a1;
    func();
    A a2("Harry");
    cout << "\n----------Exiting main function.";A::ShowCount();
}
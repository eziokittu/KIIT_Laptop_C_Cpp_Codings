// OOP LAB Assignment 4
// Q1) WAP to swap private data member of two classes
// [The classes have no relation with each other]

#include <iostream>
using namespace std;

class A;
class B;

// Defining 2 classes
class A{
    private:
        int data_A;
    public:
        void SetData(){
            cout << "\nEnter data for A obj: "; cin>>data_A;
        }
        void GetData(){
            cout << "\nData in A: "; cout<<data_A;
        }
        friend void Access_AB(A &a, B &b);
};
class B{
    private:
        int data_B;
    public:
        void SetData(){
            cout << "\nEnter data for B obj: "; cin>>data_B;
        }
        void GetData(){
            cout << "\nData in B: "; cout<<data_B;
        }
        friend void Access_AB(A &a, B &b);
};

// Defining the friend functions of both classes;
void Access_AB(A &a, B &b){
    int temp = a.data_A;
    a.data_A = b.data_B;
    b.data_B = temp;
}

int main()  
{  
    A a;  
    B b;  
    a.SetData();  
    b.SetData();  
    Access_AB(a,b); 
    a.GetData();  
    b.GetData();  
    return 0;  
}  
// OOPs LAB Assignment 7
// Q2) WAP to demonstrate the order of call of constructors and
// destructors in case of multilevel inheritance

// C++ program to implement
// multilevel inheritance
#include<iostream>
using namespace std;

// Base class A
class A{
	public:
    int a1=
		A(){
			int a = 5, b = 6, c;
			c = a + b;
			cout << "Sum is: " <<c << endl;
		}
};

// Class B
class B: public A{
	public:
		B(){
			int d = 50,e = 35, f;
			f = d - e;
			cout << "Difference is:" <<f << endl;
		}
};

// Derived class C
class C: public B
{
	public:
		C()
		{
			int g = 10, h = 20, i;
			i = g * h;
			cout << "Product is:" <<i << endl;			
		}
};

// Driver code
int main()
{
	C obj;
	return 0;
}

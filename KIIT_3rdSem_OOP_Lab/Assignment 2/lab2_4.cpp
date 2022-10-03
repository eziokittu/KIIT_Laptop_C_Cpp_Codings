// KIIT OOP LAB - Question 2-4
// Create a class complex which stores real and imaginary part
// of a complex number. Input 10 complex numbers and display it.

#include <iostream>
using namespace std;

class Complex{
    float real;
    float imaginary;

    public:
        void GetComplexNumber(){
            cout << "\nEnter real part : ";
            cin >> real;
            cout << "\nEnter imaginary part : ";
            cin >> imaginary;
        }
        void Display(){
            if (imaginary > 0)
                cout << "The complex number is "<< real << " + " << imaginary << "i";
            else
                cout << "The complex number is "<< real << " - " << -imaginary << "i";
        }
};

int main(){
    Complex c;
    c.GetComplexNumber();
    c.Display();
}

// OOPs LAB Assignment 5
// Q1) Create a class complex which stores real and imaginary part of a complex
// number. Include all types of constructors and destructor. The destructor
// should display a message about the destructor being invoked. Create objects
// using different contructors and display them

#include <iostream>
using namespace std;

class Complex{
    float real;
    float imag;
    static int count;
    public:
        // Default Constructor
        Complex (){
            real = 1;
            imag = 1;
            AddCount();
        }

        // Parameterised Contructors
        Complex (float i){
            real = 0;
            imag = i;
            AddCount();
        }
        Complex (float r, float i){
            real = r;
            imag = i;
            AddCount();
        }

        // Copy Constructors
        Complex (const Complex &c){
            real = c.real;
            imag = c.imag;
            AddCount();
        }

        // Destructor
        ~Complex(){
            Complex::count--;
            cout <<"\nThe destructer is invoked. Count = "<<Complex::ShowCount();
        }

        static void AddCount(){
            count++;
        }

        static int ShowCount(){
            return count;
        }

        void Display(){
            cout <<"\nComplex no. : ";
            cout<<real;
            if (imag>=0) cout<<" + "<<imag<<"i";
            else cout<<" - "<<-imag;
        }
};

int Complex::count;

int main(){
    Complex c1;
    Complex c2(5);
    Complex c3(-7,56);
    Complex c4(-19, -99);
    Complex c5(c4);

    // Displaying
    c1.Display();
    c2.Display();
    c3.Display();
    c4.Display();
    c5.Display();
}
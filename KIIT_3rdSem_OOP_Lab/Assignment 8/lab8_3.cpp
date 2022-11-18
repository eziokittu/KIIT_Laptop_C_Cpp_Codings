// OOPs LAB Assignment 8
// Q3)  Create a class of a complex number. Add two objects and 
// display the resultant object. Overload the ++ (post and pre)
// operator for the class

#include <iostream>
using namespace std;

class Complex{
    private:
        float real;
        float imag;
    public:
        Complex(){
            real = 0;
            imag = 0;
        }
        Complex(float r, float i){
            real = r;
            imag = i;
        }
        void GetData(){
            cout << "\n---- Enter data for complex no. ----";
            cout << "\nReal: ";
            cin >> real;
            cout << "Imag: ";
            cin >> imag;
        }
        Complex operator+(Complex& c){
            return (Complex){this->real+c.real, this->imag+c.imag};
        }
        Complex operator++(int a){ // Post Increment
            return (Complex){this->real++, this->imag++};
        }
        Complex operator++(){ // Pre Increment
            return (Complex){++this->real, ++this->imag};
        }
        void Display(){
            cout <<"\nComplex no. : ";
            cout<<real;
            if (imag>=0) cout<<" + "<<imag<<"i";
            else cout<<" - "<<-imag<<"i";
        }
};

int main(){

    Complex c1;
    c1.GetData();
    c1.Display();

    Complex c2;
    c2.GetData();
    c2.Display();

    Complex c3 = c1 + c2;
    c3.Display();
    
    Complex c4 = c3++;
    c4.Display();
    c4 = ++c3;
    c4.Display();

    return 0;
}
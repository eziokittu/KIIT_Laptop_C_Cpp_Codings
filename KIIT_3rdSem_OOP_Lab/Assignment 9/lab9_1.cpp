// OOPs LAB Assignment 9
// Q1) Create a class shape. Derive three classes from it;
// Circle, Square and Triangle. Find area of each shape
// and display it, using virtual function. (User IP)

#include <iostream>
#include <math.h>
using namespace std;

class Shape{
    public:
        float area = 10;
        void ShowArea(){
            cout << "\nArea = "<<area;
        }
        virtual void CalculateArea(){
            area = area*10;
        }
};

class Circle: public Shape {
    public:
        float r; 
        Circle (){
            cout << "---- Circle ----\nEnter radius: ";
            cin >> r;
        }
        void CalculateArea(){
            area = r*r * 3.141;
        }
};

class Triangle: public Shape {
    public:
        float a,b,c;
        Triangle (){
            cout << "---- Triangle ----\nEnter sides: ";
            cin >> a >> b >> c;
        }
        void CalculateArea(){
            float s = a+b+c;
            area = (sqrt(s * (s-a) * (s-b) * (s-c)));
        }
};

class Square: public Shape {
    public:
        float a;
        Square(){
            cout << "---- Square ----\nEnter side: ";
            cin >> a;
        }
        void CalculateArea(){
            area = a*a;
        }
};

int main(){
    Square rect;
    Triangle tri;
    Circle circ;

    Shape *s;
    
    cout << "\n---- Rectangle ----";
    s = &rect;
    s->CalculateArea();
    s->ShowArea();

    cout << "\n---- Triangle ----";
    s = &tri;
    s->CalculateArea();
    s->ShowArea();

    cout << "\n---- Circle ----";
    s = &circ;
    s->CalculateArea();
    s->ShowArea();

    return 0;
}
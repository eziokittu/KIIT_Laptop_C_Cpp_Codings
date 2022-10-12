// Assignment: 3, Due data: 14th October 2022
// Q1) WAP to find area of a circle, a rectangle and a triangle,
// using concepts of function overloading

#include <iostream>
#include <math.h>
using namespace std;

// Area of Circle
float Area(float r){ return (3.141*r*r);}

// Area of Rectangle
float Area(float l, float w){ return (l*w);}

// Area of Triangle using semiperimeter
float Area(float a, float b, float c){
    float s = (a+b+c)/2;
    return (sqrt(s * (s-a) * (s-b) * (s-c)));
}

int main(){
    float r, l,w, a,b,c;
    cout << "Enter radius: "; cin>>r;
    cout << "Area of triangle = "<<Area(r);

    cout << "\nEnter length and width "; cin>>l>>w;
    cout << "Area of Rectangle = "<<Area(l,w);
    
    cout << "\nEnter 3 sides of triangle: "; cin>>a>>b>>c;
    cout << "Area of triangle = "<<Area(a,b,c);

    return 0;
}
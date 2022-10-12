// Assignment - 3
// Q2) WAP to find the volume of a sphere, a cylinder and a cuboid,
// using function overloading.

#include <iostream>
using namespace std;

#define pi 3.141

// Volume of a Sphere
float Volume (float r){ 
    return ((4/3) * pi * (r*r*r));
}

// Volume of a Cylinder
float Volume (float r, float h){
    return (pi * (r*r) * h);
}

// Volume of Cuboid
float Volume (float a, float b, float c){
    return (a * b * c);
}

int main(){
    float r, h, a, b, c;
    cout << "\nEnter radius for Sphere:\n"; cin>>r;
    cout << "Volume of Sphere = "<<Volume(r);
    cout << "\nEnter radius and height for Cylinder:\n"; cin>>r>>h;
    cout << "Volume of Cylinder = "<<Volume(r,h);
    cout << "\nEnter 3 sides of Cuboid:\n"; cin>>a>>b>>c;
    cout << "Volume of Cuboid = "<<Volume(a,b,c);

    return 0;
}
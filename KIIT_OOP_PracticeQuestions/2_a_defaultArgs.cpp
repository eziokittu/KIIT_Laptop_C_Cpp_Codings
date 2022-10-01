#include <iostream>
using namespace std;

#define pi 3.141

// Volume of Cube
int Volume(int s){
    return (s*s*s);
}

// Volume of Sphere
float Volume(float r){
    return ((4/3) * pi * (r*r*r));
}

// Volume of Cylinder
float Volume(float h, float r){
    return(pi * (r*r) * h);
}

int main(){
    cout << "Volume of Cube of side 5 = " << Volume(5);
    cout << "Volume of Cylinder of height as 7, radius as 7 = " << Volume(7,7);
    cout << "Volume of Sphere of radius 10 = " << Volume(7.3);
}
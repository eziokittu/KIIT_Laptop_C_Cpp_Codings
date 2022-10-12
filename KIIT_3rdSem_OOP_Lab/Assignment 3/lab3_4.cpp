// Assignment - 3
// Q4) WAP to find square and cube of a number using inline function

#include <iostream>
using namespace std;

inline float Square(int n){ return (n*n);}
inline float Cube(int n){ return (n*n*n);}

int main(){
    int n;
    cout << "Enter a number : ";
    cin>>n;
    cout << "Square of "<<n<<" is "<<Square(n);
    cout << "\nCube of "<<n<<" is "<<Cube(n);
    
    return 0;
}
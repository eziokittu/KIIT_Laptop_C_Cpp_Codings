// Assignment - 3
// Q5) WAP to swap two integers using pass by reference

#include <iostream>
using namespace std;

void Swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main(){
    int a, b;
    cout << "Enter 1st number: "; cin >> a;
    cout << "Enter 2nd number: "; cin >> b;

    Swap(&a, &b);
    cout << "After swapping using pass by reference - ";
    cout << "\n1st number is "<<a;
    cout << "\n2nd number is "<<b;

    return 0;
}
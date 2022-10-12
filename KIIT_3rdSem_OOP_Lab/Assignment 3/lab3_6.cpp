// Assignment - 3
// Q6) WAP to increment the value of an arguement given to a function

#include <iostream>
using namespace std;

void increment(int *n){
    ++*n;
}

int main(){
    int n;
    cout << "Enter a number : ";
    cin >> n;
    increment(&n);
    cout << "After increment, no. is : "<<n;

    return 0;
}
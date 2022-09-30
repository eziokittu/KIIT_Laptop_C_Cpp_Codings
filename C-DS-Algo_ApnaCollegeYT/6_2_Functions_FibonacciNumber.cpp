#include <iostream>
#include <cmath>
using namespace std;

void FibonnaciNumberAt(int n){

    // using recursion
    // if (n==1) return 0;
    // else if (n==2) return 1;
    // else {
    //     return ( FibonnaciNumberAt(n-1) + FibonnaciNumberAt(n-2) );
    // }

    // normal way
    int t1 = 0;
    int t2 = 1;
    int t3;
    for (int i=1; i<=n; i++){
        cout << t1;
        t3 = t1+t2;
        t1 = t2;
        t2 = t3;
    }
    // return t3;

}

int main(){
    int n;
    cout << "Enter nth number : ";
    cin >> n;
    // cout << n <<"th Fibonacci number is : " << FibonnaciNumberAt(n);
    FibonnaciNumberAt(n);
}
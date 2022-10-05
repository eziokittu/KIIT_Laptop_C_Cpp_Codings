#include<iostream>
#include<limits>
using namespace std;

int Reverse_Integer(int m){
    long n = m;

    // if number is negative
    bool isNegative = false;
    if (n<0){
        n*=-1;
        isNegative = true;
    }

    // reversing the number
    long rev=0;
    while (n>0){
        rev = (rev*10) + (n%10);
        n = n/10;
        if (rev*10 < rev) return 0;
    }

    // returning
    if (rev<INT32_MIN || rev>INT32_MAX) return 0;
    else{
        if (isNegative) return -rev;
        else return rev;
    }
}

int main(){
    cout << Reverse_Integer(54) << endl;
    cout << Reverse_Integer(-879) << endl;
    cout << Reverse_Integer(100) << endl;
    cout << Reverse_Integer(50010) << endl;
    cout << Reverse_Integer(1234567890) << endl;
    cout << Reverse_Integer(1234567809) << endl;
    cout << Reverse_Integer(-2147483648) << endl;
    
    return 0;
}
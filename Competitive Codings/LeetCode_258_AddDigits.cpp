// LeetCode Problem 258 - Add Digits
// https://leetcode.com/problems/add-digits/

#include <iostream>
using namespace std;

int addDigits(int n) {
    int sum=0;
    while (n>0){
        sum += n%10;
        n /= 10;
    }
    if (sum > 9) return addDigits(sum);
    return sum;
}

int main(){
    cout << addDigits(45) << " ";
    cout << addDigits(38) << " ";
    cout << addDigits(1) << " ";

    return 0;
}
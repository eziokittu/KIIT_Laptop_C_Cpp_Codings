// Leetcode Problem 319 - Bulb Switcher
// https://leetcode.com/problems/bulb-switcher/

#include <iostream>
using namespace std;

// brute force
int findNoOfFactors(int n){
    int count=1; // the number is divisible by itself so +1
    for (int i=1; i<=n/2; i++){
        if (n%i==0){
            count++;
        }
    }
    return count;
}

int bulbSwitch(int n) {
    if (n<2) return n;
    int c=0;
    for (int i=1; i<n; i++){
        if (findNoOfFactors(i)%2==1){
            c++;
        }
    }
    return c;
}

int main() {
    int n = 10;
    cout << bulbSwitch(n);
}
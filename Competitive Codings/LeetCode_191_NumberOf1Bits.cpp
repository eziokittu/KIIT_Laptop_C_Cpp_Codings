// LeetCode Problem 191 - Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/

#include <iostream>
#include <vector>

using namespace std;

int getLSB(uint32_t &n){
    int a = (1 & n);
    n=n/10;
    return a;
}

int hammingWeight(uint32_t n) {
    unsigned int count=0;
    while (n>0){
        int a = getLSB(n);
        if (a==1){
            count++;
        }
    }
    return count;
}

int main(){
    uint32_t n = 1111100001;
    cout << hammingWeight(n);
    return 0;
}
// LeetCode Problem 9 - Palindrome Number
// https://leetcode.com/problems/palindrome-number/

#include <iostream>
using namespace std;

bool isPalindrome(int m) {
    long rev=0, n=m;
    while (n>0){
        rev = (rev*10) + (n%10);
        n/=10;
    }
    if (rev==m) return true;
    else return false;
} 

int main(){
    cout << "\n1334331 is Palindrome? - "<<isPalindrome(1334331);
    cout << "\n6789009876 is Palindrome? - "<<isPalindrome(6789009876);
    cout << "\n1234565656 is Palindrome? - "<<isPalindrome(1234565656);
}
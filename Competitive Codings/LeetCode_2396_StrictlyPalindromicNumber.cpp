// LeetCode Problem - 2396 - Strictly Palindromic Number
// https://leetcode.com/problems/strictly-palindromic-number/

#include <iostream>

using namespace std;

string ConvertDecimalToBase(int num, int base){
    string s = "";
    while (num>0){
        int quotient = num/base;
        int rem = num - base*quotient;
        if (rem<10){
            s=(char)(rem+'0')+s;
        }
        else{
            s=(char)(rem-10+'A')+s;
        }
        num = quotient;
    }
    return s;
}

bool checkPalindrome(string s){
    string temp="";
    int l=0;
    for (int i=0; s[i]!='\0'; i++)
        l++;
    for (int i=l-1; i>=0; i--){
        temp+=s[i];
    }
    for (int i=0; i<l; i++){
        if (s[i]!=temp[i]){
            return false;
        }
    }
    return true;
}

bool isStrictlyPalindromic(int n) {
    for (int i=2; i<n-1; i++){
        if (checkPalindrome(ConvertDecimalToBase(n, i))==false){
            return false;
        }
    }
    return true;
}

int main(){
    cout << "Strictly Palindromic? -";
    cout << "\n9 - "<<isStrictlyPalindromic(9);
    cout << "\n4 - "<<isStrictlyPalindromic(9);
    cout << "\n255 - "<<isStrictlyPalindromic(9);
    cout << "\n1000 - "<<isStrictlyPalindromic(9);
    cout << "\n123 - "<<isStrictlyPalindromic(9);
}
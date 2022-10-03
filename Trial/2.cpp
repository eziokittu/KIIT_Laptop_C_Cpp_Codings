// Leetcode problem 14 - Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.

#include<iostream>
#include<vector>
using namespace std;

int romanToInt(string s){
    int sum=0;
    for (int i=0; i<s.length(); i++){

        if (s[i]=='I'){
            if (s[i+1]!='\0'){
                if (s[i+1]=='V') {
                    sum += 4;
                    i+=1;
                }
                else if (s[i+1]=='X') {
                    sum += 9;
                    i+=1;
                }
            }
            else {
                sum += 1;
            }
        }

        else if (s[i]=='X'){
            if (s[i+1]!='\0'){
                if (s[i+1]=='L') {
                    sum += 40;
                    i+=1;
                }
                else if (s[i+1]=='C') {
                    sum += 90;
                    i+=1;
                }
            }
            else {
                sum += 10;
            }
        }

        else if (s[i]=='C'){
            if (s[i+1]!='\0'){
                if (s[i+1]=='D') {
                    sum += 400;
                    i+=1;
                }
                else if (s[i+1]=='M') {
                    sum += 900;
                    i+=1;
                }
            }
            else {
                sum += 100;
            }
        }

        else if (s[i]=='V') sum += 5;
        else if (s[i]=='L') sum += 50;
        else if (s[i]=='D') sum += 500;
        else if (s[i]=='M') sum += 1000;
    }
    return sum;
}

int main(){
    cout << endl << romanToInt("M");
    cout << endl << romanToInt("IV");
    cout << endl << romanToInt("XVII");
    cout << endl << romanToInt("M");
    cout << endl << romanToInt("M");
    return 0;
}
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
        //cout << "\nSum = " << sum << "s["<<i<<"] = "<<s[i] << endl;
        if (s[i]=='I'){
            sum += 1;
            if (s[i+1]!='\0'){
                if (s[i+1]=='V') {
                    sum += 3;
                    i+=1;
                }
                else if (s[i+1]=='X') {
                    sum += 8;
                    i+=1;
                }
            }
        }

        else if (s[i]=='X'){
            sum += 10;
            if (s[i+1]!='\0'){
                if (s[i+1]=='L') {
                    sum += 30;
                    i+=1;
                }
                else if (s[i+1]=='C') {
                    sum += 80;
                    i+=1;
                }
            }
        }

        else if (s[i]=='C'){
            sum += 100;
            if (s[i+1]!='\0'){ 
                if (s[i+1]=='D') {
                    sum += 300;
                    i+=1;
                }
                else if (s[i+1]=='M') {
                    sum += 800;
                    i+=1;
                }
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
    //cout << endl << romanToInt("M");
    cout << endl << romanToInt("IV");
    cout << endl << romanToInt("XVII");
    //cout << endl << romanToInt("M");
    //cout << endl << romanToInt("M");
    return 0;
}
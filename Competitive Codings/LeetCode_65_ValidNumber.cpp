// LeetCode Problem 65 - Valid Number
// https://leetcode.com/problems/valid-number/

#include <iostream>
using namespace std;

bool isNumber(string s) {
    int state = 0;
    // states
    // 0 = not started
    // 1 = + or -
    // 2 = number before dot
    // 3 = .
    // 4 = number after dot
    // 5 = e
    // 6 = + or -
    // 7 = number
    // 
    // NOTE 1: there must be a number after . / e / + / -
    for (char c : s){

        // getting the value
        int n = c-'0';

        // if a number
        if (n>=0 && n<=9){
            if (state==0 || state==1 || state==2){
                state = 2;
            }
            else if (state==3 || state==4){
                state = 4;
            }
            else if (state==5 || state==6 || state==7){
                state = 7;
            }
            else {
                return false;
            }
            continue;
        }

        // if a '.'
        else if (c=='.'){
            if (state==0 || state==1){
                state=3;
            }
            else if (state==2){ // special case : '5.' is possible
                state=4;
            }
            else{
                return false;
            }
            continue;
        }

        // if a '+' or '-'
        else if (c=='+' || c=='-'){
            if (state==0 || state==5){
                state+=1;
            }
            else{
                return false;
            }
            continue;
        }

        // for 'e'
        else if (c=='e' || c=='E'){
            if (state==2 || state==4){
                state = 5;
            }
            else{
                return false;
            }
            continue;
        }

        // other characters
        else{
            return false;
        }
    }
    if (state == 1 || state == 3 || state == 5 || state == 6){
        return false;
    }
    return true;
}

int main(){
    string s = "12.76e-4";
    cout << isNumber(s);
    return 0;
}
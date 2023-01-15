// LeetCode Problem 69 - Fraction To Recurring Decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal/

#include <iostream>
#include <string>
using namespace std;

string fractionToDecimal(int n, int d) {
    string t="", s = "";
    s = to_string(double(n)/double(d));

    // adding bracres if repeating
    bool start = false;
    int increment = 1;
    for (int i=0; i <s.length(); i++){
        if (s[i] == '.') start = true;
        t += s[i];
        if (start){
            while (increment != 4){
                for (int j=i; j<s.length()-1; j+increment){
                    if (s[j] == s[j+1]){

                    }
                }
            }
        }
    }

    // remove the trailing zeroes
    for (int i=s.length()-1; i>0; i--){
        if (s[i]=='0' || s[i]=='.') s.pop_back();
        else break;
    }

    return s;
}

int main(){
    cout << fractionToDecimal(22, 4);
    return 0;
}